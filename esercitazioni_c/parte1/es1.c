#include <stdlib.h>
#include <stdio.h>

void swap(int**, int**);

int main(int argc, char *argv[]) {

  int a = 0;
  int b = 1;
  int *px = &a;
  int *py = &b;

  printf("valore puntato da px: %d\n", *px);
  printf("valore puntato da py: %d\n", *py);

  swap(&px, &py);

  printf("valore puntato da px: %d\n", *px);
  printf("valore puntato da py: %d\n", *py);
  return 0;

}

void swap(int **a, int **b) {

  int *tmp = *a;
  *a = *b;
  *b = tmp;
}
