#include <stdio.h>

int main(){
	float soma, pesos[3] = {0,0,0};
	int erro, i, j, input1, input2, epocas, resposta;
	const int dados[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};
	
	//epocas
	fputs("epocas: ", stdout);
	scanf("%d", &epocas);

	//treinamento
	for(i = epocas; i--;)
		for(j = 4; j--;){
			//soma pesos sinapticos e inputs
			soma = 0;
			soma = -1*pesos[0] + dados[4 - j][0]*pesos[1] + dados[4 - j][1]*pesos[2];

			//funcao de ativacao (degrau)
			if(soma > 0) resposta = 1;
			else resposta = 0;

			//calcula o erro
			erro = dados[4 - j][2] - resposta;

			//atualiza os pesos
			if(erro){
				pesos[0] = pesos[0] + 0.5*erro*(-1);				
				printf("erro: %d - input: %d - peso: %f\n", erro, -1, pesos[0]); 
				pesos[0] = pesos[0] + 0.5*erro*dados[4 - j][0];
				printf("erro: %d - input: %d - peso: %f\n", erro, dados[4 - j][0], pesos[1]); 
				pesos[0] = pesos[0] + 0.5*erro*dados[4 - j][1];
				printf("erro: %d - input: %d - peso: %f\n", erro, dados[4 - j][1], pesos[2]); 
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
		soma = -1*pesos[0] + input1*pesos[1] + input2*pesos[2];
		if(soma > 0) resposta = 1;
		else resposta = 0;
		printf("\nRESULTADO: %d\n", resposta);
	}
}
