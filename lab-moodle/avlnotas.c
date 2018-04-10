#include <stdio.h>
#include <stdlib.h>

typedef struct s_noArv * noArv;
struct s_noArv{
	int ra;
	int nota;
	noArv esq;
	noArv dir;
};

noArv novoNoArv(int ra, int nota){
	noArv tmp = (noArv) malloc (sizeof(struct s_noArv));
	
	if(!tmp){
		return NULL;
	}

	tmp->ra = ra;
	tmp->nota = nota;
	tmp->esq = NULL;
	tmp->dir = NULL;

	return tmp;
}

void insere(noArv * raiz, noArv x){
	if ((*raiz) == NULL){
		*raiz = x;
	}
	//vai para direita
	if (x->ra > (*raiz)->ra){
		insere(&(*raiz)->dir, x);
	//vai para esquerda
	}else if (x->ra < (*raiz->ra)){
		insere(&(*raiz)->esq, x);
	//RA igual
	}else{
		*(raiz)->nota = x->nota;
	}
}

int main(int argc, char const *argv[])
{
	char operation;
	NoArv raiz = NULL;

	while(1){
		switch(operation){
			case('I'):
				insere();
				break;
			case('R'):
				remove();
				break;
			case('B'):
				buscaNo();
				break;
			case('A'):
				alturaArvore();
			case('P'):
				imprimePosOrdem();
				break;
		}	
		return 0;
}