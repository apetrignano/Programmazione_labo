#include <stdlib.h>
#include <stdio.h>

int main() {

	char s1[] = "Contenuto 1"; // Le stringhe sono salvate correttamente
	char s2[] = "Contenuto 2";
  
  //printf("stringa numero 1: %s", s1);
  //char *pointerA = &(s1[0]), *pointerB = &(s2[0]), *pointerTemp; // questi puntatori non è che si riferiscono a un vettore di char, ma ad un singolo carattere
	//char *pointerA = &s1, *pointerB = &s2, *pointerTemp; // L'errore è qui: bisogna dichiarare un puntatore diverso 
  // puntatore che punta ad una singola cella di memoria, che corrisponde all'indirizzo di base di una stringa
  //char (*pA)[] = &s1;
  //char *pA = s1; // Corretto così: 
  char *pointerA = s1, *pointerB = s2, *pointerTemp;

  //printf("stringa a cui punta il puntatore pointerA: %s", *pA);

  // Algoritmo di scambio
	pointerTemp = pointerA;
	pointerA = pointerB;
	pointerB = pointerTemp;

  //printf("valore di pointerA: %c\n", *(pointerA + 1)); // così invece si guarda il secondo elemento della stringa
	//printf("Stringa 1: %c\nStringa 2: %c\n", *pointerA, *pointerB); // così io sto semplicmente stampando un carattere, in particolare il primo della stringa
	printf("Stringa 1: %s\nStringa 2: %s\n", pointerA, pointerB); // non va messo *pointerX, altrimenti verrebbe stampato il primo elemento dell'oggetto puntato, perchè pointerA punta all'INTERO array
	
	return 0;
}
