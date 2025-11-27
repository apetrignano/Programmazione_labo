#include <stdlib.h>
#include <stdio.h>

#define N 100

int main() {

  int a[N], b[N], num_a, num_b;

  printf("numero di valori da inserire per a: ");
  scanf("%d", &num_a);
  for(int i = 0; i < num_a; i++) {
    printf("valore %d: ", i);
    scanf("%d", &a[i]);
  }

  printf("numero di valori da inserire per b: ");
  scanf("%d", &num_b);
  for(int i = 0; i < num_b; i++) {
    printf("valore %d: ", i);
    scanf("%d", &b[i]); // non capisco perchè devo mettere l'indirizzo se l'array è un puntatore (risposta: perchè DECADE a puntatore durante una chiuamata a funzione)
    printf("%d\n", b[i]);
  }

  return 0;
}

int *merge()
