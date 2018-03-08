/* Este é um exercício de lista circular*/

#include <stdlib.h>
#include <stdio.h>


typedef struct node * pnode;
typedef struct node node;
struct node{
	int item;
	pnode next;
};

pnode createNode(int item){
	pnode x = malloc (sizeof(node));
	x->item = item;
	x->next = NULL;
}

void insertNode(pnode *head, pnode x, pnode *last){
	if (*head == NULL){
		*head = x;
		*last = x;
	} else{
		x->next = *head;
		*head = x;
		(*last)->next = *head;
	}
}

void printList(pnode *head){
	pnode temp = *head;
	do {
		printf("%d ", temp->item);
		temp = temp->next;
	} while(temp != *head);
	
	printf("\n");
}

void removeLastElement(pnode *head, pnode *last){
	pnode temp = *head;
	if (temp->next == NULL){
		free(temp);
		*head == NULL;
		printf("Sua lista possuia apenas um elemento\n");
	}
	while (temp->next != *last){
		temp = temp->next;
	}
	temp->next = (*last)->next;
	free(*last);
}

int main(int argc, char const *argv[])
{
	pnode head = NULL;	
	pnode last = NULL; 
	for (int i = 0; i < 10; i++){
		insertNode(&head, createNode(i), &last);
	}
	printList(&head);
	removeLastElement(&head, &last);
	printList(&head);
	return 0;
}