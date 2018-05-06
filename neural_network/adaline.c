#include <stdio.h>

float sum(const int data[], float weight[], sizeWeight){
	float result = weight[0];
	for(sizeWeight; i--;)
		result += weight[sizeWeight]*data[sizeWeight];
	return result;
}

int step(float x){
	if(x > 0) return 1;
	return 0;
}

void 

int main(){
	float soma, weight[3] = {0,0,0};
	int erro, i, input1, input2, epocas, result;
	const int data[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};
	
	//epocas
	fputs("epocas: ", stdout);
	scanf("%d", &epocas);

	//treinamento
	for(epocas; epocas--;)
		for(i = 4; i--;){
			//soma weight sinapticos e inputs(data de treinamento)
			soma = 0;
			soma = weight[0] + data[i][0]*weight[1] + data[i][1]*weight[2];

			//funcao de ativacao(degrau)
			if(soma > 0) result = 1;
			else result = 0;

			//calcula o erro
			erro = data[i][2] - result;
			printf("erro data[%d]: %d\n", i, erro);

			//atualiza os weight(bias and step values are equal to 1)
			if(erro){
				weight[0] = weight[0] + erro;				
				weight[1] = weight[1] + erro*data[i][0];
				weight[2] = weight[2] + erro*data[i][1];
			}
		}	
	puts("RESULTADO DO TREINAMENTO:");		
	printf("w[0] = %f\n", weight[0]);
	printf("w[1] = %f\n", weight[1]);
	printf("w[2] = %f\n", weight[2]);
	//resultado dos inputs
	while(1){
		//inputs
		fputs("input1: ", stdout);
		scanf("%d", &input1);
		fputs("input2: ", stdout);
		scanf("%d", &input2);

		//resultado
		soma = 0;
		soma = weight[0] + input1*weight[1] + input2*weight[2];
		if(soma > 0) result = 1;
		else result = 0;
		printf("RESULTADO: %d\n\n", result);
	}
}
