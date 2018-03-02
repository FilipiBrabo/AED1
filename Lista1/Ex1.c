#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int k, M, *seq, cont = 0, aux;

	scanf("%d", &M); //Tamanho max da sub-sequencia
	scanf("%d", &k); //Quantidade de números da sequência

	//Alocação da memória da sequência
	seq = (int *) malloc(M * sizeof(int));
	
	//Leitura da sequência de tamanho M
	for (int i = 0; i < M; i++){
		scanf("%d", seq+i);
	}

	for (int i = 0; i <= M; i++){
		if (cont  == k){
			aux = cont;
			for (aux; aux > 0; aux--){
				printf("%d ", *(seq+i-aux));
			}
			printf("\n");
			while(*(seq+i)+1 == *(seq+i+1)){
				aux = cont;
				i++;
				for (aux; aux > 0; aux--){
			 	printf("%d ", *(seq+i-aux));
				}
				printf("\n");			
			}
			cont == 0;
		}
		else if(*(seq+i)+1 == *(seq+i+1)) cont++;
		else if(cont > 0){
			for (cont; cont >= 0; cont--){
				printf("%d ", *(seq+i-cont));
			}
			printf("\n");
		}
	}

	return 0;
}

//fazer loop para ver se os prox k numeros são sub seq 