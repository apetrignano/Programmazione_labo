#include <stdlib.h>
#include <stdio.h>

#define M 3
#define N 3

int main() {

  void swap(int, int);

  int matrix[M][N] = {
    {1, 2, 3},
    {2, 4, 5},
    {3, 5, 6}
  };

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(matrix[i][j] != matrix[j][i]) {
        printf("La matrice non è simmetrica\n");
        return 0;
      }

    }
  }

  printf("La matrice è simmetrica:)\n");

  return 0;
}

