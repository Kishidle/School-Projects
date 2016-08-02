#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//This program uses the Knutt-Morris-Pratt algorithm for string searching
//Made by Ramon Arca
void computePrefix(int prefix[], char pattern[], int length){

	//int *prefixTable = malloc(sizeof(int) * length);

	int i = -1; //longest prefix that has been found in the pattern
	int j = 0; //current index
	 //in
	prefix[0] = i;
	for(j = 1; j < length; j++){

		while(i > -1 && pattern[i + 1] != pattern[j]){
			i = prefix[i];
			//printf("test");
			
		}
		if(pattern[i + 1] == pattern[j]) //tries to find a prefix
			i++;
		prefix[j] = i;
	}
	
}

int main(int argc, char* argv[]){


	//KMP Searching Algorithm
	char fromText[130] = "";
	char input[130] = "";
	char pattern[130] = "";
	//char result[ = "";
	int i = 0;
	int j = 0;
	int x = 1;
	int flag = 0;
	int z = 0;
	FILE *fp = fopen("inputall.txt", "r");

	if(fp != NULL){

		while(fgets(fromText, sizeof(fromText), fp) != NULL){

			int length = strlen(fromText);
			int prefix[130] = { 0 };
			//for(z = 0; z < 64; z++) printf("%d", prefix[z]);
            i = 0;
            j = 0;
			if(fromText[length - 1] == '\n') fromText[length - 1] = '\0';
			
			printf("String #%d: %s\n\n", x, fromText);
			for(i = 0; i < length; i++){

				if(fromText[i] != '.'){

					if(flag)
						strncat(pattern, &fromText[i], 1);

					else strncat(input, &fromText[i], 1);
				}

				else if(fromText[i] == '.')
					flag = 1;
				
			}
			flag = 0;
			i = 0;
			//int* prefixTable = computePrefix(pattern, strlen(pattern));
			computePrefix(prefix, pattern, strlen(pattern));
			//printf("\ntest");
			for(j = 0; j < strlen(input); j++){
                while(i > -1 && pattern[i + 1] != input[j]){
                	i = prefix[i];
                	//printf("test");
                }
                     //skip using prefix
                
                if(pattern[i + 1] == input[j])
                    i++; //next character matches
                if(i == strlen(pattern) - 1){
                    printf("Pattern occurs with shift %d\n", j - strlen(pattern) + 1);
                    flag = 1; // checking for invalid shift later
                    i = prefix[i]; // look for next match if it exists
                }
               
			}
			
			if(!flag){
                printf("Invalid shift\n");
			}
			x++;
			flag = 0;
			memset(input, 0, sizeof(input));
			memset(pattern, 0, sizeof(pattern));
			//memset(prefix, 0, sizeof(prefix));
			
		}
	}
	


	return 0;
}
