#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//converts char to integer value
int convertCI(char c){
	return c - '0';
}


int main(int argc, char *argv[]){
	
	char fromText[128];
	char input[128];
	char pattern[128];
	int q, i;
	int flag = 0;
	int rkArr[128] = { 0 };
	FILE *fpread, fpwrite;
	int patternq = 0;
	fpread = fopen("input.txt", "r");
	fpwrite = fopen("output.txt", "w");
	
	if(fpread != NULL){
		
		while(fgets(fromText, sizeof(fromText), fpread) != NULL){
			
			int length = strlen(fromText);
			
			if(fromText[length - 1] == '\n') 
				fromText[length - 1] = '\0'
			
			//get text and pattern
			
			for(i = 0; i < length; i++){
				
				if(fromText[i] != '.'){
					
					if(flag){
						patternq = patternq + convertCI(fromText[i]);
					}
					
					else rkArr[i] = convertCI(fromText[i]);
				}
				
				
				else if(fromText[i] == '.')
					flag = 1;
				
				
				
			}
			//convert text into int
			
			
			
		}
	}
	
	
	
	
	return 0;
}
