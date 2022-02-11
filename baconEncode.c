#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "baconCode.h"

int main(int argc, char **argv) {
	char line;
	FILE *fp = fopen("test.txt","r+");

	int a[5];
	int n =31;
	srand(time(0));
	int spc = 1+rand()%8;
	while((line = getc(fp)) != EOF){
		 // Use the current time as the seed for random generator
		if(line == '\0'){break;}
		if(line == '\n'){putc(line,stdout); continue;}
		const char * foundPtr=strchr(alfa,tolower(line));
		if(!foundPtr){foundPtr = &(alfa[strlen(alfa)-1]);}
		int index = (int)(foundPtr-alfa);//conver to binnary
		int i;
		for(i=0;n>0;i++){
			a[i]=index%2;
			index = index/2;
			n=n/2;
		}
		n =31;
		for(i=i-1;i>=0;i--){
			if(a[i] == 0 ){putc(vowels[rand()%strlen(vowels)],stdout);}
			else if (a[i] == 1){putc(consonants[rand()%strlen(consonants)],stdout);}
			if(spc == 0){ putc(' ',stdout); spc =  1+rand()%8;}else{spc--;}
		}
	}
	fclose(fp);
	return 0;
}
