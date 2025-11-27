#include <stdlib.h>
#include <stdio.h>

int delannoy(int, int);

int main(int argc, char *argv[]) {

  if(argc != 3) {
  printf("Usage: %s <m> <n>\n", argv[0]);
  return -1;
  }

  int m = atoi(argv[1]), n = atoi(argv[2]);
  int n_d = delannoy(m, n);

  printf("%d\n", n_d);

  return 0;

}

int delannoy(int m, int n) {
  if(n == 0 || m == 0) {
    return 1;
  }

  return delannoy(m - 1, n) + delannoy(m, n - 1) + delannoy(m - 1, n - 1);

}
