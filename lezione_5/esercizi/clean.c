#include <stdio.h>
#include <stdlib.h>

void clean(char *s, char *t); // s stringa da ripulire, t stringa ripulita

int main(int argc, char *argv[]) {

  char c1[BUFSIZ];
  char c2[BUFSIZ];

  printf("Inserire la stringa:\n");
  fgets(c1, BUFSIZ, stdin);

  clean(c1, c2);

  printf("Risultato:\n%s", c2);
  
  return EXIT_SUCCESS;
}

void clean(char *s, char *t) {

  int i = 0, j = 0;
  while(s[i]) {
    if(s[i] != 32) {
      t[j] = s[i];
      j++;
    }
    i++;
  }
}

