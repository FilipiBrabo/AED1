// Completar em casa (Soma e Produto das listas caso forem iguais)
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n,m; //tamanho
	scanf("%d", &n);
	scanf("%d", &m);

	int maiorSeq = (n > m ? n : m); // Descobre a maior seq

	int maior = 0;
	// 0: iguais
	// 1: seq A é maior
	// 2: seq B é maior	

	for(int i = 0; i < maiorSeq; i++){
		
		float a;
		if (i < n){
			printf("Digite o elemento %d da seq A:", i+1);
			scanf("%f", &a);	
		}

		float b;
		if (i < m){
			printf("Digite o elemento %d da seq B:", i+1);
			scanf("%f", &b);
		}
		
		if(maior == 0){
			if (i >= n){
				maior = 2;
			} else if (i >= m){
				maior = 1;
			}
			if (a > b){
				maior = 1;
			} else if (b > a){
				maior = 2;
			}
		}
	}

	switch (maior) {
		case 0: printf("São iguais\n"); break;
		case 1: printf("A é maior!\n"); break;
		case 2: printf("B é maior!\n"); break;
	}
	return 0;
}