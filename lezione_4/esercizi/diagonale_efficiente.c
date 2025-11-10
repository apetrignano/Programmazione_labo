#include <stdlib.h>
#include <stdio.h>


#define M 3
#define N 3

int main(){
  int matrix[M][N]= {
    {1, 1, 0},
    {0, 1, 0},
    {1, 0, 1}
  };
  int i, j;
  int sum = 0;

  for(int i = 0; i < 3; i++) {
    sum += matrix[i][i];
  }

  printf("Somma della diagonale = %d\n", sum);

 return 0;
 }
