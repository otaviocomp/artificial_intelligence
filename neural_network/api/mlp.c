#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_E 0.001
#define LEARNING_RATE 0.1
//Bias = 1 and learning rate = 1;

float sumHidden(float weight[][3], const int data[][2], int i, int j){
	return weight[i][0] + weight[i][1]*data[j][0] + weight[i][2]*data[j][1];
}

float sumOutput(float weight[], float h1, float h2){
	return weight[0] + weight[1]*h1 + weight[2]*h2;
}

float sigmoide(float x){
	return 1.0/(1 + pow(M_E, -x));
}

float derivSigmoide(float x){	//derivate of the sigmoide function 	
	return sigmoide(x)*(1 - sigmoide(x));
}

float errorOutput(float d, float y){
	return (d - y)*derivSigmoide(y);
}

float errorHidden(float deltaOutput, float weightOutput[], float y){
	return derivSigmoide(y)*(deltaOutput*weightOutput[0] + deltaOutput*weightOutput[1] + deltaOutput*weightOutput[2]);
}

void training(float weightHidden[][3], float weightOutput[], const int data[][2], const int result_data[], int epochs){
	int i;
	float h1, h2, y, error, oldError = 0, deltaOutput, deltaHidden;
	for(epochs; epochs--;)
		for(i = 4; i--;){
			//feedForward
			h1 = sigmoide(sumHidden(weightHidden, data, 0, i)); //output hidden neuron 1
			h2 = sigmoide(sumHidden(weightHidden, data, 1, i)); //output hidden neuron 2
			y = sigmoide(sumOutput(weightOutput, h1, h2)); //output neuron last layer
			error = data[i][2] - y;
			error = error - oldError;
			printf("erro data[%d]: %f\n", i, error);
			if(error > MAX_E){ //backPropagation 
				//output layer
				deltaOutput = errorOutput(result_data[i], y);
				weightOutput[0] = weightOutput[0] + LEARNING_RATE*deltaOutput;
				weightOutput[1] = weightOutput[1] + LEARNING_RATE*deltaOutput*h1;
				weightOutput[2] = weightOutput[2] + LEARNING_RATE*deltaOutput*h2;

				//hidden layer
				deltaHidden = errorHidden(deltaOutput, weightOutput, y);
				weightHidden[0][0] = weightHidden[0][0] + LEARNING_RATE*deltaHidden;
				weightHidden[0][1] = weightHidden[0][1] + LEARNING_RATE*deltaHidden*data[i][0];
				weightHidden[0][2] = weightHidden[0][2] + LEARNING_RATE*deltaHidden*data[i][1];
				weightHidden[1][0] = weightHidden[1][0] + LEARNING_RATE*deltaHidden;
				weightHidden[1][1] = weightHidden[1][1] + LEARNING_RATE*deltaHidden*data[i][0];
				weightHidden[1][2] = weightHidden[1][2] + LEARNING_RATE*deltaHidden*data[i][1];
			}
			oldError = error;
		}		
}

void weights(float weightHidden[][3], float weightOutput[]){
	int size = 1, i, j;
	srand(time(NULL));
	for(i = size; i--;)
		for(j = 2; j--;)
			weightHidden[i][j] = rand()%11/10.0;
	for(i = 2; i--;)
		weightOutput[i] = rand()%11/10.0;
}

int main(){
	int epochs, input1, input2;
	float result, h1, h2, weightHidden[2][3], weightOutput[3];
	const int data[4][2] = {{0,0},{1,0},{0,1},{1,1}};	//XOR port
	const int result_data[4] = {0,1,1,0};
	weights(weightHidden, weightOutput);

	fputs("epochs:", stdout);
	scanf("%d", &epochs);
	training(weightHidden, weightOutput, data, result_data, epochs);
	printf("\nweightOutput0:%f\n", weightOutput[0]);
	printf("weightOutputO1:%f\n", weightOutput[1]);
	printf("weightOutputO2:%f\n", weightOutput[2]);
	printf("weightHidden00:%f\n", weightHidden[0][0]);
	printf("weightHidden01:%f\n", weightHidden[0][1]);
	printf("weightHidden02:%f\n", weightHidden[0][1]);
	printf("weightHidden10:%f\n", weightHidden[1][0]);
	printf("weightHidden11:%f\n", weightHidden[1][1]);
	printf("weightHidden12:%f\n", weightHidden[1][2]);
	while(1){
		//inputs 
		fputs("input1: ", stdout);
		scanf("%d", &input1);
		fputs("input2: ", stdout);
		scanf("%d", &input2);

		h1 = sigmoide(weightHidden[0][0] + weightHidden[0][1]*input1 + weightHidden[0][2]*input2);
		h2 = sigmoide(weightHidden[1][0] + weightHidden[1][1]*input1 + weightHidden[1][2]*input2);
		result = sigmoide(weightOutput[0] + weightOutput[1]*h1 + weightOutput[2]*h2);

		fputs("RESULT:", stdout);
		printf("%f\n", result);
	}	
}
