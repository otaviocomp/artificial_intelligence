#include <stdio.h>
#include <math.h>

#define MAX_E 0.01

//Bias = 1 and learning rate = 1;

float sumHidden(float weight[][3], const int data[][3], int i, int j){
	return weight[i][0] + weight[i][1]*data[j][0] + weight[i][2]*data[j][1];
}

float sumOutput(float weight[], float h1, float h2){
	return weight[0] + weight[1]*h1 + weight[2]*h2;
}

float sigmoide(float x){
	return 1.0/(1 + pow(M_E, -x));
}

float derivSigmoide(float x){ //derivate of the sigmoide function
	return sigmoide(x)*(1 - sigmoide(x));
}

float errorOutput(float d, float y){
	return (d - y)*derivSigmoide(y);
}

float errorHidden(float deltaOutput, float weightOutput[], float y){
	return derivSigmoide(y)*(deltaOutput*weightOutput[0] + deltaOutput*weightOutput[1] + deltaOutput*weightOutput[2]);
}

void training(float weightHidden[][3], float weightOutput[], const int data[][3], int epochs){
	int i;
	float h1, h2, y, e, deltaOutput, deltaHidden;
	for(epochs; epochs--;)
		for(i = 4; i--;){
			//feedForward
			h1 = sigmoide(sumHidden(weightHidden, data, 0, 3 - i)); //output hidden neuron 1
			h2 = sigmoide(sumHidden(weightHidden, data, 1, 3 - i)); //output hidden neuron 2
			y = sigmoide(sumOutput(weightOutput, h1, h2)); //output neuron last layer
			e = data[3 - i][2] - y;
			if(e < 0) -1*e;
			printf("erro: %f\n", e);
			if(e > MAX_E){ //backPropagation 
				//output layer
				deltaOutput = errorOutput(data[3 - i][2], y);
				weightOutput[0] = weightOutput[0] + deltaOutput;
				weightOutput[1] = weightOutput[1] + deltaOutput*h1;
				weightOutput[2] = weightOutput[2] + deltaOutput*h2;

				//hidden layer
				deltaHidden = errorHidden(deltaOutput, weightOutput, y);
				weightHidden[0][0] = weightHidden[0][0] + deltaHidden;
				weightHidden[0][1] = weightHidden[0][1] + deltaHidden*data[3 - i][0];
				weightHidden[0][2] = weightHidden[0][2] + deltaHidden*data[3 - i][1];
				weightHidden[1][0] = weightHidden[1][0] + deltaHidden;
				weightHidden[1][1] = weightHidden[1][1] + deltaHidden*data[3 - i][0];
				weightHidden[1][2] = weightHidden[1][2] + deltaHidden*data[3 - i][1];
			}
		}		
}

int main(){
	int epochs, input1, input2, result;
	float h1, h2, weightHidden[2][3] = {0,0,0,0,0,0}, weightOutput[3] = {0,0,0};
	const int data[4][3] = {{0,0,0},{1,0,1},{0,1,1},{1,1,0}};	//XOR port

	fputs("epochs:", stdout);
	scanf("%d", &epochs);
	training(weightHidden, weightOutput, data, epochs);
	while(1){
		//inputs 
		fputs("input1: ", stdout);
		scanf("%d", &input1);
		fputs("input2: ", stdout);
		scanf("%d", &input2);

		h1 = sigmoide(weightHidden[0][0] + weightHidden[0][1]*input1 + weightHidden[0][2]*input2);
		h2 = sigmoide(weightHidden[1][0] + weightHidden[1][1]*input1 + weightHidden[1][2]*input2);
		result = (int)sigmoide(weightOutput[0] + weightOutput[1]*h1 + weightOutput[2]*h2);

		fputs("RESULT:", stdout);
		printf("%d\n", result);
	}	
}
