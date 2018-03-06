#include <stdio.h>
#include <stdlib.h>

typedef struct node * pnode;
typedef struct node node;
struct node{
	int item;
	pnode next;
};

pnode newNode(int item){
	pnode x = malloc (sizeof(node));
	if (x == NULL){
		printf("Mem. insulficiente");
		return NULL;
	}

	x->item = item;
	x->next = NULL;
}

void insertNode (pnode *head, pnode x){
	x->next = *head;
	*head = x;
}

void printList(pnode *head){
	pnode x;
	for (x = *head; x != NULL; x = x->next)
		printf("%d ", x->item);
	printf("\n");
}

void insertPosX(pnode * head, pnode x, int pos){
	pnode aux = *head;
	if (pos == 1){		
		x->next = *head;
		*head = x;
		free(aux);
	}
	for (int i = 2; i < pos; i++){
		if (aux == NULL)
			printf("Não existe essa posição\n");
		else{
			aux = aux->next;
		}
	}
	if (aux == NULL){
		printf("Escolha um posição válida\n");
	} else{
		x->next = aux->next;
		aux->next = x;
	}
}

void removePosX(pnode * head, int pos){
	if (*head == NULL){
		printf("Lista Vazia\n");
	} else if(pos == 1){
		pnode aux = *head;
		*head = (*head)->next;
		free(aux);		
	} else{
		pnode aux = *head;
		for (int i = 2; i < pos; i++){
			if (aux == NULL){
				printf("Não existe essa posição\n");
			} else {
				aux = aux->next;
			}
		}
		if (aux != NULL){
			pnode x = aux->next;
			if (x == NULL){
			printf("Não existe nó nesta posição\n");
		}	 else if (x->next == NULL){
				free(x);
				aux->next = NULL;
		} 	else{
				aux->next = x->next;
				free(x);
			}
	 	}
	}
}

void invertList(pnode *head){
	pnode current = *head;
	pnode prev = NULL;
	pnode next;
	while (current != NULL){
		next = current->next;
		current->next=prev;
		prev = current;
		current = next;
	}
	*head = prev;	
}


int main(int argc, char const *argv[])
{
	pnode head = NULL;
	for (int i = 0; i < 10; i++){
		insertNode(&head, newNode(i));
	}

	insertPosX(&head, newNode(654), 1);
	// removePosX(&head, 12);
	//invertList(&head);

	printList(&head);
	return 0;
}