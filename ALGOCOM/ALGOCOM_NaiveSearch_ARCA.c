#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	int select;
	char fromText[64];
	char input[64];
	char pattern[64];
	
	printf("Select method of searching: \n");
	printf("[1] With string functions \n");
	printf("[2] Without string functions \n");
	
	scanf("%d", &select);
	
	FILE *fp;
	
	fp = fopen("input.txt");
	if(fp != NULL){
		
		while(fgets(fromText, sizeof(fromText), fp) != NULL){
		
			if(select == 1){
				
				//use strstr() with a char pointer
			}
			else if(select == 2){
		
			
				//use for loops to compare characters from the text and the pattern
			}
		}
	
	}
}
