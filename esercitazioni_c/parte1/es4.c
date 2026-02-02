#include <stdlib.h>
#include <stdio.h>

void reverse(char *s, char *t);

int main(int argc, char *argv[]) {

  char s1[BUFSIZ], s2[BUFSIZ];

  printf("Inserire la stringa: ");

  if(fgets(s1, BUFSIZ, stdin) == NULL) {
    printf("Errore di lettura!\n");
    return -1;
  }

  int i = 0;
  //for(; i != '\n'; i++);
  while(s1[i] != '\n') {i++;}
  s1[i] = '\0';

  reverse(s1, s2);

  printf("%s\n", s1);
  printf("%s\n", s2);

return 0;
}

void reverse(char *s, char *t) {

  int i = 0;
  while(s[i]!= '\0') {i++;} // sono arrivato all'ultimo carattere prima del terminatore di stringa, ha indice i
  i--;
  int size = i;
  //printf("ultimo carattere prima del terminatore: %c\n", s[i]);
  int k = 0;

  while(k < size || i >= 0) {
    t[k] = s[i];
    k++;
    i--;
  }
  t[k+1] = '\0';
  }



