#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int* computePrefix(char pattern[], int length){

	int *prefixTable = malloc(sizeof(int) * length);
	int i = 0; //longest prefix that has been found in the pattern
	int j; //current index
	prefixTable[0] = 0; //in
	for(j = 1; j < length; j++){

		while(i > 0 && pattern[i] != pattern[j]){
			i = prefixTable[i];
		}
		if(pattern[i] == pattern[j])
			i++;
		prefixTable[j] = i;
	}
	return prefixTable;
}

int main(int argc, char* argv[]){


	//KNP Searching Algorithm
	char fromText[128] = "";
	char input[64] = "";
	char pattern[64] = "";
	char result[64] = "";
	int i = 0;
	int j = 0;
	int flag = 0;
	FILE *fp = fopen("KNPtest.txt", "r");
	if(fp != NULL){

		while(fgets(fromText, sizeof(fromText), fp) != NULL){

			int length = strlen(fromText);
			if(fromText[length - 1] == '\n') fromText[length - 1] = '\0';

			for(i = 0; i < length; i++){

				if(fromText[i] != '.'){

					if(flag)
						strncat(pattern, &fromText[i], 1);

					else strncat(input, &fromText[i], 1);
				}

				else if(fromText[i] == '.')
					flag = 1;
			}

			int* prefixTable;
			prefixTable = computePrefix(pattern, strlen(pattern));
			for(j = 1; i < strlen(input); j++){
                while(i > 0 && pattern[i] != input[j]){
                    i = prefixTable[i];
                }
                if(pattern[i] == input[j])
                    i++;
                if(i == strlen(pattern)){
                    printf("Pattern shift at %d\n", j - strlen(pattern));
                    i = prefixTable[i];
                }
			}
		}
	}
	_getch();


	return 0;
}
