#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int k, M, *seq, cont, *subSeq = 0, aux;

	scanf("%d", &k); //Tamanho max da sub-sequencia
	scanf("%d", &M); //Quantidade de números da sequência

	//Alocação da memória da sequência
	seq = (int *) malloc(M * sizeof(int));
	
	//Leitura da sequência de tamanho M
	for (int i = 0, i < M, i++){
		scanf("%d", seq+i);
		if (i > 0){
			if (cont < k){
				if (*(seq+i) == *(seq+i-1)){
					if (i == 1){
						*(subSeq + cont) = *(seq + i);
						cont++;	
					}
					*(subSeq + cont) = *(seq + i);
					cont++; 
				}else if ()
			} 
		}
	}
	
	]/*aux = *seq;
	while (cont < k){		
		if (aux + 1 == *(seq + 1 + cont){
			*(subSeq + cont) = aux;
			cont++;
			aux = *(seq + cont);
		} else if {cont > 0 && 

		}
	}*/

	return 0;
}