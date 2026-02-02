#include <stdlib.h>
#include <stdio.h>

double somma(double, double);
double sottrazione(double, double);
int main(int argc, char *argv[]) {

  double saldo;
  double *ps = &saldo;
  int c;
  
  printf("Inserire saldo: ");
  scanf("%lf", &saldo);

  do { printf("1. Visualizza saldo\n2. Deposito\n3. Prelievo\n4. Calcolo interesse\n5. Esci\n> ");
  scanf("%d", &c);

  switch(c) {
    
    case 1: 
      printf("Saldo: %lf\n", saldo);
      break;

    case 2:
      printf("Inserire quantità: ");
      double a;
      scanf("%lf", &a);
      if(a <= 0) {
          printf("Errore, il denaro deve essere > 0\n");
          break;
        }
      saldo = somma(saldo, a);

      printf("saldo aggiornato: %lf\n", saldo);
      
      break;

      case 3:
        printf("Inserire quantità: ");
        double b;
        scanf("%lf", &a);
        if(a <= 0 || a > saldo) {
          printf("valore non valido\n");
          break;
        }
        saldo = sottrazione(saldo, a);

        printf("Saldo aggiornato: %lf\n", saldo);


        break;

  }


  } while(c != 5);



  return 0;

}


double somma(double a, double b) {
  return a + b;
}

double sottrazione(double a, double b) {
  return a - b;
}
