#include <stdio.h>

int main(){
	float sum, weights[3] = {0,0,0}, error;
	int i, input1, input2, epochs, res;
	const int data[4][2] = {{0,0},{0,1},{1,0},{1,1}};
	const int results[4] = {0,0,0,1};
	
	//epochs
	fputs("epochs: ", stdout);
	scanf("%d", &epochs);

	//training
	for(epochs; epochs--;)
		for(i = 4; i--;){
			//sum synaptics weights and inputs(data de treinamento)
			sum = 0;
			sum = weights[0] + data[i][0]*weights[1] + data[i][1]*weights[2];

			//activation function(step function)
			if(sum > 0) res = 1;
			else res = 0;

			//calcula o error
			error = results[i] - res;
			printf("error data[%d]: %d\n", i, error);

			//upgrade weights(bias and step values are equal to 1)
			if(error){
				weights[0] += error;				
				weights[1] += error*data[i][0];
				weights[2] += error*data[i][1];
			}
		}	
	puts("RESULTADO DO TREINAMENTO:");		
	printf("w[0] = %f\n", weights[0]);
	printf("w[1] = %f\n", weights[1]);
	printf("w[2] = %f\n", weights[2]);
	//resultado dos inputs
	while(1){
		//inputs
		fputs("input1: ", stdout);
		scanf("%d", &input1);
		fputs("input2: ", stdout);
		scanf("%d", &input2);

		//resultado
		sum = 0;
		sum = weights[0] + input1*weights[1] + input2*weights[2];
		if(sum > 0) res = 1;
		else res = 0;
		printf("RESULTADO: %d\n\n", res);
	}
}
