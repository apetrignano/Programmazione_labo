#include <stdlib.h>
#include <stdio.h>

void scambio_indirizzo(int *, int *, int *);
int main() {

	int a = 0, b = 1, c, *px = &a, *py = &b, *tmp = &c;

	*tmp = *px;
	*px = *py;
	*py = *tmp;

	printf("*px = %d\n*py = %d\n", *px, *py);




	return 0;
}

void scambio_indirizzi(int *px, int *py, int *tmp) {
	tmp = px;
	px = py;
	py = tmp;
}
