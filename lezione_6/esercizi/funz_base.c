#include <stdlib.h>
#include <stdio.h>

// Definizione strutture dati
typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct  {
	Node *head;
	int size;
} Lista;
/*
Lista *crealista() { // implementazione di funzione dichiarata in fase di implementazione
	Lista *list = (Lista*)malloc(sizeof(Lista));
	list->head = NULL;
	list->size = 0;;
	
	return list;
}
*/

// Dichiarazione funzioni
Lista *crealista();
int InserisciInTesta(Lista*, int);
int InserisciInCoda(Lista*, int);
int Rimuovi_index(Lista*, int);
int GetN(Lista*, int);
int Rimuovi_testa(Lista*);
int Rimuovi_coda(Lista*);
void stampa_lista(Lista *);
void cancella(Lista*);

int main() {

	Lista *lis = crealista();

	int dimnuova_testa = InserisciInTesta(lis, 3);
  int ancora1 = InserisciInCoda(lis, 2);
  int ancora2 = InserisciInCoda(lis, 1);

  printf("======================================================\n");
	printf("Inserimento di elemento in testa\nValore: %d\n", dimnuova_testa);
  printf("======================================================\n");
  printf("Contenuto della lista:\n");
  stampa_lista(lis);
  printf("======================================================\n");
  //printf("Contenuto della lista dopo rimozione del primo elemento:\n");
  //int rimozione = Rimuovi_testa(lis);
  //stampa_lista(lis);
  //printf("======================================================\n");
  printf("Contenuto della lista dopo rimozione dell'ultimo elemento:\n");
  int rimozione = Rimuovi_coda(lis);
  stampa_lista(lis);
  printf("======================================================\n");
  printf("Rimozione di tutti gli elementi...\n");
  cancella(lis);
  //printf("contenuto finale:\n");
  //stampa_lista(lis);


	return 0;
}

// Implementazione funzioni

Lista *crealista() { // implementazione di funzione dichiarata in fase di implementazione
	Lista *list = (Lista*)malloc(sizeof(Lista));
	list->head = NULL;
	list->size = 0;;
	
	return list;
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

  return newnode->data;
}

int Rimuovi_testa(Lista *list) {

  if(list->head == NULL) { // se l'head non punta a nulla, significa che non ci sono elementi nella lista, quindi non si fa nulla
    return -1;
  }
  Node *nod = list->head; // si dichiara il Node head
  Node *newnod = nod->next; // dichiarazione del nodo successivo all'head
  list->head = newnod; // il successivo diventa l'head
  free(nod); // si rimuove l'head

  list->size--; // aggiornamento size
  
  return list->size;
}

int Rimuovi_coda(Lista *list) {

  if(list->head == NULL) {
  return -1;
  }
  
  Node *nod = list->head;
  Node *nnod = NULL;
  while(nod->next != NULL) { // scorre indice fino a trovare l'ultimo
    nnod = nod;
    nod = nod->next;
  }
  nnod->next = nod->next;
  free(nod);
  list->size--;

  return list->size;
}
int Rimuovi_index(Lista *list, int index) {
  if(index >= list->size) {
    printf("indice fuori dal dominio.\n");
    return -1;
  }
  Node *curr = list->head;
  Node *prec = NULL;

  if(index == 0) {
    list->head = curr->next;
    free(curr);
  } else {
    for(int i = 0; i < index; i++) {
     prec = curr;
     curr = curr->next;
  }
  prec->next = curr->next;
  free(curr);
  }
  list->size--;
  return list->size;
}

int GetN(Lista *list, int index) {
  if(index >= list->size) {
    printf("indice fuori dal dominio!\n");
    return -1;
  }
  
  Node *attuale = list->head; // si sta dichiarando un tipo Node, che ok viene modificato, ma si tratta di una variabile locale, non indice sul nodo vero e proprio
  for(int i = 0; i < index; i++) { // scorre la lista fino a trovare l'elemento all'indice desiderato
    attuale = attuale->next;
  }
  return attuale->data;
}

void stampa_lista(Lista *list) {
  printf("Elenco elementi della lista:\n");
  for(int i = 0; i < list->size; i++) {
    printf("elemento %d: %d\n", i + 1, GetN(list, i));
  }
}

void cancella(Lista *list) {

  while(list->size > 0) {
    int temp = Rimuovi_coda(list);
  }
}
