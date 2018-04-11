#include <stdio.h>
#include <stdlib.h>

typedef struct node * pnode;
typedef struct node node;
struct node{
	int RA; 
	int CodTopico;
	node *next;

};

pnode newNode(int RA, int CodTopico){
	pnode x = malloc(sizeof(struct node));

	if (x == NULL){
		return NULL;
	}
	x->RA = RA;
	x->CodTopico = CodTopico;
	x->next = NULL;

	return x;
}

void appendNode(pnode *head, pnode x){
	if (*head == NULL){
		*head = x;
	} else{
		pnode temp = malloc(sizeof(node));
		temp = *head;
		while(temp->next != NULL){
			temp = temp ->next;
		}
		temp->next = x;
	}
}

void printList(pnode *head){
	pnode temp = malloc(sizeof(node));
	temp = *head;
	while(temp != NULL){
		printf("%d %d\n", temp->RA, temp->CodTopico); 
		temp = temp->next;
	}
}


int main(int argc, char const *argv[])
{
	pnode head = NULL;
	int RA, CodTopico;
	scanf("%d %d", &RA, &CodTopico);
	while (RA != -1 && CodTopico != -1){
		pnode x = newNode(RA, CodTopico);
		appendNode(&head, x);
		
		
		//printf("Digite os valores de RA e CodTopico, -1 -1 para sair\n");
		scanf("%d %d", &RA, &CodTopico);
	}
	printList(&head);

	return 0;
}