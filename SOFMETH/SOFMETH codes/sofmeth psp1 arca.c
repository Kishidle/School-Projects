#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	
	int n;
	int i;
	float *arr;
	float mean = 0;
	float stdev = 0;
	
	printf("How many real numbers? ");
	scanf("%d", &n);
	
	arr = malloc(n * sizeof(float));
	
	printf("Input %d real numbers: \n", n);
	
	for(i = 0; i < n; i++){
		scanf("%f", &arr[i]);
		mean = mean + arr[i];
		
	}
	mean = mean / n;
	printf("Mean is: %f \n", mean);
	for(i = 0; i < n; i++){
		stdev = stdev + pow(arr[i] - mean, 2);
		
		
	}
	
	stdev = sqrt(stdev / (n - 1));
	
	printf("Standard deviation is: %f \n", stdev);
	
	getch();
}
