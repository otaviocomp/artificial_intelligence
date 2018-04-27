#include <stdio.h>
#include <math.h>

//Bias = 1;

float sumHidden(float pesos[][3], const int dados[][3], int i, int j){
	return pesos[i][0] + pesos[i][1]*dados[j][0] + pesos[i][2]*dados[j][1];
}

float sumOutput(float pesos[], float h1, float h2);{
	return pesos[0] + pesos[1]*h1 + pesos[2]*h2;
}

float sigmoide(float x){
	return 1.0/(1 + pow(M_E, -x));
}

float derivSigmoide(float x){
	return sigmoide(x)*(1 - sigmoide(x));
}

float errorOutput(float d, float y){
	return (d - y)*derivSigmoide(d - y);
}

void training(float pesosHidden[][3], float pesosOutput[], const int dados[][3], int epochs){
	int i = 4;
	float h1, h2;
	for(epochs; epochs--;)
		for(i; i--;){
			h1 = sigmoide(sumHidden(pesosHidden, dados, 0, 3 - i));
			h2 = sigmoide(sumHidden(pesosHidden, dados, 1, 3 - i));
}

int main(){
	int epochs, result;
	float input1, input2, pesosHidden[2][3] = {0,0,0,0,0,0}, pesosOutput[3] = {0,0};
	const int dados[4][3] = {{0,0,0},{1,0,1},{0,1,1},{1,1,0}};	

	fputs("epochs:", stdout);
	scanf("%d", epochs);

	while(1){
		//inputs 
		fputs("input1: ", stdout);
		scanf("%f", input1);
		fputs("input2: ", stdout);
		scanf("%f", input2);
		fputs("RESULT:", stdout);
		printf("%d", result);
	}	
}
