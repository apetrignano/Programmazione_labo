#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3
int main(int argc, char *argv[]){

  int matrix[M][N] = {
  {2, 1, 3},
  {4, 5, 2},
  {7, 1, 0}
  };
  int max = matrix[0][0];
  int index_i = 0;
  int index_j = 0;

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(matrix[i][j] > max) {
        max = matrix[i][j];
        index_i = i;
        index_j = j;
      }
    }
  }
  printf("elemento della matrice massimo: v[%d][%d] = %d\n", index_i + 1, index_j + 1, max);
  return 0;
}
