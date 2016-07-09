#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void computeParam(int arr1[], int arr2[], int n){
	int i = 0;
	float ave1 = 0;
	float ave2 = 0;
	float sum1 = 0;
	float sum2 = 0;
	float b0 = 0;
	float b1a = 0;
	float b1b = 0;
	
	//get sum and average
	for(i = 0; i < n; i++){
		sum1 = sum1 + arr1[i];
		sum2 = sum2 + arr2[i];
	}
	
	
	ave1 = sum1 / n;
	ave2 = sum2 / n;
	
	//get b1
	
	
	for(i = 0; i < n; i++){
		b1a = b1a + (arr1[i] * arr2[i]);
	}
	b1a = b1a - (n * ave1 * ave2);
	printf("%f\n", b1a);
	for(i = 0; i < n; i++){
		b1b = b1b + pow(arr1[i], 2);
	}
	b1b = b1b - (n * pow(ave1, 2));
	b1a = b1a / b1b;
	printf("%f\n", b1a);
	//get b0
	b0 = ave2 - b1a * ave1;
	
	printf("b0: %.2f\n", b0);
	printf("b1: %.4f\n", b1a);
}

int main(){
	
	int x = 0;
	int n;
	int estObjLOC[] = {130, 650, 99, 150, 128, 302, 95, 945, 368, 961};
	int estNaCLOC[] = {163, 765, 141, 166, 137, 355, 136, 1206, 433, 1130};
	int actNaCLOC[] = {186, 699, 132, 272, 291, 331, 199, 1890, 788, 1601};
	int userEst[] = {0, 0, 0};
	int userAct[] = {0, 0, 0};
	
	for(x = 0; x < 3; x++){
		
		if(x == 0){
			printf("Test Case 1: \n");
			computeParam(estObjLOC, actNaCLOC, 10);
		}
		
		else if(x == 1){
			printf("Test Case 2: \n");
			computeParam(estNaCLOC, actNaCLOC, 10);
		}
		
		else if(x == 2){
			
			printf("Test Case 3: \n");
			printf("Input estimated LOC for program 2A\n");
			scanf("%d", &userEst[0]);
			printf("Input actual LOC for program 2A\n");
			scanf("%d", &userAct[0]);
			printf("Input estimated LOC for program 3A\n");
			scanf("%d", &userEst[1]);
			printf("Input actual LOC for program 3A\n");
			scanf("%d", &userAct[1]);
			printf("Input estimated LOC for program 4A\n");
			scanf("%d", &userEst[2]);
			printf("Input actual LOC for program 4A\n");
			scanf("%d", &userAct[2]);
		
			computeParam(userEst, userAct, 3);
		}
		printf("\n");
	}
	
	
	
	
}
