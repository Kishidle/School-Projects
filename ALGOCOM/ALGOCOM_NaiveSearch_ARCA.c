#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	int select;
	char fromText[64];
	char input[64];
	char pattern[64];
	int i = 0;
	int flag = 0;
	printf("Select method of searching: \n");
	printf("[1] With string functions \n");
	printf("[2] Without string functions \n");
	
	scanf("%d", &select);
	
	FILE *fp;
	
	fp = fopen("input.txt");
	if(fp != NULL){
		
		while(fgets(fromText, sizeof(fromText), fp) != NULL){
		
			//find text and pattern from line acquired
			for(i = 0; i < strlen(fromText); i++){
				
				if(fromText[i] != '.'){
					
					if(flag) strcat(pattern, fromText[i]);
					
					else strcat(input, fromText[i]);
				}
				else{
					i++;
					flag = 1;
				}
			}
			
			if(select == 1){
				
				//find all occurences of substring pattern in input
				while(strstr(input, pattern) != NULL){
					
					
				}
				
			}
			else if(select == 2){
		
			
				//use for loops to compare characters from the text and the pattern
			}
			
			
			//reset values
			flag = 0;
		}
	
	}
}
