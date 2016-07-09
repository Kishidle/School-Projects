#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp = fopen("sofmeth 1.c", "r");
	int lineCount = 0;
	int multiFlag = 0;
	int charFlag = 0;
	int lineFlag = 0;
	int tabFlag = 0;
	int skipFlag = 0;
	int i;
	if(fp != NULL){
		char line[1024];	
		while(fgets(line, sizeof(line), fp) != NULL){
			for(i = 0; i < strlen(line); i++){
				if(line[0] == '\n' || multiFlag == 1){
					lineFlag = 1;
					break;
				}
				if(line[i] == '/' && line[i+1] == '*'){
					lineFlag = 1;
					multiFlag = 1;
				}
				if(line[i] == '*' && line[i+1] == '/'){
					lineFlag = 0;
					multiFlag = 0;
					i++;
					skipFlag = 1;
				}
				if(line[i] != ' ' && skipFlag == 0){
					if(line[i] == '/' && line[i+1] == '/' && charFlag == 0){
						break; 
					}
					if(line[i] == '\t' && charFlag == 0){
						tabFlag = 1;
					}
					if(line[i] != '\t' && line[i] != '\n' && multiFlag == 0){
						charFlag = 1;
						tabFlag = 0;
					}
				}
				if(i == strlen(line) - 1 && tabFlag == 1 && skipFlag == 0){
					break;
				}
				if(i == strlen(line) - 1 && charFlag == 1 && lineFlag == 0 && skipFlag == 0){
					lineCount++;
				}
				skipFlag = 0;
			}
			charFlag = 0;
			tabFlag = 0;
			lineFlag = 0;
			multiFlag = 0;
		}
		fclose(fp);
		printf("%d", lineCount);
	}
}
