#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void inputs(int *n, float *step, float *y, int *epochs, float *e);
float *weight(int n, float *W);
float *inputs_X(int n, float *X);
float function(float x);
float forward(int n, float *W, float *X);
float get_error(float y, float x);
float *update_weight(int n, float step, float error, float *W, float *X);

int main(){
	int n, i, epochs, count = 0, result; 
	float *W, *X, step, y, e, error;
	inputs(&n, &step, &y, &epochs, &e);	
	W = weight(n, W);
	X = inputs_X(n, X);
	result = forward(n, W, X);
	error = get_error(y, result);
	while(error > e && count < epochs){
		count++;
		W = update_weight(n, step, error, W, X);
		result = (int)forward(n, W, X);
		error = get_error(y, result);
	}	
	printf("result = %f\n", result);
}

void inputs(int *n, float *step, float *y, int *epochs, float *e){
	printf("type the number of inputs: ");
	scanf("%d", n);
	printf("type the value of the step: ");
	scanf("%f", step);
	printf("type the expected value: ");
	scanf("%f", y);
	printf("type the number of epochs: ");
	scanf("%d", epochs);
	printf("type the minimum error: ");
	scanf("%f", e);
}

float *weight(int n, float *W){
	int i;
	clock_t t;
	srand(t);
	W = malloc((n + 1)*sizeof(float));
	for(i = 0; i <= n; i++)
		W[i] = rand()%11/10.0;	
	return W;
}

float *inputs_X(int n, float *X){
	int i;
	X = malloc(n*sizeof(float));
	X[0] = -1;
	printf("type the values of the inputs: \n");
	for(i = 1; i <= n; i++){
		printf("X[%d] = ", i);
		scanf("%f", &X[i]);
	}
	return X;
}

//step function
float function(float x){
	if(x >= 0) return 1;
	else return 0;
}

float forward(int n, float *W, float *X){
	int i;
	float result = 0.0;
	for(i = 0; i <= n; i++)
		result = W[i]*X[i] + result;
	result = function(result);
	return result;
}

float get_error(float y, float x){
	return fabs(x - y);
}

float *update_weight(int n, float step, float error, float *W, float *X){	
	int i;
	for(i = 0; i <= n; i++)
		W[i] = W[i] + step*error*X[i];
	return W;
}
