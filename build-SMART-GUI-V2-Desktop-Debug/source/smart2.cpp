
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "smart.c"

using namespace std;

int main(){

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

//run_setting((char*)SETTING_BUFFER[sett], tkey, T, n, alpha, FREQ, VOLTE, occ, dif, expcode, tshmid, txt, tex, php, "", std, limit);
		


return 0;
}
