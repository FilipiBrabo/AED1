#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node *node;
struct s_node{
  int ra, nota;
  char *nome;
  node ant, prox;
};

//cria um novo nó e retorna ele
node newNode(int ra, int nota, char *nome){
  node x = (node) malloc(sizeof(struct s_node));
  
  if(x != NULL) {
    x->ra = ra;
    x->nota = nota;
    x->nome = nome;
    x->prox = NULL;
    x->ant = NULL;
  }
  return x;
}

//insere um no
void insertNode(node* lista, node x) {
  if (*lista == NULL){
  	*lista = x;
  	return;
  }
  node aux = *lista;
  for (; aux->prox != NULL; aux = aux->prox);
  if (aux->ra != x->ra){
    aux->prox = x;
    x->ant = aux;
  }else{
    aux->ra = x->ra;
    aux->nome = x->nome;
    aux->nota = x->nota;     
  }
}

//printa lista
void printList(node *lista) {
  if (*lista == NULL) return;
  node aux = *lista;
  while (aux != NULL){
    printf("[%d %s %d]\n", aux->ra, aux->nome, aux->nota);
    aux = aux->prox;
  }
}

//busca um ra na lista e mostra a posição (-1 se não existe)
void searchNode(node *head, int ra){
  if (*head  == NULL){
  	printf("Pos=-1\n");	
  	return;
  } 
  
  node aux = *head;
  int pos = 0;
  while(aux && aux->ra != ra){
    aux = aux->prox;
    pos++;
  }
  
  if (aux){  //nó existe
    printf("Pos=%d\n", pos);
  }else{  //nó não existe
    printf("Pos=-1\n");
  }
}

/*Compara 2 nós:
Campo:
	1 - Compara os RAs
	2 - Compara os nomes
*/
int compare(node a, node b, int campo) {
  if (campo == 1) {
    return a->ra > b->ra;
  }
  else {
    return strcmp(a->nome, b->nome);
  }
}

//Ordena a lista por inserção
long int insertionSort(node *head, int campo) {
  if (*head == NULL) return 0;
  long int comp = 0;
  node prevI, prevJ, nextI, nextJ;

  	for (node i = (*head)->prox; i != NULL; i = i->prox) {
	    node j = i->ant;
	    while (j != NULL && ++comp && compare(j, i, campo) > 0){
	      	j = j->ant;      
	    }
	  
		if (i->ant == j) continue;
		
		if (j){	//Nó anterior existe
			prevJ = j->ant;
			nextJ = j->prox;
			prevI = i->ant;
			nextI = i->prox;

			//insere o no i na posição j+1
			j->prox = i;      
			i->prox = nextJ;
			i->ant = j;
			nextJ->ant = i;

			prevI->prox = nextI;
			if (nextI){ //se existe o nó nextI
				nextI->ant = prevI;
			} 

		}else{	//Nó anterior igual a NULL(começo da lista);        
			nextJ = *head;
			prevI = i->ant;
			nextI = i->prox;

			//insere o no i na primeira posição da lista
			*head = i;
			i->prox = nextJ;
			i->ant = NULL;
			nextJ->ant = i;

			prevI->prox = nextI;
			if (nextI){	//se existe o nó nextI
				nextI->ant = prevI;
		  	}
		}

    //faz o i apontar para o nó certo para fazer a iteração
		i = prevI;

	}
  return comp;
}


//Ordena a lista por seleção
long int selectionSort(node *head, int campo){
  if (*head == NULL) return 0;
  
  node i = *head;
  long int comp = 0;
  node tmp;
  
	for (; i->prox != NULL; i = i->prox){     
	node min = i;
	node j = i->prox;    

		for (; j != NULL; j = j->prox){
			if (compare(min, j, campo) >  0){
			min = j;
			}
			comp++;
		}
		
		if (min != i){
			tmp = newNode(i->ra, i->nota, i->nome);

			i->ra = min->ra;
			i->nome = min->nome;
			i->nota = min->nota;

			min->ra = tmp->ra;
			min->nome = tmp->nome;
			min->nota = tmp->nota;

			free(tmp);
		}
		
	}	

	return comp;
}	

/*Ordena a lista: 
Algoritmos:
  1: Ordenação por seleção
  2: Ordenação por inserção
Campo chave:
  1: RA
  2: Nome
*/
long int ordenaLista(int algoritmo, int campo, node* head){
  if (*head == NULL) return 0;  
  long int comp;  //número de comparações
  
  if (algoritmo == 1){  //Ordenação por seleção
    comp = selectionSort(head, campo);
  }else if (algoritmo == 2){  //Ordena por inserção
    comp = insertionSort(head, campo);  
  }
  
  return comp;
}

//deleta lista
void deleteList(node *head){
	if (*head == NULL) return;

	node aux = *head;
	node tmp;
	while (aux != NULL){
		tmp = aux;
		aux = aux->prox;
		free(tmp);
	}

	*head = NULL;
}

int main(int argc, char const *argv[])
{
  char op;
  node lista = NULL;
  while (scanf("\n%c", &op) != -1) {
    int ra, nota, alg, cam;
    char *nome = malloc(51 * sizeof(char));
    switch (op) {
      case 'I':
        scanf("%d %s %d", &ra, nome, &nota);
        insertNode(&lista, newNode(ra, nota, nome));
      break;
      case 'O':
        scanf("%d %d", &alg, &cam);
        printf("Comparacoes=%ld\n", ordenaLista(alg, cam, &lista));
      break;
      case 'B':
        scanf("%d", &ra);
        searchNode(&lista, ra);
      break;
      case 'M':
        printList(&lista);
      break;
      case 'P':
        deleteList(&lista);
        return 0;
      break;
    }
  }
}