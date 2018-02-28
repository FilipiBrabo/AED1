#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact * node;
typedef struct contact contact;
struct contact{
		char *name;
		int tel;
		char *email;
		contact *next;
};

node createContact(char* name, int tel, char* email){
	node x = malloc(sizeof(contact));
	if (x == NULL){
		return NULL;
	}
	x->name = name;
	x->tel = tel;
	x->email = email;
	x->next = NULL; 
	printf("ok");

	return x;
}

void addContact(node *ini, node x){
	if (*ini == NULL){
		*ini = x;
	} else{
		node aux = malloc(sizeof(contact));
		aux = *ini;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = x;
	}
}

node searchName(node *ini, char* name){
	int aux;
	if (*ini == NULL){
			printf("Agenda vazia");
			return NULL;
	}
	node temp = malloc(sizeof(node));
	temp = *ini;
	while (temp != NULL){
		aux = strcmp((temp)->name, name);
		if (aux == 0){
			return temp;
		}
		temp = temp->next;		
	}
	printf("Contato não encontrado\n");
	return NULL;
}

node showContact(node x){	
	printf("\n----------------------------\n");
	printf("Nome: %s\n", x->name);
	printf("Telefone: %d\n", x->tel);
	printf("Email: %s\n", x->email);
	printf("----------------------------\n");
}

node searchTel(node* inicio, int tel){
	if (*inicio == NULL){
		return NULL;
	}
	
	node aux = malloc(sizeof(node));
	aux = *inicio;
	
	while (aux != NULL){
		if (aux->tel == tel) return aux;
		aux = aux->next;
	}
	printf("Contato não encontrado\n");
	return NULL;
}

void imprimeLista(node* ini){
	if (*ini == NULL){
		printf("Lista vazia\n");
	}

	node aux = malloc(sizeof(node));
	aux = *ini;
	
	while (aux != NULL){
		showContact(aux);
		aux = aux->next;
	}
}


int main(int argc, char const *argv[]){

	node ini = NULL;
	char * name;
	char * email;
	int x, tel;
	while(1){	
		printf("\nO que você deseja fazer?\n\nDigite:\n1 - Adicionar contato\n");
		printf("2 - Buscar dados pelo nome\n3 - Buscar dados pelo telefone\n");
		printf("4 - Mostrar agenda\n5 - Sair\n");
		scanf("%d", &x);

		switch (x){
			case 1:			
				name = (char*) malloc (40 * sizeof(char));
				email = (char*) malloc (40 * sizeof(char));	
				
				printf("\nDigite o nome:\n");
				scanf("%s", name);
				printf("\nDigite o telefone:\n");
				scanf("%d", &tel);
				printf("\nDigite o email:\n");
				scanf("%s", email);

				node new = createContact(name, tel, email);
				if (new){
					addContact(&ini, new);
				}else{
					("Sem memória disponível!");
				}
				break;
			
			case 2:
				name = (char*) malloc (40 * sizeof(char));
				printf("\nDigite o nome:\n");
				scanf("%s", name);

				node aux = searchName(&ini, name);
				if (aux == NULL){
					break;
				}else{
					showContact(aux);
				}
				break; 

			case 3:
				printf("\nDigite o número de telefone:");
				scanf("%d", &tel);

				node aux1 = searchTel(&ini, tel);
				if (aux1 == NULL){
					break;
				}else{
					showContact(aux1);
				}
				break;
			case 4:
				printf("Agenda:");
				imprimeLista(&ini);
			case 5:
				return 0;
	}
	return 0;
}
