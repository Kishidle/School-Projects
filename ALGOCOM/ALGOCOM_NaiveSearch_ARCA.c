#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	int select;
	char fromText[64];
	char input[64] = "";
	char pattern[64];
	char result[64] = "";
	int i = 0;
	int j = 0;
	int temp = 0;
	int shift = -1;
	int patternFlag = 0;
	int flag = 0;
	printf("Select method of searching: \n");
	printf("[1] With string functions \n");
	printf("[2] Without string functions \n");
	
	scanf("%d", &select);
	
	FILE *fp;
	
	fp = fopen("input.txt", "r");
	if(fp != NULL){
		
		while(fgets(fromText, sizeof(fromText), fp) != NULL){
		
			//find text and pattern from line acquired
			for(i = 0; i < strlen(fromText); i++){
				
				if(fromText[i] != '.'){
					
					if(flag) strncat(pattern, &fromText[i], 1);
					
					else strncat(input, &fromText[i], 1);
				}
				else if(fromText[i] == '.'){
					
					flag = 1;
				}
			}
			
			if(select == 1){
				
				//find all occurences of substring pattern in input
				//iterate per index, "cut" the string then compare the string with pattern
				for(i = 0; i < strlen(input); i++){
					
					for(j = i; j < strlen(pattern); j++){
						
						strncat(result, &input[j], 1);
					}
					if(strcmp(input, pattern) == 0) printf("Shift at %d", i);
					memset(input, 0, sizeof(input));
				}
				
				
				
			}
			else if(select == 2){
		
				for(i = 0; i < strlen(input); i++){
					
					for(j = 0; j < strlen(pattern); j++){
						
						if(input[i + j] == pattern[j]){
							flag = 1;
						}
						else{
							flag = 0;
							break;
						}
					}
					if(flag){			
						printf("Shift at %d", i);
						shift = 1;
					}
					
				}
				
				if(shift == -1){ //can i not use patternFlag?
					printf("Invalid shift\n");
				}
				//use for loops to compare characters from the text and the pattern
			}
			
			
			//reset values
			flag = 0;
			shift = -1;
		}
	
	}
}
