#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct  {
	Node *head;
	int size;
} Lista;


Lista *crealista() { // implementazione di funzione dichiarata in fase di implementazione
	Lista *list = (Lista*)malloc(sizeof(Lista));
	list->head = NULL;
	list->size = 0;;
	
	return list;
}

int InserisciInTesta(Lista*, int);
int InserisciInCosa(Lista*, int);

int main() {

	Lista *lis = crealista();

	int dimnuova = InserisciInTesta(lis, 3);

	printf("%d\n", dimnuova);

	return 0;
}

int InserisciInTesta(Lista *list, int a) {


	Node *newnode = (Node *) malloc(sizeof(Node)); // dichiarazione di nuovo nodo di tipo nodo
	newnode->data = a;
	newnode->next = list->head; //punta al primo elemento della lista
	list->head = newnode; // Ora newnode è il primo elemento della lista
	list->size++;
			    
	return newnode->data;
}

int InserisciInCoda(Lista *list, int a) {

	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = a;
	newnode->next = NULL; // dato che è l'ultimo elemento non punta a nulla
	
	if(list->head == NULL) {
		list->head = newnode; // se non ci sono altri elementi chiaramente il primo elemento è comunque quello aggiunto in cdda
	} else {
		Node *current = list->head; // dichiarazione di un puntatore al tipo node, che corrisponde al primo elemento
		while(current->next != NULL) {
			current = current->next;
		} current->next = newnode;
	} list->size++;

