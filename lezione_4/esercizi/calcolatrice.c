#include <stdlib.h>
#include <stdio.h>

// Inserire una funzione check_operandi, che controlla se gli operandi sono effettivamente stati inseriti

int main() {

    double somma();
    double sottrazione();
    double moltiplicazione();
    double divisione();
    char select;
    double res;
    
    printf("Inserire i due operandi: ");
    scanf("%lf %lf", a, b);
    do {
    do{
        printf("1.\tAddizione.\n2.\tSotttrazione.\n3.\tMoltiplicazione.\n4.\tDivisione.\n5.\tEsci.\n> ");
        scanf("%d", &select); // ovviamente non andrebbe usata la scanf per il char, ma la getchar(), con i difetti che ne conseguono obv
    } while(select < 1 || select > 5);

 /*   if(select == 5) {
    return 0;
    } */

    switch(select) {
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

/*double somma() {
	double a, b;
	double risultato;

	printf("Somma\nInserire a e b: ");
	scanf("%lf %lf", &a, &b);

	printf("%lf + %lf = ", a, b);

	risultato = a + b;

	return risultato;

}*/

double somma(double a, double b) {
	return a + b;
}

double sottrazione() {
	double a, b;
	double risultato;

	printf("Sottrazione\nInserire a e b: ");
	scanf("%lf %lf", &a, &b);

	printf("%lf - %lf = ", a, b);

	risultato = a - b;

	return risultato;

}

double sottrazione(double a, double b) {

	return a - b;
}


/*double moltiplicazione() {
	double a, b;
	double risultato;

	printf("Moltiplicazione\nInserire a e b: ");
	scanf("%lf %lf", &a, &b);

	printf("%lf * %lf = ", a, b);

	risultato = a - b;

	return risultato;

}*/
double moltiplicazione(double a, double b) {
	return a * b;
}

/*double divisione() {
	double a, b;
	double risultato;

	printf("Divisione\nInserire a e b: ");
	scanf("%lf %lf", &a, &b);
	if(b == 0) {
	printf("Errore: divisione per 0\n");
	return -1;
	}
	risultato = a / b;

	return risultato;
}*/
double divisione(double a, double b) {
	if(b == 0} {
			printf("Errore: divisione per 0!"\n);
			return -1;
		} else return a / b;
	}
