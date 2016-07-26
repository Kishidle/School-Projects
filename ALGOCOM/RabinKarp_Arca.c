#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//converts char to integer value
int convertCI(char c){
	return c - '0';
}


int main(int argc, char *argv[]){
	
	char fromText[128] = "";
	char input[128] = "";
	char pattern[128] = "";
	int i, j;
	int q = 13;
	int patternLength = 0;
	int flag = 0;
	int rkArr[64] = { 0 };
	FILE *fpread, fpwrite;
	int patternq = 0;
	fpread = fopen("input(4).txt", "r");
	//fpwrite = fopen("output.txt", "w");
	int n = 0;
	int x =0;
	int shift = -1;
	if(fpread != NULL){
		
		while(fgets(fromText, sizeof(fromText), fpread) != NULL){
			
			int length = strlen(fromText);
			printf("d\n\n%d", x);
			if(fromText[length - 1] == '\n') 
				fromText[length - 1] = '\0';
			
			printf("%s\n", fromText);
			//get text and pattern
			
			for(i = 0; i < length; i++){
				
				if(fromText[i] != '.'){
					
					if(flag){
						
						//patternLength++; //decide whether to use this one or put it in an array instead
						strncat(pattern, &fromText[i], 1);
						patternq = patternq + (int)fromText[i];
						
					}
					
					else{
						strncat(input, &fromText[i], 1);
						//kArr[i] = convertCI(fromText[i]);
						
						
					}
					
				
					 
				}
				
				
				else if(fromText[i] == '.')
					flag = 1;
				
			}
			
			patternq = patternq % q;
			flag = 0;
			// do we just add the ascii values or are we supposed to concatenate the integers together?
			for(i = 0; i < strlen(input); i++){
				
				if(strlen(input) - i < strlen(pattern)){
					//printf("\n%d", i);
					break;
				}
					
				for(j = 0; j < strlen(pattern); j++){
					
					rkArr[i] = rkArr[i] + (int)input[i + j];
					//printf("%d %d\n", j, (int)input[i+j]);
				}
				//printf("\n");
				rkArr[i] = rkArr[i] % q;
				
				//printf("mod: %d \n", rkArr[i]);
				//printf("pattern: %d \n", patternq);
				++n;
				
			}
			
			for(i = 0; i < n; ++i){
				
				if(rkArr[i] == patternq){
					
					
					for(j = 0; j < strlen(pattern); ++j){
						
						printf("%d", i);
						
						if(input[i + j] == pattern[j]){
						
							flag = 1;
						}
						else{
							flag = 0;
							if(x == 73){
							printf("helloagain");
							}
							break;
						}
						
					}
					if(x == 73){
						printf("testerino");
					}
					//check the string?
				}
			
				if(flag){
					if(x == 73){
							printf("flagerino");
						}
					flag = 0;
					printf("Pattern occurs with shift %d\n\n", i);
					shift = 1;
				}
				
			}
			printf("test");
			if(shift == -1){
				printf("Invalid shift\n\n");
			}
			
			memset(input, 0, sizeof(input));
			memset(pattern, 0, sizeof(pattern));
			flag = 0;
			shift = -1;
			patternq = 0;
			memset(rkArr, 0, sizeof(rkArr));
			x++;
		}
	}
	
	
	
	
	return 0;
}
