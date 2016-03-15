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
 * contact the authors at: faro@dmi.unict.it and thierry.lecroq@univ-rouen.fr
 * download the tool at: http://www.dmi.unict.it/~faro/smart/
 */


#define XSIZE       4200			//maximal length of the pattern
#define SIGMA       256				//constant alphabet size
#define MG			(1024*1024)		//costant for 1 MB size
#define NumAlgo     500 			//maximal number of algorithms
#define NumPatt     17				//maximal number of pattern lengths
#define NumSetting	15				//number of text buffers
#define MAXTIME		999.00

/* DEFINITION OF VARIABLES */
unsigned int MINLEN = 0, MAXLEN = 4200; //min length and max length of pattern size


#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <sys/stat.h>
#include "timer.h"
#include "sets.h"
#include "output.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


void printManual() {
	int i=system("./logo");
	printf("\tThis is an help guide for using the tool\n\n");
	//printf("\t-alpha S      sets to S the size of the alphabet (default 256)\n");
	printf("\t-pset N       computes running times as the mean of N runs (default 500)\n");
	printf("\t-tsize S      set the upper bound dimension (in Mb) of the text used for experimental results (default 1Mb)\n");
	printf("\t-plen L U     test only patterns with a length between L and U (included).\n");
	printf("\t-text F       performs experimental results using text buffer F (mandatory unless you use the -simple parameter)\n");
	printf("\t-short        computes experimental results using short length patterns\n");
	printf("\t-occ          prints the number of occurrences\n");
	printf("\t-tb L         set to L the upper bound for any wort case running time (in ms). The default value is 300 ms\n");
	printf("\t-dif          prints the number the best and the worst running time\n");
	printf("\t-std          prints the standard deviations of the running times\n");
	printf("\t-txt          output results in txt tabular format\n");
	printf("\t-tex          output results in latex tabular format\n");
	printf("\t-simple P T   executes a single run searching T (max 1000 chars) for occurrences of P (max 100 chars)\n");
	printf("\t-h            gives this help list\n");
	printf("\n\n");
}

void printTopEdge(int len){
	int i;
	fprintf(stdout,"\t");
	for(i=0; i<len; i++) fprintf(stdout,"%c",'_');
	fprintf(stdout,"\n");
}

int getAlpha(char *filename) {
	int i=0;
	while(i<NumSetting && strcmp(SETTING_BUFFER[i],filename)) i++;
	if(i==NumSetting) {
		printf("\tError in loading alphabet size\n");
		return 0;
	}
	else return SETTING_ALPHA_SIZE[i];
}

void generateCode(char *code) {
	int t = (int)time(NULL);
	sprintf(code,"EXP%d",t);
}

int getText(char *T, char *path, int FREQ[SIGMA], int TSIZE) {
	//obtains the input text
	int j,i = 0;
	char indexfilename[100];
	strcpy(indexfilename, path);
	strcat(indexfilename, "/index.txt");
	FILE *index;
	if(index = fopen(indexfilename, "r")) {
		char c;
		while( i<TSIZE && (c=getc(index))!=EOF ) {
			if(c=='#') {
				char filename[100];
				strcpy(filename, path);
				j=strlen(filename);
				filename[j++]='/';
				while( (c=getc(index))!='#' ) filename[j++]=c;
				filename[j]='\0';
				printf("\tLoading the file %s\n",filename);
				FILE *input;
				if( input = fopen(filename, "r") )  {
					char d;
					while(i<TSIZE && (d=getc(input))!=EOF ) T[i++]=d;
					fclose(input);
				}
				else printf("\tError in loading text file %s\n",filename);
			}
		}
		fclose(index);
	}
	else printf("\tError in loading text buffer. No index file exists.\n");
	T[i]='\0';
	// compute the frequency of characters and the dimension of the alphabet
	int nalpha = 0;
	int maxcode= 0;
	for(j=0; j<SIGMA; j++) FREQ[j]=0;
	for(j=0; j<i; j++) {
		if(FREQ[T[j]]==0) nalpha++;
		FREQ[T[j]]++;
		if(maxcode<T[j]) maxcode=T[j];
	}
	printf("\tAlphabet of %d characters.\n", nalpha);
	printf("\tGreater chararacter has code %d.\n", maxcode);
	return i;
}

int execute(int algo, key_t pkey, int m, key_t tkey, int n, key_t rkey, key_t ekey, int *count, int alpha) {
	char command[100];
	sprintf(command, "./source/bin/%s shared %d %d %d %d %d %d",str2lower(ALGO_NAME[algo]),pkey,m,tkey,n,rkey,ekey);
    int res = system(command);
	if(!res) return (*count);
	else return -1;
}

void setOfRandomPatterns(char **setP, int m, char *T, int n, int numpatt, unsigned char* simplePattern) {
	int i,j,k;
	for(i=0; i<numpatt; i++)  {
		if(strcmp(simplePattern,"")) strcpy(setP[i],simplePattern);
		else {
			k = random() % (n-m); //generates a number between 0 and n-m
			for(j=0; j<m; j++) setP[i][j]=T[k+j]; //creates the pattern
			setP[i][j]='\0'; 
		}
	}
}



/********************************************************/
int run_setting(char *filename, key_t tkey, unsigned char* T, int n, 
				int alpha, int *FREQ, int VOLTE, int occ, int dif, char *code, int tshmid, int txt, int tex, int php,
				unsigned char* simplePattern, int std, int limit) {
   //performs experiments on a text
   int    m, i, j, k, il, algo, occur, total_occur, try;
   double TIME[NumAlgo][NumPatt], BEST[NumAlgo][NumPatt], WORST[NumAlgo][NumPatt], STD[NumAlgo][NumPatt], STDTIME[5000];
   char **setP = (char **) malloc (sizeof(char*)*VOLTE);
   for(i=0; i<VOLTE; i++) setP[i] = (char*) malloc (sizeof(char)*(XSIZE+1));
   unsigned char   c, *P;
   FILE *fp, *ip, *stream;
   int SIMPLE = (strcmp(simplePattern,"")?1:0);
   if(!SIMPLE) {
      char logfile[100];
      sprintf(logfile,"results/%s",code);
      mkdir(logfile,0775);
      strcat(logfile,"/errorlog.txt");
      stream = freopen (logfile,"w",stderr);  //redirect of stderr
   }

	//allocate space for running time in shered memory
	srand( time(NULL) );
	double *time;
	int eshmid;
	key_t ekey = rand()%1000;
	try = 0;
	do {
		ekey = rand()%1000; 
		eshmid = shmget(ekey, 8, IPC_CREAT | 0666); 
	} while((++try<10 && eshmid<0) || ekey==tkey);
	if (eshmid < 0) {
		perror("shmget"); 
		shmctl(tshmid, IPC_RMID,0);
		exit(1);
	}
	if ((time = shmat(eshmid, NULL, 0)) == (double *) -1) {
		perror("shmat"); 
		shmctl(tshmid, IPC_RMID,0);
		shmctl(eshmid, IPC_RMID,0);
		exit(1);
	}

	//allocate space for pattern in shered memory
   int pshmid;
   key_t pkey = rand()%1000;
   try = 0;
   do {
		pkey = rand()%1000; 
		pshmid = shmget(pkey, XSIZE+1, IPC_CREAT | 0666); 
   } while((++try<10 && pshmid<0) || pkey==tkey || pkey==ekey);
   if (pshmid < 0) {
       perror("shmget"); 
  	   shmctl(tshmid, IPC_RMID,0);
  	   shmctl(eshmid, IPC_RMID,0);
	   exit(1);
   }
   if ((P = shmat(pshmid, NULL, 0)) == (unsigned char *) -1) {
       perror("shmat"); 
	   shmctl(tshmid, IPC_RMID,0);
	   shmctl(pshmid, IPC_RMID,0);
  	   shmctl(eshmid, IPC_RMID,0);
	   exit(1);
   }
   for(i=0; i<SIGMA; i++) FREQ[i] = 0;

   //allocate space for the result number of occurrences in shared memory
   int *count;
   int rshmid;
   key_t rkey = rand()%1000;
   try = 0;
   do  {
		rkey = rand()%1000; 
		rshmid = shmget(rkey, 4, IPC_CREAT | 0666); 
   } while((++try<10 && rshmid<0) || rkey==tkey || rkey==pkey || pkey==ekey);
   if (rshmid < 0) {
       perror("shmget"); 
	   shmctl(tshmid, IPC_RMID,0);
  	   shmctl(eshmid, IPC_RMID,0);
	   shmctl(pshmid, IPC_RMID,0);
	   exit(1);
   }
   if ((count = shmat(rshmid, NULL, 0)) == (int *) -1) {
       perror("shmat"); 
	   shmctl(tshmid, IPC_RMID,0);
	   shmctl(pshmid, IPC_RMID,0);
  	   shmctl(eshmid, IPC_RMID,0);
	   shmctl(rshmid, IPC_RMID,0);
	   exit(1);
   }

   //initializes the vector which will contain running times
	for(i=0; i<NumAlgo; i++) for(j=0; j<NumPatt; j++) {
		TIME[i][j] = WORST[i][j] = STD[i][j] = 0;
		BEST[i][j] = MAXTIME;
	}

   //count how many algorithms are going to run
   int num_running = 0;
   for(i=0; i<NumAlgo; i++) if(EXECUTE[i]) num_running ++;

   i=system("./logo");
   for(il=0; PATT_SIZE[il]>0; il++) if(PATT_SIZE[il]>=MINLEN && PATT_SIZE[il]<=MAXLEN)
   {
      m = PATT_SIZE[il];
	  setOfRandomPatterns(setP, m, T, n, VOLTE, simplePattern);
      printf("\n");
  	  printTopEdge(60);
      if(!SIMPLE) printf("\tExperimental results on %s\n",filename);
	  else printf("\tExperimental results on %s\n",T);
	  printf("\tSearching for a set of %d patterns with length %d\n", VOLTE, m);
      printf("\tTesting %d algorithms\n", num_running);
      printf("\n");

	  int current_running = 0;
      for(algo=0; algo<NumAlgo; algo++)
	  if(EXECUTE[algo]) {
		current_running++;
		char data[30];
      	sprintf(data,"\t - [%d/%d] %s ",current_running,num_running,str2upper(ALGO_NAME[algo]));
		printf("%s",data);fflush(stdout);
		for(i=0; i<35-strlen(data); i++) printf(".");
		total_occur = 0;
				  
		for(k=1; k<=VOLTE; k++) {
	   		for(j=0; j<m; j++) P[j]=setP[k-1][j]; P[j]='\0'; //creates the pattern
			int perc = (int)((100*k)/VOLTE);
			if(perc<10) printf("\b\b\b\b[%d%%]", perc);
			else if(perc<100) printf("\b\b\b\b\b[%d%%]", perc);
			else printf("\b\b\b\b[%d%%]", perc);
			fflush(stdout);

        	occur = execute(algo,pkey,m,tkey,n,rkey,ekey,count,alpha);

			STDTIME[k] = (*time);
			TIME[algo][il] += (*time);
			if (BEST[algo][il]>(*time)) BEST[algo][il] = (*time);
			if (WORST[algo][il]<(*time)) WORST[algo][il] = (*time);
			total_occur += occur;
			if(occur<=0 && (!SIMPLE))  {
				//timer_stop(_timer);
				TIME[algo][il]=0;
				total_occur = occur;
				break;
	      	}
			if((*time)>limit)  {
				//timer_stop(_timer);
				TIME[algo][il]=0;
				total_occur = -2;
				break;
	      	}
			
      	}
		
		TIME[algo][il] /= (double)VOLTE;
		for(k=1; k<=VOLTE; k++) STD[algo][il] += pow(STDTIME[k]-TIME[algo][il],2.0);
		STD[algo][il] /= (double)VOLTE;
		STD[algo][il] = sqrt(STD[algo][il]);
		  
		if(total_occur>0 || (total_occur>=0 && SIMPLE)) {
			int nchar = 15;
			if(dif) nchar += 20;
			if(std) nchar += 15;
			int i;
   			printf("\b\b\b\b\b\b\b.[OK]  ");
			sprintf(data,"\t\%.2f ms",TIME[algo][il]);
			printf("%s",data);
			for(i=0; i<15-strlen(data); i++) printf(" ");
			if(dif) {
				sprintf(data," [%.2f, %.2f]", BEST[algo][il], WORST[algo][il]);
				printf("%s",data);
				for(i=0; i<20-strlen(data); i++) printf(" ");
			}
			if(std) {
				sprintf(data," std %.2f", STD[algo][il]);
				printf("%s",data);
				for(i=0; i<15-strlen(data); i++) printf(" ");
			}
			if(occ) printf("\t\%d",total_occur/VOLTE);
			printf("\n");
		}
		else if(total_occur==0) printf("\b\b\b\b\b\b\b\b.[ERROR] \n");
		else if(total_occur==-1) printf("\b\b\b\b\b.[--]  \n");
		else if(total_occur==-2) printf("\b\b\b\b\b\b.[OUT]  \n");
      }
   }

   printf("\n");
   printTopEdge(60);
   if(!SIMPLE) {
	   fclose(stream);
	   printf("\tOUTPUT RUNNING TIMES %s\n", code);
	   if(txt) outputTXT(TIME, alpha, filename, code);
	   outputXML(TIME, alpha, filename, code);
	   outputHTML(TIME, alpha, filename, code);
	   if(tex) outputLatex(TIME, alpha, filename, code);
	   if(php) outputPHP(TIME, BEST, WORST, STD, alpha, filename, code, dif, std);
   }
   //free shared memory
   shmctl(pshmid, IPC_RMID,0);
   shmctl(rshmid, IPC_RMID,0);
   return 0;
} 

/**************************************************/
int FREQ[SIGMA];				//frequency of alphabet characters

int main(int argc, const char *argv[])
{
	//mandatory parameters
   	char *filename = (char*) malloc (sizeof(char) * (100));
	//non mandatory parameters
	PATT_SIZE = PATT_LARGE_SIZE;	//the set of pattern legths
	int alpha = 256;				//size of the alphabet
	int VOLTE = 500;				//number of runs for each pattern length
	int TSIZE = 1048576;
	int SIMPLE = 0;                 //set to 1 if we run a single search with custom pattern and text
	int occ = 0;					//set to 1 for printing number of occurrences
	int dif = 0;					//set to 1 for printing the best and the worst running time
	int txt = 0;					//set to 1 for printing results in txt format
	int tex = 0;					//set to 1 for printing results in latex format
	int php = 0;					//set to 1 for printing results in php format
	int std = 0;					//set to 1 for printing the standard deviation value
	int limit = 300;				//set to 300 running time bound
   	char *simplePattern = (char*) malloc (sizeof(char) * (100)); //used for the simple run of SMART
   	char *simpleText = (char*) malloc (sizeof(char) * (1000));    //used for the simple run of SMART
	/* useful variables */
   	unsigned char *T	;			//text and pattern
	int n, tshmid,try;							//length of the text
   	FILE *ip;						//file pointer for input text
   	char parameter[1000]; 
	char c;

    srand( time(NULL) );

	/* processing of input parameters */
	if (argc==1) {printf("No parameter given. Use -h for help.\n\n"); return 0;}
	if (!strcmp("-h", argv[1])) {printManual(); return 0;}
	int par = 1;
	while(par<argc) {
		if (par<argc && !strcmp("-pset", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
			if(!isInt(parameter)) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			VOLTE = string2decimal(parameter);
		}
		if (par<argc && !strcmp("-tsize", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
			if(!isInt(parameter)) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			TSIZE = string2decimal(parameter); TSIZE *= MG;
		}
		if (par<argc && !strcmp("-tb", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
			if(!isInt(parameter)) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			limit = string2decimal(parameter);
		}
		if (par<argc && !strcmp("-text", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
		   	strcat(filename, parameter);
		}
		if (par<argc && !strcmp("-plen", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
			MINLEN = string2decimal(parameter);;
			if(MINLEN<1 || MINLEN>4200) {printf("Error in input parameters. The minimum length is not a valid argument.\n\n"); return 0;}
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
			MAXLEN = string2decimal(parameter);;
			if(MAXLEN<1 || MINLEN>MAXLEN) {printf("Error in input parameters. The maximum length is not a valid argument.\n\n"); return 0;}
		}
		if (par<argc && !strcmp("-simple", argv[par])) {
			par++;
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
		   	strcpy(simplePattern, parameter);
			if(strlen(simplePattern)>100) {printf("Error in input parameters. Max 100 chars for P parameter.\n\n"); return 0;}
			if(par>=argc) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
			strcpy(parameter, argv[par++]);
		   	strcpy(simpleText, parameter);
			if(strlen(simpleText)>1000) {printf("Error in input parameters. Max 1000 chars for T parameter.\n\n"); return 0;}
			SIMPLE=1;
		}
		if (par<argc && !strcmp("-occ", argv[par])) {
			par++;
			occ = 1;
		}
		if (par<argc && !strcmp("-dif", argv[par])) {
			par++;
			dif = 1;
		}
		if (par<argc && !strcmp("-txt", argv[par])) {
			par++;
			txt = 1;
		}
		if (par<argc && !strcmp("-std", argv[par])) {
			par++;
			std = 1;
		}
		if (par<argc && !strcmp("-tex", argv[par])) {
			par++;
			tex = 1;
		}
		if (par<argc && !strcmp("-php", argv[par])) {
			par++;
			php = 1;
		}
		if (par<argc && !strcmp("-short", argv[par])) {
			par++;
			PATT_SIZE = PATT_SHORT_SIZE;
		}
		if (par<argc && !strcmp("-veryshort", argv[par])) {
			par++;
			PATT_SIZE = PATT_VERY_SHORT;
		}
		if (par<argc && strcmp("-text", argv[par])!=0 
						&& strcmp("-alpha", argv[par])!=0 
						&& strcmp("-tsize", argv[par])!=0 
						&& strcmp("-plen", argv[par])!=0 
						&& strcmp("-occ", argv[par])!=0 
						&& strcmp("-dif", argv[par])!=0 
						&& strcmp("-txt", argv[par])!=0 
						&& strcmp("-tb", argv[par])!=0 
						&& strcmp("-simple", argv[par])!=0 
						&& strcmp("-tex", argv[par])!=0 
			            && strcmp("-std", argv[par])!=0 
						&& strcmp("-php", argv[par])!=0 
						&& strcmp("-pset", argv[par])!=0
						&& strcmp("-veryshort", argv[par])!=0
						&& strcmp("-short", argv[par])!=0) {printf("Error in input parameters. Use -h for help.\n\n"); return 0;}
	
	}
	if(strcmp(filename,"") && SIMPLE) {printf("Error in input parameters. Both parameters -simple and -text defined.\n\n"); return 0;}
	if(!strcmp(filename,"") && !SIMPLE) {printf("Error in input parameters. No filename given.\n\n"); return 0;}
    
	//get information about the set of algorithms
	getAlgo(ALGO_NAME,EXECUTE);

   	//allocate space for text in shered memory
    key_t tkey = rand()%1000;
	size_t size = sizeof(unsigned char) * TSIZE+10;
    try = 0;
    do  {
		tkey = rand()%1000;
		tshmid = shmget(tkey, TSIZE+10, IPC_CREAT | 0666); 
 	} while(++try<10 && tshmid<0);
    if (tshmid < 0) {
        perror("shmget"); exit(1);
    }
    if ((T = shmat(tshmid, NULL, 0)) == (unsigned char *) -1) {
		printf("\nShared memory allocation failed!\nYou need at least 12Mb of shared memory\nPlease, change your system settings and try again.\n");
        perror("shmat"); 
		shmctl(tshmid, IPC_RMID,0);
		exit(1);
    }

	if( SIMPLE ) {  
		//experimental results on a single pattern and a single text
   		n = strlen(simpleText);
   		int m = strlen(simplePattern);
		strcpy(T,simpleText);
		alpha = 250;
		PATT_CUSTOM_SIZE[0] = m;
		PATT_CUSTOM_SIZE[1] = 0;
		PATT_SIZE = PATT_CUSTOM_SIZE;
		//if ( !(alpha = getAlpha(filename)) ) return 0;
   		printf("\n\tText of %d chars : %s\n", n,T);
   		printf("\tPattern of %d chars : %s\n", m,simplePattern);
		srand(time(NULL));
		char expcode[100];
		generateCode(expcode);
   		printf("\tStarting experimental tests with code %s\n",expcode);
   		run_setting("", tkey, T, n, alpha, FREQ, VOLTE, occ, dif, expcode, tshmid, txt, tex, php, simplePattern, std, limit);
		//no output is given for the simple case;
	}
	else if( strcmp(filename, "all") ) {  
		//experimental results on a single corpus
   		printf("\n\tTry to process archive %s\n", filename);
		char fullpath[100];
		strcpy(fullpath,"data/");
		strcat(fullpath, filename);
		//initialize the frequency vector
   		if( !(n = getText(T,fullpath,FREQ,TSIZE) ) ) {
			shmctl(tshmid, IPC_RMID,0);
			return 0;
		}
		if ( !(alpha = getAlpha(filename)) ) {
			shmctl(tshmid, IPC_RMID,0);
			return 0;
		}
   		printf("\tText buffer of dimension %d byte\n", n);
		srand(time(NULL));
		char expcode[100];
		generateCode(expcode);
   		printf("\tStarting experimental tests with code %s\n",expcode);
   		run_setting(filename, tkey, T, n, alpha, FREQ, VOLTE, occ, dif, expcode, tshmid, txt, tex, php, "", std, limit);
		outputINDEX(filename,expcode);
	}
	else {  
		//starts experimental results on all texts
		srand(time(NULL));
		char expcode[100];
		generateCode(expcode);
		int sett;
		for(sett=0; sett<NumSetting; sett++) {
			char fullpath[100];
			strcpy(fullpath,"data/");
			strcat(fullpath, SETTING_BUFFER[sett]);
   			alpha = SETTING_ALPHA_SIZE[sett];
   			printf("\n\tTry to process archive %s\n", SETTING_BUFFER[sett]);
			//initialize the frequency vector
   			if( !(n = getText(T,fullpath,FREQ,TSIZE) ) ) {
				shmctl(tshmid, IPC_RMID,0);
				return 0;
			}
   			printf("\tText buffer of dimension %d byte\n", n);
   			printf("\tStarting experimental tests with code %s\n",expcode);
    		run_setting((char*)SETTING_BUFFER[sett], tkey, T, n, alpha, FREQ, VOLTE, occ, dif, expcode, tshmid, txt, tex, php, "", std, limit);
		}
		outputINDEX(filename,expcode);
	}

	//free shared memory
	shmctl(tshmid, IPC_RMID,0);

   	return 0;
}

