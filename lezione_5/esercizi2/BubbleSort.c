#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef enum {FALSE, TRUE} bool;

void bubble_sort(double*, int);
void swap(double*, double*);
void swapPointers(double *a, double *b);

int main() {

	int n;
	printf("valori double da inserire: ");
	scanf("%d", &n);
	double *numeri = (double*) malloc(n * sizeof(double));
	if (numeri == NULL) {
		fprintf(stderr, "Allocazione fallita\n");
		return -1;
	}
	for(int i = 0; i < n; i++) {
		printf("numero %d: ", i + 1);
		scanf("%lf", &numeri[i]);
		}

  //printf("%lf - %lf\n", numeri[0], numeri[1]);

  bubble_sort(numeri, n);
  //swapPointers(&numeri[0], &numeri[1]);
  //printf("%lf - %lf\n", numeri[0], numeri[1]);

  for(int i = 0; i < n; i++) {
    printf("elemento %d: %lf\n", i + 1, numeri[i]);
  }


	free(numeri);

	return 0;
}

void bubble_sort(double *v, int len) {
	bool scambio = TRUE;
  while(scambio == TRUE) {
        scambio = FALSE;
        for(int i = 0; i <= len - 2; i++) {
            //printf("confronto tra %lf e %lf\n", v[i], v[i + 1]);
            if(v[i] > v[i+1]){
            swap(&v[i], &v[i+1]);
            //swapPointers(&v[i], &v[i+1]);
            scambio = TRUE;
            }
        }
    }
}

void swap(double *a, double *b) { // sinceramente devo capire questo, pensavo si dovesse lavorare sugli indirizzi // sinceramente devo capire questo, pensavo si dovesse lavorare sugli indirizzi
    double tmp = *a;
    *a = *b;
    *b = tmp;
  }

void swapPointers(double *a, double *b) { // a e b contengono degli indirizzi
  double *tmp = a; // dichiarazione di un puntatore di tipo double, il cui valore è l'indirizzo del valore puntato da a
  //printf("tmp = %lf\na = %lf\n", *tmp, *a);
  a = b; // assegnamento del valore di b ad a; il valore di b è l'indirizzo del valore puntato da b, a ora punta *b
  //printf("a = %lf\nb = %lf\n", *a, *b);
  b = tmp; // assegnamento di tmp a b; il valore di tmp è l'indirizzo del valore puntato da a, b ora punta a *tmp
  //printf("b = %lf\ntmp = %lf\n", *b, *tmp);
}
