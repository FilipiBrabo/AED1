#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct node * pNode;
typedef struct mPointer mPointer;
typedef struct mPointer * pMPointer;

struct node{
	int item;
	int line;
	int collum;
	pNode nextInLine, nextInCollum;
}; 

struct mPointer{
	int index;
	pNode nextNode;
	pMPointer nextPointer;

};

struct matrix{
	pMPointer headLine;
	pMPointer headCollum;
};

pNode newNode(int item, int line, int collum){
	pNode x = malloc(sizeof(node));
	if (!x){
		return NULL;
	}
	x->item = item;
	x->line = line;
	x->collum = collum;
	x->nextInLine = NULL;
	x->nextInCollum = NULL;
}

pMPointer newMPointer(int index){
	pMPointer x = malloc(sizeof(mPointer));
	if (!x){
		return NULL;
	}
	x->index = index;
	x->nextNode = NULL;
	x->nextPointer = NULL;
}

void printMatrix(pMPointer * headLine, int num_line, int num_collum){
	if (*headLine == NULL) return;
	
	pMPointer tmp = *headLine;
	int contLine = 0;
	while (tmp){
		//printf("\ntmpindex: %d\n", tmp->index); 
		if (tmp->index == contLine){ //there's node in the line
			pNode atual = tmp->nextNode;
			//printf("atualcollum : %d", atual->collum);
			int contCollum = 0;
			
			printf("[");
			int i = 0;
			while (atual){
				for (i; i < atual->collum; i++){
					printf("0 ");
					contCollum++;
				}
				printf("%d ", atual->item);
				i++;
				contCollum++;
				atual = atual->nextInLine;
			}
			while (contCollum < num_collum){
				printf("0 ");
				contCollum++;
			}
			printf("]\n");
			tmp = tmp->nextPointer;
			contLine++;

		}else{ // line's empty
			printf("[");
			for (int i = 0; i < num_collum; i++){
			printf("0 ");
			}
			printf("]\n");
			//tmp = tmp->nextPointer;
			contLine++;
		}
	}
	while(contLine < num_line){
		printf("[");
			for (int i = 0; i < num_collum; i++){
			printf("0 ");
			}
			printf("]\n");
			contLine++;
	}
	
}

void insertNode(pMPointer * headLine, pMPointer * headCollum, int lineIndex, int collumIndex, int item){
	if (*headLine == NULL && *headCollum == NULL){ //Empty matrix
		//Create 2 head pointers and make head point to them;
		*headLine = newMPointer(lineIndex);
		*headCollum = newMPointer(collumIndex);
		
		//Create a new node
		pNode node = newNode(item, lineIndex, collumIndex);
		
		//Make head pointers point to the node;
		(*headLine)->nextNode = node;
		(*headCollum)->nextNode = node;

	}else{
		//Adding node to the line
		pNode node = newNode(item, lineIndex, collumIndex);
		pMPointer lineAux = *headLine;
		pMPointer collumAux = *headCollum;

		while (lineAux->nextPointer != NULL && lineAux->index < lineIndex){				
			if(lineAux->nextPointer->index < lineIndex){
				lineAux = lineAux->nextPointer;
			}else{
				break;
			}			
		}

		//if there's no pointer to this line, create the pointer and add the node
		if (lineAux->index != lineIndex){ 					
			pMPointer lineTmp = newMPointer(lineIndex);		
			pMPointer tmp = lineAux->nextPointer; 		//temporary pointer that points to the next head pointer
			
			//insert the new pointer into the matrix
			lineAux->nextPointer = lineTmp;				
			lineTmp->nextPointer = tmp;

			//insert the new node into the matrix;
			lineTmp->nextNode = node;
		}

		//insert in the first position
		else if (lineAux->nextNode->collum > collumIndex){
			pNode tmp = lineAux->nextNode;
			lineAux->nextNode = node;
			node->nextInLine = tmp;
		}

		//goes to the (position-1) and add the node
		else{
			pNode tmp = lineAux->nextNode;
			while (tmp->nextInLine != NULL){
				if (tmp->nextInLine->collum < collumIndex){
					tmp = tmp->nextInLine;
				}
				else{
					break;
				}
			}
			pNode aux = tmp->nextInLine;
			tmp->nextInLine = node;
			node->nextInLine = aux;			
		}

		//Adding node to the collum
		while (collumAux->nextPointer != NULL && collumAux->index < collumIndex){
			if (collumAux->nextPointer->index < collumIndex){
				collumAux = collumAux->nextPointer;
			}else{
				break;
			}
		}
		//if there's no pointer to this collum, create the pointer and add the node
		if (collumAux->index != collumIndex){					
			pMPointer collumTmp = newMPointer(collumIndex);		
			pMPointer tmp = collumAux->nextPointer; 			//temporary pointer that points to the next head pointer

			//insert the new pointer into the matrix
			collumAux->nextPointer = collumTmp;
			collumTmp->nextPointer = tmp;

			//inert the node into the matrix
			collumTmp->nextNode = node;
		}
		//insert the node in the first position
		else if (collumAux->nextNode->line > lineIndex){
			pNode tmp = collumAux->nextNode;
			collumAux->nextNode = node;
			node->nextInCollum = tmp;
		}
		//goes to the (position-1) and insert the node
		else{
			pNode tmp = collumAux->nextNode;
			while (tmp->nextInCollum != NULL){
				if (tmp->nextInCollum->line < lineIndex){
					tmp = tmp->nextInCollum;
				}
				else{
					break;
				}
			}
			pNode aux = tmp->nextInCollum;
			tmp->nextInCollum = node;
			node->nextInCollum = aux;
		}

	}
}

void multiplyMatrix(pMPointer * headLineA, pMPointer * headCollumB, int la, int ca, int lb, int cb){
	if (*headLineA == NULL || *headCollumB == NULL){
		printf("ERRO\n");
		return;
	}else if (ca != lb){
		printf("ERRO\n");
		return;
	}

	pMPointer lineA = *headLineA;
	pMPointer collumB = *headCollumB;

	struct matrix matrixR;
	matrixR.headLine = NULL;
	matrixR.headCollum = NULL;

	int contLine = 0, flag = 0;
	while (lineA){
		if (lineA->index == contLine){ //There's node in the line
			
			while(collumB){
				if (collumB->nextNode){
					flag == 1;
				}
				collumB = collumB->nextPointer;
			}

			if (flag == 1){
				pNode tmpA = lineA->nextNode;
				pNode tmpB = collumB->nextNode;
				int sum = 0;

				while (tmpA && tmpB){
					if (tmpA->collum == tmpB->line){
						sum += tmpA->item * tmpB->item;
					}else if (tmpA->collum > tmpB->line){
						tmpB = tmpB->nextInCollum;
					}else{
						tmpA = tmpA->nextInLine;
					}			
				}
				insertNode(&matrixR.headLine, &matrixR.headCollum, contLine, tmpB->collum, sum);
			}
			contLine++;
			lineA = lineA->nextPointer;			 
		}else{ //Line's empty
			contLine++;
		}			
	}
	printMatrix(&matrixR.headLine, ca, ca);

}

	 
int main(int argc, char const *argv[])
{
	char operation;
	int la, ca, na, lb, cb, nb, line, collum, item;

	struct matrix matrixA;
	matrixA.headLine = NULL;
	matrixA.headCollum = NULL;

	struct matrix matrixB;
	matrixB.headLine = NULL;
	matrixB.headCollum = NULL;

	scanf("%d %d %d %d %d %d", &la, &ca, &na, &lb, &cb, &nb);
	for (int i = 0; i < na; i++){
		scanf("%d %d %d", &line, &collum, &item);
		insertNode(&matrixA.headLine, &matrixA.headCollum, line, collum, item);
	}
	for (int i = 0; i < nb; i++){
		scanf("%d %d %d", &line, &collum, &item);
		insertNode(&matrixA.headLine, &matrixA.headCollum, line, collum, item);	
	}

	/*
	printf("\nLINHA\n");
	while (aux){
		printf("%d -> ", aux->item);
		aux = aux->nextInLine;
	}
	printf("\nCOLUNA\n");
	while (aux2){
		printf("%d\n", aux2->item);
		aux2 = aux2->nextInCollum;
	}*/

	while (scanf("%c", &operation) && operation != 'S'){
		switch(operation){
			case('A'): //imprime matriz A
				printMatrix(&matrixA.headLine, la, ca);
				break;
			case('B'): //imprime matriz B
				printMatrix(&matrixB.headLine, lb, cb);
				break;
			case('M'): //Multiplica matriz A e B, e imprimi o resultado
				multiplyMatrix(&matrixA.headLine, &matrixB.headCollum, la, ca, lb, cb);
				//printMatrix();
				break;
		}
	}


	return 0;
}