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

pTreeNode insert(pTreeNode root, int RA, int nota){
	if (root == NULL)
		return newTreeNode(RA, nota);

	if (RA < root->RA){
		root->left = insert(root->left, RA, nota);
	}else if (RA > root->RA){
		root->right = insert(root->right, RA, nota);
	}
	return root;
}

int cont = 0;

pTreeNode searchRA(pTreeNode root, int RA){
	if (root == NULL){
		cont++;
		printf("C=%d Nota=-1\n", cont);
		cont = 0;
		return NULL; 
	}
	if (root->RA == RA){
		cont++;
		printf("C=%d Nota=%d", cont, root->nota);
		cont = 0;
		return root;
	}else if(RA < root->RA){
		cont++;		
		return searchRA(root->left, RA);
	}else{
		cont++;		
		return searchRA(root->right, RA);
	}

}

int height = -1;
pTreeNode showHeight(pTreeNode root){
	

}

//search the previous node to that RA
pTreeNode previous;
pTreeNode searchPrevious(pTreeNode root, int RA){	
	if (root == NULL){
		return NULL; 
	}
	if (root->RA == RA){
		return NULL;
	}else if(RA < root->RA){
		previous = root;
		return searchPrevious(root->left, RA);
	}else{
		previous = root;
		return searchPrevious(root->right, RA);
	}


}

pTreeNode searchRightSmaller(pTreeNode x){
	pTreeNode previous_aux;
	if (x == NULL){
		previous_aux = x;
		return x;
	}else{
		previous_aux = x;
		return searchRightSmaller(x->left);
	}
}

pTreeNode removeTreeNode(pTreeNode root, int RA){
	root = searchPrevious(root, RA);
	if (root->right->RA == RA){
		pTreeNode tmp = root->right;
		
		if (tmp->right == NULL && tmp->left == NULL){
			root->right = NULL;
			free(tmp);
		}else if (tmp->right == NULL && tmp->left != NULL){
			root->right = tmp->left;
			free(tmp);
		}else if(tmp->right != NULL && tmp->left == NULL){
			root->right = tmp->right;
			free(tmp);
		}else{
			pTreeNode smaller = searchRightSmaller(tmp);
			tmp->RA = smaller->RA;
			removeTreeNode(root);
		}
	}else if (root->left->RA == RA){
		pTreeNode tmp = root->left;
		
		if (tmp->right == NULL && tmp->left == NULL){
			root->left = NULL;
			free(tmp);
		}else if (tmp->right == NULL && tmp->left != NULL){
			root->left = tmp->left;
			free(tmp);
		}else if(tmp->right != NULL && tmp->left == NULL){
			root->left = tmp->right;
			free(tmp);
		}else{
			pTreeNode smaller = searchRightSmaller(tmp);
			tmp->RA = smaller->RA;
			removeTreeNode(tmp->left, RA);
		}
	}
}


int main(int argc, char const *argv[])
{
	char op; //operation
	int flag = 1, RA, nota;
	pTreeNode root = NULL;

	while(scanf("\n%c", &op) && op != 'P'){
		switch(op){
			case('I'):
				scanf("%d %d", &RA, &nota);
				if (flag == 1){
					root = insert(root, RA, nota);
					flag = 0;
				}else{
					insert(root, RA, nota);
				}
				break;

			case('R'):
				scanf("%d", &RA);
				removeTreeNode(root, RA);
				break;

			case('B'):
				scanf("%d", &RA);
				searchRA(root, RA);
				//printf("%d\n", previous->RA);
				break;

			case('A'):
				showHeight(root);
				break;
		}
	}
	return 0;
}