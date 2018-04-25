#include <stdio.h>
#include <stdlib.h>

typedef struct linkedNode linkedNode;

struct linkedNode {
  int ra, nota;
  linkedNode* next;
};
void check() {
  printf("check\n");
}
void test(linkedNode *list) {
  if (list == NULL) return;
  printf("%p = (%d, %d), -> %p", list, list->ra, list->nota, list->next);
  test(list->next);
}

//Cria e retorna o nó
linkedNode* newNode(int ra, int nota){
  linkedNode* x = malloc(sizeof(linkedNode));
  x->ra = ra;
  x->nota = nota;
  x->next = NULL;
  return x;
}

//Imprime a lista
void printList(linkedNode *ini){
  printf("[LISTA]\n");
  for(;ini != NULL;ini = ini->next){
    printf("[%d %d]\n", ini->ra, ini->nota);
  }
}

//Insere nó na ultima posição da lista
void insertNode(linkedNode **head, linkedNode **last, linkedNode *x){
  if (*head == NULL){
  	*head = x;
  	*last = x;
  }
  (*last)->next = x;
  *last = x;
}

//Remove o primeiro nó de uma lista
linkedNode* removeNode(linkedNode **head) {
  linkedNode *x = *head;
  (*head) = (*head)->next;
  return x;
}

/*Compara dois números.
comp:
  0 - Crescente
  1 - Decrescente
*/
int comp(int ra_1, int ra_2, int compare){
  return compare ? ra_1 > ra_2 : ra_1 < ra_2;
}

void merge(linkedNode **head_1, linkedNode **head_2, linkedNode **last, int compare){
  linkedNode *aux1 = *head_1, *aux2 = *head_2, *listAux;
  //check();
  while (aux1 != *head_2 && aux2 != NULL){
  	//printf("%d\n", comp(aux1->ra, aux2->ra, compare)); 
  	if (comp(aux1->ra, aux2->ra, compare)){
  		listAux = aux2;
  		aux2->next = aux1;
  		aux2->next = NULL;
  		
  		aux1 = aux1->next;
  		aux2 = aux2->next;
  		printf("%d\n", listAux->ra);
  		printf("%d\n", listAux->next->ra);
  		printf("Head2:%d\n", (*head_2)->ra);	  
	}
  }

  if (aux1){

  }else{

  }
}


void mergeSort(linkedNode** head_1, linkedNode* last, int qtd, int compare){
  if (qtd <= 1) return;

  linkedNode **head_2 = head_1, *last_2, *last_1;
  int mid = qtd/2;
  last_2 = last;
  // printf("%d %d\n", qtd, mid);
  for (int i = 0; i <= mid; i++){
  	 	
  	if ((*head_2)->next != NULL){
  		last_1 = *head_2;
    	head_2 = &(*head_2)->next;
  	}  	
  }
  
//   printf("qtd = %d ------------------------------------\n", qtd);
//   test(*head_1);
//   printf("---------------------------------------------\n");
  mergeSort(head_1, last_1, mid, compare);
  mergeSort(head_2, last_2, qtd-mid, compare);
  
  merge(head_1, head_2, &last, compare);
}

//Deleta uma lista
void freeList(linkedNode **head){
  if (*head == NULL) return;

  linkedNode *aux = *head;
  while (*head != NULL){
    aux = *head;
    *head = (*head)->next;
    free(aux);
  }
}

int main() {
  linkedNode *list = NULL, *last = list;
  int op, qtd = 0;
  while (scanf("%d", &op) != -1) {
    if (op == 1) {
      int ra, nota;
      scanf("%d %d", &ra, &nota);
      insertNode(&list, &last, newNode(ra, nota));
      qtd++;
    }
    else if (op == 2) {
      	printList(list);
    }
    else if (op == 6) {
    //printf("Last:%d\n", qtd);
		mergeSort(&list, last, qtd, 0);
      	//printf("ok\n");
    }
    else if (op == 9) {
		mergeSort(&list, last, qtd, 1);
		//printf("ok2\n");
    }
    else if (op == 0) {
		freeList(&list);
		return 0;
    }
    else if (op == 3){
    	test(list);
    	printf("\n");
    }
  }
}
