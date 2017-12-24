#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *weight(int n, float *W);
void perceptron_config(int *n, float *W, float *X, float *y);

int main()
{
	int n, i; 
	float *W, *X, y;
	printf("type the number of inputs: ");
	scanf("%d", n);
	printf("y = %f\n", y);
	for(i = 0; i < n; i++)
		printf("X[%d] = %f\n", i, X[i]);
	for(i = 0; i <= n; i++)
		printf("W[%d] = %f\n", i, W[i]);
}

void perceptron_config(int *n, float *W, float *X, float *y)
{
	int i;
	X = malloc(*n*sizeof(float));
	printf("type the values of the inputs: \n");
	for(i = 0; i < *n; i++)
	{
		printf("X[%d] = ", i);
		scanf("%f", &X[i]);
	}
	printf("type the expected value: ");
	scanf("%f", y);

	W = malloc((*n + 1)*sizeof(float));

	// bias
	W[0] = -1;
	for(i = 1; i <= *n; i++)
		W[i] = 0.5;	
	for(i = 0; i < *n; i++)
		printf("X[%d] = %f\n", i, X[i]);
}
