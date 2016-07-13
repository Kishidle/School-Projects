#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	int select;
	
	printf("Select method of searching: \n");
	printf("[1] With string functions \n");
	printf("[2] Without string functions \n");
	
	scanf("%d", &select);
	
	if(select == 1){
		
		//use strstr() with a char pointer as the one to receive
	}
	else if(select == 2){
		
		//use for loops to compare characters from the text and the pattern
	}
}
