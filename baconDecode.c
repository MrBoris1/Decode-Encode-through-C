#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "baconCode.h"

int main(int argc,char **argv) {
	char line;
	FILE *fp = fopen("test_encode.txt","r+");

	int cap = 1;
	int count = 0;
	char lst[5] = {};
	int bina[5]={};
	int totalbit=0;
	while((line = getc(fp)) != EOF){
		if(line == '\0'){break;}
		if(line == ' '){continue;}
		if(count == 5){
			int size = sizeof(lst)/sizeof(lst[0]);
			const char * foundPtr;
			const char * foundPtr2;
			for(int i = 0; i<size; i++){
				foundPtr = strchr(vowels,lst[i]);
				foundPtr2 = strchr(consonants,lst[i]);
				if(foundPtr){
					bina[i] = 0;
				}
				else if (foundPtr2)
				{
					bina[i] = 1;
				}
			}
			size = sizeof(bina)/sizeof(bina[0]);
			double result;
			for(int i = 0; i<size; i++){
				if(bina[i]==1){
					if (i == 0){ result = 2*2*2*2;}
					else if (i == 1){ result = 2*2*2;}
					else if (i == 2){ result = 2*2;}
					else if (i == 3){ result = 2;}
					else{result=1;}	
					totalbit = totalbit + result;
				}	
			}
			if (cap == 1){ cap = 0; putc(toupper(alfa[totalbit]),stdout);}
			else{putc(alfa[totalbit],stdout);} //puts the final decoded string value
			totalbit = 0;
			count = 0;
		}
		if(line == '\n'){ cap = 1; putc(line,stdout); continue;}
		lst[count]=line;
		count++;
	}
	fclose(fp);
	return 0;
}