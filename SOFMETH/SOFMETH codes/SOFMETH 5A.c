#include<stdioh.h>
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
	float f = 0;
	float z = 0;
	float v = 0.39894;
	// enter x
	// enter n (must be an even number)
	
	if(x >= 0){
		integrateFlag = 1;
	}
	else x = abs(x);
	
	//W = (xhi - xlo) / N
	w = x / n;
	temp = x;
	x = 0;
	//start loop here
	//calculate simpson's rule
	//where is permissible error coming from?
	for(i = 0; i <= n; i++){
		if(i ! = 0) x = x + temp;
		
		y = pow(x, 2) / 2;
		z = pow(e, (-1 * y);
		f = v * z;
		if(i % 2 == 0){
			termResult = termResult + (2 * f * w / 3);
		}
		else{
			termResult = termResult + (4 * f * w / 3);
		}
		
	}
	if(abs(termResult - oldResult) <= E){
		//answer
	}
	else{
		oldResult = termResult;
		n = 2*n;
	}
	//loop back
}
