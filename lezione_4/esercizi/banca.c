#include <stdlib.h>
#include <stdio.h>

int main() {

	double deposito(double, double);
	double prelievo(double, double);
	double tass(double, double, double);

	int choice;
	double saldo = 300;
	double tasso = 3;

	do{

	do{
		printf("1.\tVisualizza saldo.\n2.\tDeposito.\n3.\tPrelievo.\n4.\tCalcolo interesse.\n5.\tEsci.\n> ");
		scanf("%d", &choice);
	} while(choice < 1 || choice > 5); 

	switch(choice) {
		case 1:
			printf("Saldo corrente: %lf\n", saldo);
			break;
		case 2:
			double dep;

			printf("Quanto di intende depositare? ");
			scanf("%lf", &dep);
			saldo = deposito(saldo, dep);
			printf("Saldo aggiornato: %lf\n", saldo);
			break;
		case 3:
			double prel;

			do{
			
			printf("Inserire denaro da prelevare: ");
			scanf("%lf", &prel);
			} while (prel <= 0 || prel > saldo);

			printf("Saldo aggiornato: %lf\n", prelievo(saldo, prel));
			break;
			
		case 4:
			double time;

			printf("Anni di deposito: ");
			scanf("%lf", &time);

			printf("Tasso annuo: %lf\nSaldo previsto: %lf\n", tasso, saldo + tass(saldo, time, tasso));
	
	}



	} while(choice != 5);

	/*switch(choice) {
		case 1:
			printf("Saldo corrente: %lf", saldo);
			break;
		case 2:
			double dep;

			printf("Quanto di intende depositare? ");
			scanf("%lf", &dep);
			printf("Saldo aggiornato: %lf\n", deposito(saldo, dep));
			break;
		case 3:
			double prel;

			do{
			
			printf("Inserire denaro da prelevare: ");
			scanf("%lf", &prel);
			} while (prel <= 0 || prel > saldo);

			printf("Saldo aggiornato: %lf", prelievo(saldo, prel));
			
		case 4:
			double time;

			printf("Anni di deposito: ");
			scanf("%lf", &time);

			printf("Tasso annuo: %lf\nSaldo previsto: %lf\n", tasso, saldo + tass(saldo, time, tasso));
	
	} */


return 0;
}

double deposito(double a, double b) {
	return a + b;
}

double prelievo(double a, double b) {
	return a - b;
}

double tass(double saldo, double anni, double tasso){

	return saldo * anni * tasso;

}
