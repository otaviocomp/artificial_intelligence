#include <stdio.h>
#include <stdlib.h>

int *deriv(int *coef, int *dcoef, int n);

int main()
{
	int n, i;
	float step, init;
	printf("digite a ordem da funcao: ");
	scanf("%d", &n);
		
	// alocar vetores com coeficientes da funcao
	int *coef = malloc(n*sizeof(int));    // f(x)
	int *dcoef = malloc((n - 1)*sizeof(int));    // f'(x)	
	
	printf("digite os coeficientes da funcao (do coeficiente de maior ordem para o menor):\n");
	for(i = n; i >= 0; i--)
		scanf("%d", &coef[i]);

	printf("digite o valor do passo: ");
	scanf("%f", step);
	printf("digite o valor inicial: ");
	scanf("%f", init);

	dcoef = deriv(coef, dcoef, n);	
}

int *deriv(int *coef, int *dcoef, int n)
{
	int i;
	for(i = n - 1; i >= 0; i++)
		dcoef[i] = coef[i + 1]*(i + 1);
	return dcoef;
}


