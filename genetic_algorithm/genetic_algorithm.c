#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_input(int *size_population, int *bits, int *epochs);
int **set(int **population, int size_population, int bits);
int *value(int **population, int *value_vector, int size_population, int bits);
float *fitness(int *value_vector, float *fitness_vector, int size_population);
int **selection(int **population, float *fitness_vector, int size_population, int bits);
int **crossover(int **population, int size_population, int bits);
int **mutation(int **population, int size_population, int bits); 

int main()
{
	int **population, *value_vector, size_population, bits, i, j, epochs;
	float *fitness_vector;
	
	get_input(&size_population, &bits, &epochs); // get values 
	population = set(population, size_population, bits); // create population
	for(i = 0; i < epochs; i++)
	{
		value_vector = value(population, value_vector, size_population, bits); 
		fitness_vector = fitness(value_vector, fitness_vector, size_population);
		population = selection(population, fitness_vector, size_population, bits);
		population = crossover(population, size_population, bits);
		population = mutation(population, size_population, bits);
	}
	printf("\n--result--\n\n");
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
			printf("%d ", population[i][j]);
		printf("\n");	
	}	
}

void get_input(int *size_population, int *bits, int *epochs)
{
	printf("type the size of population: "); 
	scanf("%d", size_population);
	printf("type the number of bits: ");
	scanf("%d", bits);
	printf("type the number of epochs: ");
	scanf("%d", epochs);
}


int **set(int **population, int size_population, int bits)
{
	int i, j;
	clock_t t;
	srand(t);

	// memory allocation
	population = malloc(size_population*sizeof(int*));
	for(i = 0; i < size_population; i++)
		population[i] = malloc(bits*sizeof(int));

	// attribution	
	for(i = 0; i < size_population; i++)
		for(j = 0; j < bits; j++)
			population[i][j] = rand()%2;
	
	//result		
	printf("\n--matrix of population--\n\n");			
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
			printf("%d ", population[i][j]);
		printf("\n");	
	}	
	return population;	
}

int *value(int **population, int *value_vector, int size_population, int bits)
{
	int i, j, sum = 0, prod = 1;
	value_vector = malloc(size_population*sizeof(int));
	for(i = 0; i < size_population; i++)
	{
		for(j = bits - 1; j >= 0; j--)
		{
			sum += population[i][j]*prod;
			prod *= 2;
		}
		value_vector[i] = sum;
		prod = 1;
		sum = 0;
	}
	printf("\n--value of vector--\n\n");
	for(i = 0; i < size_population; i++)
		printf("%d\n", value_vector[i]);
	return value_vector;
}

float *fitness(int *value_vector, float *fitness_vector, int size_population)
{
	int i, max = 0;
	fitness_vector = malloc(size_population*sizeof(float));
	for(i = 0; i < size_population; i++)
		max += value_vector[i];
	for(i = 0; i < size_population; i++)
		fitness_vector[i] = (float)value_vector[i]/(float)max;
	printf("\n--fitness--\n\n");
	for(i = 0; i < size_population; i++)
		printf("%f %\n", fitness_vector[i]*100.0);	
	return fitness_vector;	
}

int **selection(int **population, float *fitness_vector, int size_population, int bits)
{
	int i, j, position = 1; 
	float sum = 0, probability, inferior_limit, superior_limit;
	float *accumulated = malloc(size_population*sizeof(float));
	clock_t t;
	srand(t);
	
	int **new_population = malloc(size_population*sizeof(int*));
	for(i = 0; i < size_population; i++)
		new_population[i] = malloc(bits*sizeof(int));

	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < position; j++)	
			sum += fitness_vector[j];
		accumulated[i] = sum*100.0;
		sum = 0;
		position++;
	}

	printf("\n--accumulated--\n\n");
	for(i = 0; i < size_population; i++)
		printf("%f\n", accumulated[i]);

	position = 0;
	for(i = 0; i < size_population; i++)
	{
		// roulette
		inferior_limit = 0.0;
		probability = rand()%10000/100.0;
		printf("probability = %f\n", probability);
		for(j = 0; j < size_population; j++)
		{
			superior_limit = accumulated[j];
			if(probability >= inferior_limit && probability <= superior_limit)
				break;
			inferior_limit = superior_limit; 	
			position++;
		}
		printf("position = %d\n", position);
		for(j = 0; j < bits; j++)
			new_population[i][j] = population[position][j];
		position = 0;
	}
	printf("\n--selected population--\n\n");
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
			printf("%d ", new_population[i][j]);
		printf("\n");	
	}	
	return new_population;	
}

int **crossover(int **population, int size_population, int bits)
{
	int i, j, crossover_probability, prob, tmp;
	clock_t t;
	srand(t);
	printf("\n--crossover--\n\n");
	for(i = 0; i < size_population; i += 2)
	{
		crossover_probability = rand()%101;
		if(crossover_probability < 76)
		{
			printf("crossover %d - %d\n", i, i + 1);
			prob = rand()%bits;
			printf("position %d\n", prob);
			for(j = bits - 1; j >= prob; j--)
			{
				tmp = population[i][j];
				population[i][j] = population[i + 1][j];
				population[i + 1][j] = tmp;
			}
		}
	}
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
			printf("%d ", population[i][j]);
		printf("\n");	
	}	
	return population;
}		
		
int **mutation(int **population, int size_population, int bits)
{ 
	int i, j; 
	clock_t t;
	srand(t);
	printf("\n--mutation--\n\n");
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
		{
			if((rand()%100) == 0)
			{
				printf("mutation in %d - %d\n", i, j);
				if(population[i][j] == 1)
					population[i][j] = 0;
				else
					population[i][j] = 1;
			}
		}
	}
	for(i = 0; i < size_population; i++)
	{
		for(j = 0; j < bits; j++)
			printf("%d ", population[i][j]);
		printf("\n");	
	}
	return population;
}




