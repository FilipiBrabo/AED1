#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode * pTreeNode;
typedef struct TreeNode TreeNode;
struct TreeNode{
	int RA;
	TreeNode *pLeft, *pRight;
}; 

typedef struct node * pnode;
typedef struct node node;
struct node{
	int RA;
	pnode next;
};

pnode newNode(int RA){
	pnode x = malloc (sizeof(node));
	if (x == NULL){
		return NULL;
	}
	x->RA = RA;
	x->next = NULL;
}

void insertNodeList(pnode* head, pnode x){
	pnode atual = *head;
	if (atual == NULL){
		x->next = *head;
		*head = x;
	}else{
		pnode prox = atual->next;
		while (prox != NULL && x->RA >= prox->RA){
			atual = prox;
			prox = prox->next;
		}
		if(x->RA < atual->RA){
			x->next = atual;
			*head = x;		
		}else if(x->RA > atual->RA){
			atual->next = x;
			x->next = prox;
		}
		
	}
}

int searchRAList(pnode *head, int RA){
	if (*head == NULL){
		return 0;
	}
	else{
		int cont = 1;
		pnode aux = *head;
		if (RA < aux->RA){
			return 1;
		}
		while (aux != NULL && aux->RA != RA && aux->RA < RA){
			cont++;
			aux = aux->next;
		}
		if (aux == NULL){
			return cont-1;
		}else{
			return cont;
		}
	}

}

void printList(pnode *head){
	pnode x;
	for (x = *head; x != NULL; x = x->next)
		printf("%d ", x->RA);
	printf("\n");
}

pTreeNode newTreeNode(int RA){
	pTreeNode tmp = malloc(sizeof(TreeNode));
	tmp->RA = RA;
	tmp->pLeft = tmp->pRight = NULL;
	return tmp;
}

pTreeNode insertTreeNode(pTreeNode raiz, int RA){
	if (raiz == NULL){
		return newTreeNode(RA);
	}
	if (RA < raiz->RA){
		raiz->pLeft = insertTreeNode(raiz->pLeft, RA);
	}else if (RA > raiz->RA){
		raiz->pRight = insertTreeNode(raiz->pRight, RA);
	}
		
	return raiz;
	
}

int contTree;
pTreeNode searchRATree(pTreeNode raiz, int RA){
	if (raiz == NULL){
		return raiz;
	}
	if (raiz->RA == RA){
		contTree++;
		return raiz;
	}
	
	if (raiz->RA < RA){
		contTree++;
		return searchRATree(raiz->pRight, RA);
	}
	else{
		contTree++;
		return searchRATree(raiz->pLeft, RA);
	}
	
}

int main(int argc, char const *argv[])
{
	pnode head = NULL;
	pTreeNode raiz = NULL, tmp;
	char op;
	int RA, contList, flag = 1;
	while (scanf("%c %d", &op, &RA) && (op != 'P' || RA != 0)){
		switch (op){
			case ('I'):
			insertNodeList(&head, newNode(RA));
			if (flag = 1){
				flag = 0;
				raiz = insertTreeNode(raiz, RA);
			}else{
				insertTreeNode(raiz, RA);
			}
			//printList(&head);
			break;

			case ('B'):
			contList = searchRAList(&head, RA);
			contTree = 0;
			searchRATree(raiz, RA);
			printf("L=%d A=%d\n", contList, contTree);
	
			break;
		}
	}
	return 0;
}