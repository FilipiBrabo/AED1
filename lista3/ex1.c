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
	if (pos == 1){		
		insertNode(head, x);
	}else{
		pnode aux = *head;
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
}

void removePosX(pnode * head, int pos){
	if (*head == NULL){
		printf("Lista Vazia\n");
	} else if(pos == 1){
		pnode aux = *head;
		*head = (*head)->next;
		//free(aux);		
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
				//free(x);
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

pnode splitList(pnode *head){
	pnode current = *head;
	pnode list2 = NULL;
	int size = 0;
	while (current != NULL){
		current = current->next;
		size++;
	}
	//printf("%d \n", size);
	current = *head;
	if (size % 2 == 0){
		for (int i = 1; i < size/2; i++){
			current = current->next;
		}
		list2 = current->next;
		current->next = NULL;
	} else{
		for (int i = 0; i < size/2; i++){
			current = current->next;
		}
		list2 = current->next;
		current->next = NULL;
	}
	return list2;
}

void concatList(pnode *list1, pnode *list2){
	if (*list1 == NULL && *list2 == NULL){
		printf("Listas Vazias\n");
	} else if(*list1 != NULL && *list2 == NULL){
		printf("Lista 2 vazia\n");
	} else if (*list1 == NULL && *list2 != NULL){
		printf("Lista 1 vazias\n");
	} else {
		pnode temp = *list1;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = *list2;
	}
}
int main(int argc, char const *argv[])
{
	pnode head = NULL;
	pnode list2 = NULL;
	for (int i = 0; i < 11; i++){
		insertNode(&head, newNode(i));
	}

	for (int i = 11; i < 21; i++){
		insertNode(&list2, newNode(i));
	}
	//insertPosX(&head, newNode(654), 3);
	// removePosX(&head, 12);
	//invertList(&head);
	//list2 = splitList(&head);
	concatList(&list2, &head);

	//printList(&head);
	printList(&list2);
	return 0;
}