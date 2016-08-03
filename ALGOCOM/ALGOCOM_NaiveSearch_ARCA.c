#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//this program uses the naive search algorithm to find a matching pattern within a string
int main(int argc, char *argv[]){
	
	int select = 0;
	select = atoi(argv[1]);
	char fromText[130];
	char input[130] = "";
	char pattern[130] = "";
	char result[130] = "";
	int i = 0;
	int j = 0;
	int textLength = 0;
	int patternLength = 0;
	int temp = 0;
	int shift = -1;
	int patternFlag = 0;
	int flag = 0;
	printf("Select method of searching: \n");
	printf("[1] With string functions \n");
	printf("[2] Without string functions \n");
	int n = 1;
	//scanf("%d", &select);
	//printf("%d\n", select);
	//printf("%s \n", argv[2]);
	select = 2;
	FILE *fp;
	fp = fopen("inputall.txt", "r");
	if(fp != NULL){
			
		while(fgets(fromText, sizeof(fromText), fp) != NULL){
		
			int length = strlen(fromText);
			//printf("\n%d\n", length);
			if(fromText[length - 1] == '\n') fromText[length - 1] = '\0';
			printf("\nString %d: \n", n);
			printf("\n%s\n", fromText);
			//find text and pattern from line acquired
			for(i = 0; i < length; i++){
				
				if(fromText[i] != '.'){
					
					if(flag){
					
						strncat(pattern, &fromText[i], 1);	
					} 
					
					else strncat(input, &fromText[i], 1);
				}
				else if(fromText[i] == '.'){
					flag = 1;
				}
			}
		
			
			flag = 0;
			if(select == 1){
				
				
				//find all occurences of substring pattern in input
				//iterate per index, "cut" the string then compare the string with pattern
				for(i = 0; i < strlen(input); i++){
					
					for(j = 0; j < strlen(pattern); j++){
						
						strncat(result, &input[i + j], 1);
					}
					
					if(strcmp(result, pattern) == 0){
				
						printf("Pattern occurs with shift %d\n", i);
						shift = 1;
					} 
					memset(result, 0, sizeof(result));
					
				}
				if(shift == -1) printf("Invalid shift\n");
				
				
			}
			else if(select == 2){
			
				//find all occurence of substring pattern in input
				//compares per character instead of using string
				while(input[textLength] != '\0')
					textLength++;
				
				while(pattern[patternLength] != '\0') 
					patternLength++;
				
				for(i = 0; i < textLength; i++){
					
					for(j = 0; j < patternLength; j++){
						
						if(input[i + j] == pattern[j])
							flag = 1;

						else{	
							flag = 0;
							break;
						}
					}
					
					if(flag){			
						printf("Pattern occurs with shift %d\n", i);
						shift = 1;
					}
					
				}
				
				if(shift == -1)
					printf("Invalid shift\n");
				
				
			}
			//reset values for the next line
			memset(input, 0, sizeof(input));
			memset(pattern, 0, sizeof(pattern));
			textLength = 0;
			patternLength = 0;
			flag = 0;
			shift = -1;
			n++;
		}
	
	}
	fclose(fp);
	return 0;
}
