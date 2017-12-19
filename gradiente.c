#include <stdio.h>
#include <stdlib.h>

//void input_vars(int n, float *coef, float *sted, float *start);
float *deriv(int n, float *coef, float *dcoef);

int main()
{
	int n, i;
	float step, start;
	printf("digite a ordem da funcao: ");
	scanf("%d", &n);
		
	// alocar vetores com coeficientes da funcao // coef -> f(x) dcoef -> f'(x)
	float *coef = malloc((n + 1)*sizeof(float));    
	float *dcoef = malloc(n*sizeof(float));    

	printf("digite os coeficientes da funcao (do coeficiente de maior ordem para o menor):\n");
	for(i = 0; i <= n; i++)
	{
		printf("coeficiente de x^%d = ", n - i);
		scanf("%f", &coef[i]);
	}
	printf("digite o valor do passo: ");
	scanf("%f", &step);
	printf("digite o valor inicial: ");
	scanf("%f", &start);

	//input_vars(n, coef, &step, &start);
	dcoef = deriv(n, coef, dcoef);	

	printf("f(x) = ");
	for(i = 0; i <= n; i++)
		printf("%fx^%d ", coef[i], n - i);
	printf("\n");
	printf("f'(x) = ");
	for(i = 0; i < n; i++)
		printf("%fx^%d ",dcoef[i], n - i - 1);
	printf("\nstep = %f start = %f\n", step, start);	
	printf("\n");	
}

/*void input_vars(int n, float *coef, float *step, float *start)
{

}
*/
float *deriv(int n, float *coef, float *dcoef)
{
	int i;
	for(i = 0; i < n; i++)
		dcoef[i] = coef[i]*(n - i);
	return dcoef;
}

