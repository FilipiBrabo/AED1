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

pnode searchRA(pnode *head, int RA){
	if (*head == NULL){
		return NULL;
	}
	else{
		pnode temp = malloc(sizeof(node));
		temp = *head;
		while (temp != NULL && temp->RA != RA){
			temp = temp->next;
		}
		if (temp == NULL){			
			return NULL;
		} else{			
			pnode aux = malloc(sizeof(node));
			aux = temp->next;
			while(aux != NULL && aux->RA == RA){
				temp = temp->next;
				aux = aux->next;
			}
			return temp;
		}
			
	}
}

void appendNodeRA(pnode x, pnode y){//X é o ultimo nó com o RA, y é o nó a ser colocado
	pnode aux = malloc(sizeof(node));
	aux = x->next;
	x->next = y;
	y->next = aux;
}

int main(int argc, char const *argv[])
{
	pnode head = NULL;
	int RA, CodTopico;
	scanf("%d %d", &RA, &CodTopico);
	while (RA != -1 && CodTopico != -1){
		pnode x = newNode(RA, CodTopico);
		pnode aux = malloc(sizeof(node));
		
		aux = searchRA(&head, RA);
		if (aux == NULL){
			appendNode(&head, x);
		}else{
			appendNodeRA(aux, x);
		}

		scanf("%d %d", &RA, &CodTopico);
	}
	printList(&head);

	return 0;
}