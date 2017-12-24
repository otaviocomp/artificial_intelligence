#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputs(int *n, float *step, float *y);
float *weight(int n, float *W);
float *inputs_X(int n, float *X);
float function(float x);
//float update_weight(

int main()
{
	int n, i, epochs; 
	float *W, *X, step, y, e;

	inputs(&n, &step, &y, &epochs, &e);
	W = weight(n, W);
	X = inputs_X(n, X);

	printf("y = %f\n", y);
	for(i = 0; i < n; i++)
		printf("X[%d] = %f\n", i, X[i]);
	for(i = 0; i <= n; i++)
		printf("W[%d] = %f\n", i, W[i]);
}

void inputs(int *n, float *step, float *y)
{
	printf("type the number of inputs: ");
	scanf("%d", n);
	printf("type the value of the step: ");
	scanf("%f", step);
	printf("type the expected value: ");
	scanf("%f", y);
	printf("type the number of epochs: ");
	scanf("%f", epochs);
	printf("type the minimum error: ");
	scanf("%f", e);
}

float *weight(int n, float *W)
{
	int i;
	W = malloc((n + 1)*sizeof(float));
	for(i = 0; i <= n; i++)
		W[i] = 0.5;	
	return W;
}

float *inputs_X(int n, float *X)
{
	int i;
	X = malloc(n*sizeof(float));
	X[0] = -1;
	printf("type the values of the inputs: \n");
	for(i = 1; i <= n; i++)
	{
		printf("X[%d] = ", i);
		scanf("%f", &X[i]);
	}
	return X;
}

float function(float x)
{
	// step function
	if(x >= 0)
		return 1;
	else 
		return 0;
}

float forward(int n, float *W, float *X)
{
	int i;
	float result = 0.0;
	for(i = 0; i <= n; i++)
		result = W[i]*X[i] + result;
	result = function(result);
	return result;
}

float *update_weight(int n, float step, int epochs, float e, float *W, float *X)
{	
	int i;
	static int count = 0;
	float result = forward(n, W, X);
	float error = fabs(result - y);
	if(error > e && count < epochs)
	{
		count++;
		for(i = 0; i <= n; i++)
			W[i] = W[i] + step*error*X[i];
	}
	return W;
}





