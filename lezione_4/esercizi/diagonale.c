#include <stdlib.h>
#include <stdio.h>


#define M 3
#define N 3

int main(){
  int matrix[M][N]= {
    {1, 1, 0},
    {0, 1, 0},
    {0, 0, 1}
  };
  int i, j;
  int sum = 0;

  for (i = 0; i < M; i++){
    for (j = 0; j < N; j++){
    if (i == j){
      sum += matrix[i][j];
      }
    }
  }
  printf("Somma della diagonale = %d\n", sum);

 return 0;
 }

