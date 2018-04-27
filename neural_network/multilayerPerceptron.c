#include <stdio.h>
#include <math.h>

float sigmoide(float x){
	return 1.0/(1 + pow(M_E, x));
}

int main(){
	
