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

//insere nó x na árvore
void insere(noArv * raiz, noArv x){
	if ((*raiz) == NULL){
		*raiz = x;
	}
	//vai para direita
	if (x->ra > (*raiz)->ra){
		insere(&(*raiz)->dir, x);
	//vai para esquerda
	}else if (x->ra < (*raiz)->ra){
		insere(&(*raiz)->esq, x);
	//RA igual
	}else{
		(*raiz)->nota = x->nota;
	}
}

//remove nó com ra informado
void remove(noArv * raiz, int ra){
	if (*raiz == NULL) return;
	
	//acha o nó a ser removido
	if (ra > atual->ra){ 	//vai pra sub arvore da direita
		remove(&(*raiz)->dir, ra);	
	}else if (ra < atual->ra){	//vai pra sub arvore da esquerda
		remove(&(*raiz)->dir, ra);
	}else{	//achei o nó
		noArv atual = *raiz;	//auxiliar

		if((*raiz)->dir && (*raiz)->esq){	//tem os dois filhos 
		
		}else{	//tem no máx um filho
			if (*(raiz)->dir){	//tem o filho da direita
				(*raiz) = (*raiz)->dir;
				free(atual); 
			
			}else if ((*raiz)->esq){	//tem o filho da esquerda
				
			}	
		}
}


int main(int argc, char const *argv[])
{
	char operation;
	int ra, nota;
	noArv raiz = NULL;

	while(1){
		scanf("%c", &operation);
		switch(operation){
			case('I'):
				scanf("%d %d", &ra, &nota);
				insere(&raiz, novoNoArv(ra, nota));
				break;
			case('R'):
				//remove();
				break;
			case('B'):
				//buscaNo();
				break;
			case('A'):
				//alturaArvore();
			case('T'):
				teste(&raiz, 0);
				break;
			case('P'):
				//imprimePosOrdem();
				return 0;
				break;
		}
	}
}