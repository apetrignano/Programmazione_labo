#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef enum {FALSE, TRUE} bool;

void bubble_sort(double*);

int main() {

	int n;
	printf("valori double da inserire: ");
	scanf("%d", n);
	double *numeri = (double*) malloc(n * sizeof(double));
	if (numeri == NULL) {
		fprintf(stderr, "Allocazione fallita\n");
		return -1;
	}
	for(int i = 0; i < n; i++) {
		printf("numero %d: ", i + 1);
		scanf("%lf", numeri[i];
		}


	free(numeri);

	return 0;
}

void bubble_sort(double *v) {
	int tmp, counter = 0;
	bool scambio = TRUE;

