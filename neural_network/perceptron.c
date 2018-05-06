#include <stdio.h>

int main(){
	float soma, pesos[3] = {0,0,0};
	int erro, i, input1, input2, epocas, resposta;
	const int dados[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};
	
	//epocas
	fputs("epocas: ", stdout);
	scanf("%d", &epocas);

	//treinamento
	for(epocas; epocas--;)
		for(i = 4; i--;){
			//soma pesos sinapticos e inputs(dados de treinamento)
			soma = 0;
			soma = pesos[0] + dados[i][0]*pesos[1] + dados[i][1]*pesos[2];

			//funcao de ativacao(degrau)
			if(soma > 0) resposta = 1;
			else resposta = 0;

			//calcula o erro
			erro = dados[i][2] - resposta;
			printf("erro data[%d]: %d\n", i, erro);

			//atualiza os pesos(bias and step values are equal to 1)
			if(erro){
				pesos[0] = pesos[0] + erro;				
				pesos[1] = pesos[1] + erro*dados[i][0];
				pesos[2] = pesos[2] + erro*dados[i][1];
			}
		}	
	puts("RESULTADO DO TREINAMENTO:");		
	printf("w[0] = %f\n", pesos[0]);
	printf("w[1] = %f\n", pesos[1]);
	printf("w[2] = %f\n", pesos[2]);
	//resultado dos inputs
	while(1){
		//inputs
		fputs("input1: ", stdout);
		scanf("%d", &input1);
		fputs("input2: ", stdout);
		scanf("%d", &input2);

		//resultado
		soma = 0;
		soma = pesos[0] + input1*pesos[1] + input2*pesos[2];
		if(soma > 0) resposta = 1;
		else resposta = 0;
		printf("RESULTADO: %d\n\n", resposta);
	}
}
