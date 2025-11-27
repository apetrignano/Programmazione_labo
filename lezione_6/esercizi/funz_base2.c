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

// Dichiarazione funzioni
Lista *crealista();
int InserisciInTesta(Lista*, int);
int InserisciInCoda(Lista*, int);
int Rimuovi_index(Lista*, int);
int GetN(Lista*, int); // restituisce il valore dell'indice in parametro
int Rimuovi_testa(Lista*);
int Rimuovi_coda(Lista*);
void stampa_lista(Lista *);
void cancella(Lista*);

// Dichiarazione funzioni nuove
void salva(Lista*, char*); // scrive i valori della vista nel file, uno per volta
Lista *carica(char*); // legge da file un numero non noto a priori di interi, e li salva in una lista concatenata
int rimuovi(Lista*, int); // cancella una sola occorrenza di un valore passato come parametro
int stampaRicorsiva(Node*); // stampa a schermo gli elementi della lista in ordine inverso
void stampa_recursive(Lista *lis); // semplicemente stampa un valore int
void stampaRicorsivaEff(Node *node); // stampa ricordiva ma più efficiente, non da segmentation fault

int main(int argc, char *argv[]) {

  if(argc != 2) {
    //printf("Usage: ./prog <output>\n");
    printf("Usage: :/.%s <input>\n", argv[0]);
    return -1;
  }

  Lista *newlist = carica(argv[1]);
  
  printf("Stampa degli elementi in modo ricorsivo:\n");
  /*while(newlist->head != NULL) {
    stampa_recursive(newlist);
  }*/
  stampaRicorsivaEff(newlist->head);

	return 0;
}

// Implementazione funzioni

Lista *crealista() { // implementazione di funzione dichiarata in fase di implementazione
	Lista *list = (Lista*)malloc(sizeof(Lista));
  if(list == NULL) {
    fprintf(stderr, "Allocazione fallita\n");
    exit(20);
  }
	list->head = NULL;
	list->size = 0;;
	
	return list;
}
int InserisciInTesta(Lista *list, int a) {

  // manca un metodo per gestire il caso in cui non ci siano elementi da inserire

	Node *newnode = (Node *) malloc(sizeof(Node)); // dichiarazione di nuovo nodo di tipo nodo
	if(newnode == NULL) {
    fprintf(stderr, "Allocazione fallita\n");
    return -1;
  }

  newnode->data = a;
	newnode->next = list->head; //punta al primo elemento della lista
	list->head = newnode; // Ora newnode è il primo elemento della lista
	list->size++;
	
	return newnode->data;
}

int InserisciInCoda(Lista *list, int a) {

	Node *newnode = (Node *) malloc(sizeof(Node));
  if(newnode == NULL) {
    fprintf(stderr, "Allocazione fallita\n");
    return -1;
  }
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

  for(int i = 0; i < list->size; i++) {
    printf("elemento %d: %d\n", i + 1, GetN(list, i));
  }
}

void cancella(Lista *list) {

  while(list->size > 0) {
    int temp = Rimuovi_coda(list);
  }
}

void salva(Lista *list, char *output) {

  FILE *f_w;
  f_w = fopen(output, "w"); // apri il file passato come parametro
  if(f_w == NULL) {
    fprintf(stderr, "Open error!\n");
    exit(33);
  }

  for(int i = 0; i < list->size; i++) {
    fprintf(f_w, "elemento %d: %d\n", i + 1, GetN(list, i));
  }
  if(fclose(f_w) != 0) {
    fprintf(stderr, "close error\n");
    exit(34);;
  }
}

Lista *carica(char *input) {
  FILE *f_r = fopen(input, "r"); // apri il file passato come parametro)
  int num;
  if(f_r == NULL) {
    fprintf(stderr, "Open error!\n");
    exit(34);
  }

  Lista *lis = crealista();

  while(fscanf(f_r, "%d", &num) == 1) { // la lettura si fa direttamente qua, altrimenti l'ultimo valore viene ripetuto
    InserisciInTesta(lis, num); // inserisce il numero appena letto in testa alla lista
  }

  if(fclose(f_r) != 0) {
    fprintf(stderr, "close error!\n");
    exit(35);
  }

  stampa_lista(lis);
  //int n = rimuovi(lis, 36);
  //stampa_lista(lis);
  return lis;

}



int rimuovi(Lista *lis, int n) {

  Node *seeknode = lis->head;
  //printf("primo valore della lista: %d\n", seeknode->data);
  Node *prec = NULL;

  while(seeknode->data != n && seeknode->next != NULL) {

    if(seeknode->next == NULL) return -1;
    prec = seeknode;
    seeknode = seeknode->next;
  }
  if(seeknode->next == NULL) return -1;
  prec->next = seeknode->next;
  free(seeknode);
  lis->size--;

  return n;
}


int stampaRicorsiva(Node *node) {
  if(node->next == NULL) {
    //printf("Raggiunto caso base\n");
    return node->data;
  } else {
    //printf("non raggiunto caso base, si va avanti con il passo iterativo\n");
    return stampaRicorsiva(node->next);
  }
}

void stampa_recursive(Lista *lis) {

  printf("%d\n", stampaRicorsiva(lis->head));
  Rimuovi_coda(lis);

}
void stampaRicorsivaEff(Node *node) {
  if(node == NULL) return;
  stampaRicorsivaEff(node->next);
  printf("%d\n", node->data);
}
