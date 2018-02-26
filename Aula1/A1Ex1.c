#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n; //tamanho
	scanf("%d", &n);

	int maior = 0;
	// 0: iguais
	// 1: seq A é maior
	// 2: seq B é maior	

	for(int i = 0; i<n; i++){
		printf("Digite o elemento %d da seq A:", i+1);
		float a;
		scanf("%f", &a);

		printf("Digite o elemento %d da seq B:", i+1);
		float b;
		scanf("%f", &b);

		if(maior == 0){
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