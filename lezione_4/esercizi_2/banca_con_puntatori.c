#include <stdlib.h>
#include <stdio.h>

void deposito(double*, double*);
void prelievo(double*, double*);
void calcolo_interesse(double*, double, double, double);

int main() {

  int choice;
  double saldo = 300, dep, prel, anni, saldo_ipotetico, tasso = 0.03;
  double *ps = &saldo, *pd = &dep, *pp = &prel, *psi = &saldo_ipotetico;

  do{
    do{

      printf("1.\tVisualizza saldo.\n2.\tDeposito.\n3.\tPrelievo.\n4.\tCalcolo interesse.\n5.\tEsci.\n> ");
      scanf("%d", &choice);
      if(choice < 1 || choice > 5) printf("Inserire un numero compreso tra 1 e 5.\n");

    } while(choice < 1 || choice > 5);

    switch(choice) {

      case 1:

        printf("Saldo corrente: %lf\n", saldo);

        break;

      case 2:
        printf("Denaro da depositare: ");
        scanf("%lf", &dep);

        if(dep <= 0) {
          printf("Il deposito deve essere positivo e non nullo\n");
          break;
        }

        deposito(ps, pd);
        printf("Saldo aggiornato: %lf\n", saldo);

        break;

      case 3:

        printf("Denaro da prelevare: ");
        scanf("%lf", &prel);

        if (prel < 0 || prel >= saldo) {
          printf("Si può prelevare un numero maggiore di 0 ed inferiore al saldo disponibile\n");
          break;
        }

        prelievo(ps, pp);

        printf("Saldo aggiornato: %lf\n", saldo);

        break;

      case 4:
        printf("Inserire anni: ");
        scanf("%lf", &anni);

        if(anni < 0) {
          printf("Numero di anni deve essere positivo\n");
          break;
        }

        calcolo_interesse(psi, saldo, anni, tasso);
 
        printf("Saldo ipotetico dopo %lf anni: %lf\n", anni, saldo_ipotetico);
 
 

    }
  } while(choice !=5);

  return 0;

}

void deposito(double *saldo, double *dep) {

  *saldo += *dep;

}

void prelievo(double *saldo, double *prel) {

  *saldo -= *prel;

}


void calcolo_interesse(double *saldo_ipotetico, double s, double y, double t ) {

  *saldo_ipotetico = (s) * (t) * (y);

}
