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
void insereFinal(no *head, no ultmo, no x);
void printList(no head);
int comp(int ra_1, int ra_2, int ordem);
void mergeSort(no *head, no ultmo, int qtd);
void merge(no *head_1, no *head_2, ord)


int main() {
  no head = NULL, ultmo = NULL;
  int op, qtd = 0;
  while (scanf("%d", &op) != -1) {
    if (op == 1) {
      int ra, nota;
      scanf("%d %d", &ra, &nota);
      insertNode(&head, &ultmo, novoNo(ra, nota));
      qtd++;
    }
    else if (op == 2) {
      	printList(head);
    }
    else if (op == 6) {
    //printf("Last:%d\n", qtd);
		mergeSort(&head, ultmo, qtd, 0);
      	//printf("ok\n");
    }
    else if (op == 9) {
		mergeSort(&head, ultmo, qtd, 1);
		//printf("ok2\n");
    }
    else if (op == 0) {
		freeList(&head);
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
  printf("%p = (%d, %d), -> %p", head, head->ra, head->nota, head->next);
  test(head->next);
}

//cria um novo nó
no novoNo(int ra, int nota){
	no x = malloc (sizeof(struct s_no));
	if (!x) renturn NULL;
	
	x->ra = ra;
	x->nota = nota;

	return x;
}

//insere no final da lista
void insereFinal(no *head, no ultmo, no x){
	if (*head == NULL){
		*head = x;
		*last = x;
	
	}else{
		(*last)->prox = x;
	}
}

//imprime lista
void printList(no head){
	while (head){
		printf("[%d %d]\n", head->ra, head->nota);
		head = head->prox;
	}
}


int comp(int ra_1, int ra_2, int ordem){
  return ordem ? ra_1 > ra_2 : ra_1 < ra_2;
}

void mergeSort()