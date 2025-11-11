#include <stdlib.h>

int read_int();

int main() {

	return 0;
}

int read_int(int numero_soglia) { // Noi vogliamo che in un punto del codice sia maggiore di 0, in un altro punto che abbia un limite sinistro (una volta quindi non deve avere limite)

	int n;

	do {
		printf("Inserire numero > %d: ", numero_soglia);
		scanf("%d", &n);
	} while(n <= numero_soglia);

	return n;
}

