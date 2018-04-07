#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode * pTreeNode;
typedef struct treeNode treeNode;

struct treeNode{
	int RA;
	int nota;
	pTreeNode right, left;
};

pTreeNode newTreeNode(int RA, int nota){
	pTreeNode x = malloc (sizeof(treeNode));
	if (!x) return NULL;
	x->RA = RA;
	x->nota = nota;
	x->right = NULL;
	x->left = NULL;

	return x;
}

void insertTreeNode(pTreeNode *root, pTreeNode x){
	if (*root == NULL)
		*root = x;
	if (x->RA < (*root)->RA){ 			//Se o RA for menor vai pra esquerda
		insertTreeNode(&(*root)->left, x);
	}else if (x->RA > (*root)->RA){ 	//Se o RA for maior vai pra direita
		insertTreeNode(&(*root)->right, x);
	}else{ 								//RA igual
		(*root)->nota = x->nota;
	}	
}

int numIteracoes = 0;

pTreeNode searchRA(pTreeNode root, int RA){
	if (root == NULL){
		//numIteracoes++;
		printf("C=%d Nota=-1\n", numIteracoes);
		numIteracoes = 0;
		return NULL; 
	}
	if (root->RA == RA){
		numIteracoes++;
		printf("C=%d Nota=%d\n", numIteracoes, root->nota);
		numIteracoes = 0;
		return root;
	}else if(RA < root->RA){
		numIteracoes++;		
		return searchRA(root->left, RA);
	}else{
		numIteracoes++;		
		return searchRA(root->right, RA);
	}

}
int max(int a, int b){
	if (a > b){
		return a;
	}else{
		return b;
	}
}

int findHeight(pTreeNode root){
	if (root == NULL){
		return -1;
	}
	int leftHeight, rightHeight;

	leftHeight = findHeight(root->left);
	rightHeight = findHeight(root->right);
	return max(leftHeight, rightHeight) + 1;
}

void removeTreeNode(pTreeNode *root, int RA){
	pTreeNode tmp = *root;
	
	//acha o anterior do nó a ser removido
	pTreeNode prev = NULL;
	while (tmp && tmp->RA != RA){
		if (RA > tmp->RA){ //RA maior, vai para direita
			prev = tmp;
			tmp = tmp->right;
		}else{  			//RA menor, vai para esquerda
			prev = tmp;
			tmp = tmp->left;
		}
	}
	
	if (tmp){							//se existe o nó a ser removido				
		if (tmp->right && tmp->left){ 	//se existirem 2 filhos
			pTreeNode aux = NULL;
			//acha o menor a direita
			aux = tmp->right;
			while (aux->left){
				//prev = root;
				aux = aux->left;
			}
			
			tmp->RA = aux->RA;
			tmp->nota = aux->nota;
			
			removeTreeNode(&(tmp->right), aux->RA);

		}else{
			pTreeNode aux2 = NULL;			        //existe no max um filho
			if (tmp->right){				//existe o filho da direita
				aux2 = tmp->right;
			}else if (tmp->left){			//existe o filho da esquerda
				aux2 = tmp->left;
			}
		
			if(prev){ //se existe anterior(não estamos na raiz)
				
				//verificar se o nó está a esqueda ou a direita do anterior
				if (tmp->RA > prev->RA){
					prev->right = aux2;
				}else{
					prev->left = aux2;
				}
			}else{ //nó a ser removido é  a raiz
				*root = aux2;
			}
			free(tmp);
		}
	}

	
}

int main(int argc, char const *argv[])
{
	char op; //operation
	int RA, nota, height;
	pTreeNode root = NULL;

	while(scanf("\n%c", &op) && op != 'P'){
		switch(op){
			case('I'):
				scanf("%d %d", &RA, &nota);			
				insertTreeNode(&root, newTreeNode(RA, nota));
				break;

			case('R'):
				scanf("%d", &RA);
				removeTreeNode(&root, RA);
				break;

			case('B'):
				scanf("%d", &RA);
				searchRA(root, RA);
				//printf("%d\n", previous->RA);
				break;

			case('A'):
				height = findHeight(root);
				printf("A=%d\n", height);
				break;
		}
	}

	return 0;
}