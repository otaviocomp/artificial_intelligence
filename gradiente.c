#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_vars(int n, float *coef, float *sted, float *start, float *stop_error);
void informations(int n, float *coef, float *dcoef, float step, float start, float stop_error);
float *deriv(int n, float *coef, float *dcoef);
float df(int n, float *dcoef, float x);
float iteration(int n, float *dcoef, float step, float start, float stop_error);

int main()
{
	int n, i;
	float step, start, stop_error, result;
	printf("digite a ordem da funcao: ");
	scanf("%d", &n);
		
	// alocar vetores com coeficientes da funcao // coef -> f(x) dcoef -> f'(x)
	float *coef = malloc((n + 1)*sizeof(float));    
	float *dcoef = malloc(n*sizeof(float));    


	input_vars(n, coef, &step, &start, &stop_error);
	dcoef = deriv(n, coef, dcoef);	
	informations(n, coef, dcoef, step, start, stop_error);

	printf("df = %f\n", df(n, dcoef, start));

	printf("\n--result--\n\n");
	result = iteration(n, dcoef, step, start, stop_error);
	printf("result = %f\n", result);
}

void input_vars(int n, float *coef, float *step, float *start, float *stop_error)
{
	int i;
	printf("digite os coeficientes da funcao (do coeficiente de maior ordem para o menor):\n");
	for(i = 0; i <= n; i++)
	{
		printf("coeficiente de x^%d = ", n - i);
		scanf("%f", &coef[i]);
	}
	printf("digite o valor do passo: ");
	scanf("%f", step);
	printf("digite o valor inicial: ");
	scanf("%f", start);
	printf("digite o erro para a parada: ");
	scanf("%f", stop_error);
}

void informations(int n, float *coef, float *dcoef, float step, float start, float stop_error)
{
	int i;
	printf("\n--informations--\n\n");
	printf("f(x) = ");
	for(i = 0; i <= n; i++)
		printf("%fx^%d ", coef[i], n - i);
	printf("\n");
	printf("f'(x) = ");
	for(i = 0; i < n; i++)
		printf("%fx^%d ",dcoef[i], n - i - 1);
	printf("\nstep = %f\n", step);
	printf("start = %f\n", start);
	printf("stop_error = %f\n", stop_error);
}

float *deriv(int n, float *coef, float *dcoef)
{
	int i;
	for(i = 0; i < n; i++)
		dcoef[i] = coef[i]*(n - i);
	return dcoef;
}

float df(int n, float *dcoef, float x)
{
	int i;
	int result = 0;
	for(i = 0; i < n; i++)
		result = dcoef[i]*x + result; 
	return result;
}

float iteration(int n, float *dcoef, float step, float start, float stop_error)
{
	float error = start;
	float x = start;
	while(error > stop_error)
	{
		x = x - step*df(n, dcoef, x);
		error = fabs(x - error);
		printf("x = %f	error = %f\n", x, error);
	}
	return x;
}

