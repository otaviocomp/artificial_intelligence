#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *weight(int n, float *W);
float *inputs(int n, float *X);

int main()
{
	int n, i; 
	float *W, *X, y;

	printf("type the number of inputs: ");
	scanf("%d", &n);
	printf("type the expected value: ");
	scanf("%f", &y);

	W = weight(n, W);
	X = inputs(n, X);

	printf("y = %f\n", y);
	for(i = 0; i < n; i++)
		printf("X[%d] = %f\n", i, X[i]);
	for(i = 0; i <= n; i++)
		printf("W[%d] = %f\n", i, W[i]);
}

float *weight(int n, float *W)
{
	int i;
	W = malloc((n + 1)*sizeof(float));
	W[0] = -1;
	for(i = 1; i <= n; i++)
		W[i] = 0.5;	
	return W;
}

float *inputs(int n, float *X)
{
	int i;
	X = malloc(n*sizeof(float));
	printf("type the values of the inputs: \n");
	for(i = 0; i < n; i++)
	{
		printf("X[%d] = ", i);
		scanf("%f", &X[i]);
	}
	return X;
}

