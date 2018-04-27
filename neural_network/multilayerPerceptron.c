#include <stdio.h>
#include <math.h>

#define MAX_E 0.01

//Bias = 1 and learning rate = 1;

float sumHidden(float pesos[][3], const int dados[][3], int i, int j){
	return pesos[i][0] + pesos[i][1]*dados[j][0] + pesos[i][2]*dados[j][1];
}

float sumOutput(float pesos[], float h1, float h2){
	return pesos[0] + pesos[1]*h1 + pesos[2]*h2;
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

float errorHidden(float deltaOutput, float pesosOutput[], float y){
	return derivSigmoide(y)*(deltaOutput*pesosOutput[0] + deltaOutput*pesosOutput[1] + deltaOutput*pesosOutput[2]);
}

void training(float pesosHidden[][3], float pesosOutput[], const int dados[][3], int epochs){
	int i;
	float h1, h2, y, e, deltaOutput, deltaHidden;
	for(epochs; epochs--;)
		for(i = 4; i--;){
			//feedForward
			h1 = sigmoide(sumHidden(pesosHidden, dados, 0, 3 - i)); //output hidden neuron 1
			h2 = sigmoide(sumHidden(pesosHidden, dados, 1, 3 - i)); //output hidden neuron 2
			y = sigmoide(sumOutput(pesosOutput, h1, h2)); //output neuron last layer
			e = dados[3 - i][2] - y;
			if(e > MAX_E){ //backPropagation 
				//output layer
				deltaOutput = errorOutput(dados[3 - i][2], y);
				pesosOutput[0] = pesosOutput[0] + deltaOutput;
				pesosOutput[1] = pesosOutput[1] + deltaOutput*h1;
				pesosOutput[2] = pesosOutput[2] + deltaOutput*h2;

				//hidden layer
				deltaHidden = errorHidden(deltaOutput, pesosOutput, y);
				pesosHidden[0][0] = pesosHidden[0][0] + deltaHidden;
				pesosHidden[0][1] = pesosHidden[0][1] + deltaHidden*dados[3 - i][0];
				pesosHidden[0][2] = pesosHidden[0][2] + deltaHidden*dados[3 - i][1];
				pesosHidden[1][0] = pesosHidden[1][0] + deltaHidden;
				pesosHidden[1][1] = pesosHidden[1][1] + deltaHidden*dados[3 - i][0];
				pesosHidden[1][2] = pesosHidden[1][2] + deltaHidden*dados[3 - i][1];
			}
		}		
}

int main(){
	int epochs, input1, input2;
	float result, h1, h2, pesosHidden[2][3] = {0,0,0,0,0,0}, pesosOutput[3] = {0,0,0};
	const int dados[4][3] = {{0,0,0},{1,0,1},{0,1,1},{1,1,0}};	//XOR port

	fputs("epochs:", stdout);
	scanf("%d", epochs);
	training(pesosHidden, pesosOutput, dados, epochs);
	while(1){
		//inputs 
		fputs("input1: ", stdout);
		scanf("%f", input1);
		fputs("input2: ", stdout);
		scanf("%f", input2);

		h1 = sigmoide(pesosHidden[0][0] + pesosHidden[0][1]*input1 + pesosHidden[0][2]*input2);
		h2 = sigmoide(pesosHidden[1][0] + pesosHidden[1][1]*input1 + pesosHidden[1][2]*input2);
		result = sigmoide(pesosOutput[0] + pesosOutput[1]*h1 + pesosOutput[2]*h2);

		fputs("RESULT:", stdout);
		printf("%f", result);
	}	
}
