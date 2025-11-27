#include <stdlib.h>
#include <stdio.h>

int catalan(int);

int main(int argc, char *argv[]) {

  if(argc != 2 || atoi(argv[1]) < 0) {
    printf("Usage: %s <num_maggiore_di_0\n", argv[0]);
    return -1;
  }

  int n = atoi(argv[1]);

  for(int i = 0; i <= n; i++) {
    printf("C(%d) = %d\n", i, catalan(i));
  }

  return 0;
}

int catalan(int n) {
  //printf("si parte con %d\n", n);

  if(n == 0) {
    //printf("raggiunto caso base c(%d)\n", n);
    
    return 1;
  }

  //printf("passo ricorsivo: C(n-1) = %d\n", 2 * (2 * n - 1) / (n + 1) * catalan(n - 1));
  printf("chiamata alla funzione c(%d)\n", n - 1);
  return (int) 2 * ((2 * (double)n) - 1) / ((double)n + 1) * catalan(n - 1);
}
