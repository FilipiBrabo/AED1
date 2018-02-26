#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int k, M, *seq;

	scanf("%d", &k); //Tamanho max da sub-sequencia
	scanf("%d", &M); //Quantidade de números da sequência

	//Alocação da memória da sequência
	seq = (int *) malloc(M * sizeof(int));
	
	//Leitura da sequência de tamanho M
	for (int i = 0, i < M, i++){
		scanf("%d", seq+i);
	}

	int 

	return 0;
}