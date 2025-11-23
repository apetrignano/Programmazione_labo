#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum{FALSE, TRUE} bool;

void bubble_sort(double *v, int len);
void swap(double *a, double *b);

int main() {

  int choice = 0;
  int n = 0;
  //double *v = NULL;

  while(choice != 4) {
    printf("1.\tInserisci elenco di double.\n2.\tOrdina elenco.\n3.\tVisualizza elenco.\n4.\tTermina.\n");
    scanf("%d", &choice);


    switch(choice) {
      case 1:
        
        printf("Numero di valori da inserire: ");
        scanf("%d", &n);
        if(n <= 0) {
          printf("Inserire un numero positivo di valori\n");
          break;
        }

        double *v = (double*) malloc(n * sizeof(double));
        if(v == NULL) {
          fprintf(stderr, "Allocazione fallita\n");
          return -1;
        }

        for(int i = 0; i < n; i++) {
          printf("Numero %d: ", i + 1);
          scanf("%lf", &v[i]);
        }

      break;

      case 2:

        if(n == 0) {
          printf("Inserire prima i numeri\n");
          break;
        }

        bubble_sort(v, n);
        printf("Ordinamento finito!\n");

      break;

      case 3:

        if(n == 0) {
          printf("Inserire prima i numeri\n");
          break;
        }

        for(int i = 0; i < n; i++) {
          printf("numero %d: %lf\n", i + 1, v[i]);
        }

      break;

      case 4:
        if(n != 0) free(v);
      break;

      default:
      
        break;
    }

  }
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

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
  }


