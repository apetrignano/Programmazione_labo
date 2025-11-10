#include <stdlib.h>
#include <stdio.h>

int main() {

    double somma();
    double sottrazione();
    double moltiplicazione();
    double divisione();
    int select;
    double res;
    do {
    do{
        printf("0.\tInserisci operandi\n1.\tAddizione.\n2.\tSotttrazione.\n3.\tMoltiplicazione.\n4.\tDivisione.\n5.\tEsci.\n> ");
        scanf("%d", &select);
    } while(select < 0 || select > 5);

    

    switch(select) {
	case 0:

        case 1:
		printf("%lf\n", somma());
		break;

        case 2:
		printf("%lf\n", sottrazione());
		break;
        case 3:
		printf("%lf\n", moltiplicazione());
		break;
        case 4:
		printf("%lf\n", divisione());
		break;

    }
    } while(select != 5);

    return 0;
}

double somma() {
	double a, b;
	double risultato;

	printf("Somma\nInserire a e b: ");
	scanf("%lf %lf", &a, &b);

	printf("%lf + %lf = ", a, b);
