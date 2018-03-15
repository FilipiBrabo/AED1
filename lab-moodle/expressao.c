#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * pnode;
typedef struct node node;
struct node{
	double item;
	pnode next;
};

pnode createNode(double item){
	pnode x = malloc (sizeof(node));

	if (x == NULL){
		return NULL;
	}
	x->item = item; 
	x->next = NULL;
}

void insertNode(pnode *topo, pnode x){
	x->next = *topo;
	*topo = x;
}

void operacaoH(pnode *topo){
	(*topo)->item = 3*((*topo)->item);

}

void operacaoMais(pnode *topo){
	//atribuição dos nodes as variáveis n1, n2, para facilitar a visualização
	pnode n2 = *topo;
	pnode n1 = n2->next;

	//faz a operação
	double aux = n1->item;
	aux += n2->item;
	
	//libera os nodes que não serão mais utilizados e atualiza o valor do *topo
	pnode temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	(*topo)->item = aux;
}

void operacaoMenos(pnode *topo){
	//atribuição dos nodes as variáveis n1, n2, para facilitar a visualização
	pnode n2 = *topo;
	pnode n1 = n2->next;

	//faz a operação
	double aux = n1->item;
	aux -= n2->item;
	
	//libera os nodes que não serão mais utilizados e atualiza o valor do *topo
	pnode temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	(*topo)->item = aux;
}

void operacaoF(pnode *topo){
	//atribuição dos nodes as variáveis n1, n2, n3, para facilitar a visualização
	pnode n3 = *topo;
	pnode n2 = (*topo)->next;
	pnode n1 = n2->next;

	//faz a operação
	double aux = (n1->item)*(n1->item);
	aux -= (n2->item)/2;
	aux += n3->item;

	//libera os nodes que não serão mais utilizados e atualiza o valor do *topo
	pnode temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	(*topo)->item = aux;

}

void operacaoG(pnode *topo){
	//atribuição dos nodes as variáveis n1, n2, n3, para facilitar a visualização
	pnode n3 = *topo;
	pnode n2 = (*topo)->next;
	pnode n1 = n2->next;

	//faz a operação
	double aux = n1->item * n2->item;
	aux += n3->item;
	
	//libera os nodes que não serão mais utilizados e atualiza o valor do *topo
	pnode temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	temp = *topo;
	*topo = (*topo)->next;
	free(temp);
	(*topo)->item = aux;

}

//retorna 1 se existirem os 2 números para realiza a operação, 0 caso contrário
int verifica2(pnode *topo){
	pnode temp = *topo;
	int x = 1, cont = 0;
	while (cont < 2){
		if (temp == NULL){
			x = 0;
			return x;
		}else{
			temp = temp->next;
			cont++;
		}
	}
	return x;
	
}

//retorna 1 se existirem os 3 números para realiza a operação, 0 caso contrário
int verifica3(pnode *topo){
	pnode temp = *topo;
	int x = 1, cont = 0;
	while (cont < 3){
		if (temp == NULL){
			x = 0;
			return x;
		}else{
			temp = temp->next;
			cont++;
		}
	}
	return x;
}

/*Verifica se não há numeros sobrando na pilha, senão houver imprime o valor
do único nó*/
void printResult(pnode *topo){
	if ((*topo)->next != NULL){
		printf("ERRO\n");
	}else{
		printf("%.2lf\n", (*topo)->item);
	}
}

int main(int argc, char const *argv[]){
	char * expr;
	pnode topo = NULL;
	int i = 0, x, checkOp = 0;		
	
	scanf("%s", expr);
	while (*(expr + i) != '\0'){	
		char a = *(expr + i);
		if (a >= 48 && a <= 57){		
			insertNode(&topo, createNode(a - 48));
		}else {
			switch (a){
				case 'h':
					checkOp = 1;
					if (topo == NULL){
						printf("ERRO");
						return 0;
					}
					operacaoH(&topo);
					//desempilha(&topo);
					break;
				
				case '+':
					checkOp = 1;
					x = verifica2(&topo);
					if (x == 1){
						operacaoMais(&topo);
					}else{
						printf("ERRO\n");
						return 0;
					}
					break;

				case '-':
					checkOp = 1;
					x = verifica2(&topo);
					if (x == 1){
						operacaoMenos(&topo);
					}else{
						printf("ERRO\n");
						return 0;
					}
					break;

				case 'f':
					checkOp = 1;
					x = verifica3(&topo);
					if (x == 1){
						operacaoF(&topo);
					}else{
						printf("ERRO\n");
						return 0;
					}
					break;

				case 'g':
					checkOp = 1;
					x = verifica3(&topo);
					if (x == 1){
						operacaoG(&topo);
					}else{
						printf("ERRO\n");
						return 0;
					}
					break;

				default:
					printf("ERRO\n");
					return 0;
			}
		}

		i++;
	}
	//verifica se houve ao menos uma operação
	if (checkOp == 1){
		printResult(&topo);
	}else{
		//verifica se há um elemento na pilha
		if (topo != NULL){
			printResult(&topo);
		}else{
			printf("ERRO\n");
		}
	}	

	return 0;
}