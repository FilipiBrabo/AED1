#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;
struct s_no{
	int ra, nota;
	no prox;
};

void check();
void test(no );
no novoNo(int ra, int nota);
void insereFinal(no *head, no *ultimo, no x);
void printList(no head);
int comp(int ra_1, int ra_2, int ordem);
void mergeSort(no *head, int qtd, int ordem);
void merge(no *head_1, no head_2, int ordem);


int main() {
  no head = NULL, ultimo = NULL;
  int op, qtd = 0;
  while (scanf("%d", &op) != -1) {
    if (op == 1) {
      int ra, nota;
      scanf("%d %d", &ra, &nota);
      insereFinal(&head, &ultimo, novoNo(ra, nota));
      qtd++;
    }
    else if (op == 2) {
      	printList(head);
    }
    else if (op == 6) {
    //printf("Last:%d\n", qtd);
		mergeSort(&head, qtd, 0);
      	//printf("ok\n");
    }
    else if (op == 9) {
		mergeSort(&head, qtd, 1);
		//printf("ok2\n");
    }
    else if (op == 0) {
		//freeList(&head);
		return 0;
    }
    else if (op == 3){
    	test(head);
    	printf("\n");
    }
  }
}

void check() {
  printf("check\n");
}

void test(no head) {
  if (head == NULL) return;
  printf("%p = (%d, %d), -> %p", head, head->ra, head->nota, head->prox);
  test(head->prox);
}

//cria um novo nó
no novoNo(int ra, int nota){
	no x = malloc (sizeof(struct s_no));
	if (!x) return NULL;
	
	x->ra = ra;
	x->nota = nota;

	return x;
}

//insere no final da lista
void insereFinal(no *head, no *ultimo, no x){
	if (*head == NULL){
		*head = x;
		*ultimo = x;
	
	}else{
		(*ultimo)->prox = x;
    *ultimo = x;
	}
}

//imprime lista
void printList(no head){
  printf("[LISTA]\n");
	while (head){
		printf("[%d %d]\n", head->ra, head->nota);
		head = head->prox;
	}
}


int comp(int ra_1, int ra_2, int ordem){
  return ordem ? ra_1 > ra_2 : ra_1 < ra_2;
}

void mergeSort(no *head_1, int qtd, int ordem){
  if (qtd <= 1) return;

  no head_2 = *head_1, ultimo_1;
  int mid = qtd/2;
  for (int i = 0; i <= mid; i++){
    if (head_2->prox != NULL){
      ultimo_1 = head_2;
      head_2 = head_2->prox;
    }    
  }
  ultimo_1->prox = NULL;
  //printf("LISTA1:\n");
  //printList(*head_1);
  //printf("LISTA2:\n");
  //printList(head_2);

  mergeSort(head_1, mid, ordem);
  mergeSort(head_1, qtd-mid, ordem);
  check();
  merge(head_1, head_2, ordem);

}

//Ordena a lista em head_1 com a lista em head_2, e sava no endereço de head_1
void merge(no *head_1, no head_2, int ordem){
  no aux1 = *head_1, tmp1, tmp2, aux2 = head_2, ultimo = NULL;
  
  *head_1 = ultimo; //inicializando a lista ordenada
  
  while (aux1 && aux2){
    tmp2 = aux2;
    while (aux1 && comp(aux1->ra, aux2->ra, ordem)){ //Já está na ordem certa      
      tmp1 = aux1;
      if (!ultimo){ //adicionar o primeiro nó
        *head_1 = aux1;
        ultimo = *head_1;
        aux1 = aux1->prox;
      }else{
        aux1 = aux1->prox;
        ultimo->prox = tmp1;
      }
    
    }//Tem que ordenar
    if (aux1){
      if (!ultimo){ //adicionar o primeiro nó
          *head_1 = aux2;
          ultimo = *head_1;
          aux2 = aux2->prox;
      }else{
        aux2 = aux2->prox;
        ultimo->prox = tmp2;        
      }
    }
  }

  if (aux1){  //lista 1 existe
    while(aux1){
      tmp1 = aux1;
      aux1 = aux1->prox;
      ultimo->prox = tmp1;
    }
  }else{
    while(aux2){
      tmp2 = aux2;
      aux2 = aux2->prox;
      ultimo->prox = tmp2;
    }
  }
}
