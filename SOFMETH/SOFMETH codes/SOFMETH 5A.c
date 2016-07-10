#include<stdio.h>
#include<math.h>

int main(){
	
	float x = 0;
	int n = 0;
	int i = 0;
	float oldResult = 0;
	float result = 0;
	int integrateFlag = 0;
	float w = 0;
	float termResult = 0;
	float temp = 0;
	float y = 0;
	float e = 2.71828;
	float err = 0;
	float f = 0;
	float z = 0;
	float v = 0.39894;
	printf("Enter x: ");
	scanf("%f", &x);
	printf("Enter N: ");
	scanf("%d", &n);
	// enter x
	// enter n (must be an even number)
	
	if(x >= 0){
		integrateFlag = 1;
	}
	else x = fabs(x);
	//W = (xhi - xlo) / N
	w = x / n;
	temp = w;
	x = 0;
	//start loop here
	while(1){
	
	//calculate simpson's rule
		for(i = 0; i <= n; i++){
			if(i != 0) x = x + temp;
			//need error checking for x = 0 so that it won't error
			
			y = pow(x, 2) / 2;
			//printf("%f\n", y);
			z = pow(e, (-1 * y));
			//printf("%f\n", z);
			f = v * z;
			//printf("%.5f\n", f);
			if(i == 0 || i == n){
				termResult = termResult + (f * w / 3);
			}
			
			else if(i % 2 == 0){
				termResult = termResult + (2 * f * w / 3);
			}
			else if(i % 2 != 0){
				termResult = termResult + (4 * f * w / 3);
			}
		
		}
		if(abs(termResult - oldResult) <= err){
			//answer
			break;
		}
		else{
			err = abs(termResult - oldResult);
			oldResult = termResult;
			n = 2*n;
		}
		//loop back
	
	}
	if(integrateFlag) termResult = termResult + 0.5;
	else termResult = 0.5 - termResult;
	
	printf("Result: %f", termResult);
	
	
}
