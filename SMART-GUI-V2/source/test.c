/*
 * SMART: string matching algorithms research tool.
 * Copyright (C) 2012  Simone Faro and Thierry Lecroq
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * 
 * contact the authors at: faro@dmi.unict.it, thierry.lecroq@univ-rouen.fr
 * download the tool at: http://www.dmi.unict.it/~faro/smart/
 *
 * file test.c
 * this program is used for testing correctness of algorithms
 * test the algorithm on different conditions and
 * check the number of occurrences reported
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIGMA 256
#define XSIZE 100
#define YSIZE 1000
#define VERBOSE !strcmp(parameter,"-nv")

int search(char *x, int m, char *y, int n) {
   int i, count, j;

   /* Searching */
   count = 0;
   for (j = 0; j <= n - m; ++j) {
      for (i = 0; i < m && x[i] == y[i + j]; ++i);
      if (i >= m)
         count++;
   }
   return count;
}

void printManual() {
	printf("\n\tSMART UTILITY FOR TESTING STRING MATCHING ALGORITHMS\n\n");
	printf("\tusage: ./test ALGONAME\n");
	printf("\tTest the program named \"algoname\" for correctness.\n");
	printf("\tThe program \"algoname\" must be located in source/bin/\n");
	printf("\tOnly programs in smart format can be tested.\n");
	printf("\n\n");
}

int execute(char *algoname, key_t pkey, int m, key_t tkey, int n, key_t rkey, int *count, int alpha) {
	char command[100];
	sprintf(command, "./source/bin/%s shared %d %d %d %d %d",algoname,pkey,m,tkey,n,rkey);
	//printf("%s\n",command);
    int res = system(command);
	if(!res) return (*count);
	else return -1;
}

int FREQ[SIGMA];

int main(int argc, char *argv[]) {
	int i, j;
	unsigned char *T,*P;
	
	/* processing of input parameters */
	if (argc==1) {printManual(); return 0;}
	char algoname[100];
	strcpy(algoname,argv[1]);
	char parameter[100];
	if(argc>2) strcpy(parameter,argv[2]);
	char filename[100] = "source/bin/";
	strcat(filename,algoname);
	FILE *fp = fopen(filename, "r");
	if( !fp ) {
		if(!VERBOSE) printf("\n\tERROR: unable to execute program %s\n\n",filename);
		exit(1);
	}
	fclose(fp);
	
   	//allocate space for text in shered memory
   	srand( time(NULL) );
   	int tshmid;
   	key_t tkey = rand()%1000;
    int try = 0;
    do  {
		tkey = rand()%1000;
		tshmid = shmget(tkey, YSIZE+1, IPC_CREAT | 0666); 
 	} while(++try<10 && tshmid<0);
    if (tshmid < 0) {
        perror("shmget"); 
		exit(1);
    }
   	if ((T = shmat(tshmid, NULL, 0)) == (unsigned char *) -1) {
   	    perror("shmat"); 
		shmctl(tshmid, IPC_RMID,0);
		exit(1);
   	}

   	//allocate space for pattern in shered memory
   	srand( time(NULL) );
   	int pshmid;
   	key_t pkey = rand()%1000;
    try = 0;
    do  {
		pkey = rand()%1000;
		pshmid = shmget(pkey, XSIZE+1, IPC_CREAT | 0666); 
 	} while(++try<10 && pshmid<0);
    if (pshmid < 0) {
        perror("shmget"); 
		shmctl(tshmid, IPC_RMID,0);
		exit(1);
    }
   	if ((P = shmat(pshmid, NULL, 0)) == (unsigned char *) -1) {
   	    perror("shmat"); 
	   	shmctl(tshmid, IPC_RMID,0);
	   	shmctl(pshmid, IPC_RMID,0);
		exit(1);
   	}

   	//allocate space for the result number of occurrences in shared memory
   	int *count;
   	int rshmid;
   	key_t rkey = rand()%1000;
    try = 0;
    do  {
		rkey = rand()%1000;
		rshmid = shmget(rkey, 4, IPC_CREAT | 0666); 
 	} while(++try<10 && rshmid<0);
    if (rshmid < 0) {
        perror("shmget"); 
		shmctl(tshmid, IPC_RMID,0);
		shmctl(pshmid, IPC_RMID,0);
		exit(1);
    }
   	if ((count = shmat(rshmid, NULL, 0)) == (int *) -1) {
   	    perror("shmat"); 
   		shmctl(tshmid, IPC_RMID,0);
   		shmctl(pshmid, IPC_RMID,0);
   		shmctl(rshmid, IPC_RMID,0);
		exit(1);
   	}

	if(!VERBOSE) printf("\n\tPlease, wait a moment..............");
	fflush(stdout);

	//begin testing
	int rip = 0;
	int alpha, k, h, m, occur1, occur2, test=1;
	for(alpha = 2; alpha<=128; alpha*=2) {
		for(i=0; i<YSIZE; i++) T[i] = rand()%alpha;
		// compute the frequency of characters
		for(j=0; j<SIGMA; j++) FREQ[j]=0;
		for(j=0; j<YSIZE; j++) FREQ[T[j]]++;
		for(m = 2; m<=64; m*=2) {
			for(j=0; j<10; j++) {
				rip++;
				printf("\b\b\b\b\b\b[%.3d%%]",rip*10/42,m); fflush(stdout);
				(*count) = 0;
				k = j*2;
				for(h=0; h<m; h++) P[h] = T[k+h];
				P[m]='\0';
				occur1 = search(P,m,T,YSIZE);
	        	occur2 = execute(algoname,pkey,m,tkey,YSIZE,rkey,count,alpha);
				if(occur2>=0 && occur1 != occur2) {
					if(!VERBOSE) printf("\n\t%d - %d\n\tERROR: test failed\n\n",occur1, occur2);
				   	shmctl(tshmid, IPC_RMID,0);
				   	shmctl(pshmid, IPC_RMID,0);
				   	shmctl(rshmid, IPC_RMID,0);
					exit(1);
				}
			}
		}
	}
	if(!VERBOSE) printf("\n\tWell done! Test passed successfully\n\n");
		

   	//free shared memory
   	shmctl(tshmid, IPC_RMID,0);
   	shmctl(pshmid, IPC_RMID,0);
   	shmctl(rshmid, IPC_RMID,0);
	return 0;
}

