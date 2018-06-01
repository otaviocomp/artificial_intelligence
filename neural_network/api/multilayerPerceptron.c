#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_E 0.001
#define LEARNING_RATE 0.1

float *sum(float **weights, const float **input, int sizeW, int sizeI){
	for(sizeW;
}

float *sigmoide(float *x, int size){					//i is the size of vector
	float result[size];
	for(size;size--;)
		result[size] = 1.0/(1 + pow(M_E, -x[size]));
	return result;
}

void training(float **WH, float WO, const int *data, const int *result){
	int epochs=100;										//number of epochs
	for(epochs;epochs--;)
		for(i=4;i--;){									//i is the number of inputs(4 inputs in XOR)
		
}

void initWeights(float **WH, float *WO){
	int i,j;
	srand(time(NULL));
	for(i=10;i--;)
		for(j=3;j--;)
			WH[i][j] = rand()%11/10.0;
	for(i=11;i--;)
		WO[i] = rand()%11/10.0;
}

int main(){
	float WH[10][3], WO[1][11];							//weights declarations
	const float data[4][2] = {{0,0},{1,0},{0,1},{1,1}}; //XOR input
	const int result[4] = {0,1,1,0};					//XOR output
	initWeights(WH,WO);									//initialize the weights with random values
	training(WH,WO,data,result);						//training the neural network
}

