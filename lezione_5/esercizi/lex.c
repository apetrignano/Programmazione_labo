#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lex(char *s, char *t); // confronta due stringhe per dire come sono ordinate

int main(int argc, char *argv[]) {

  if(argc != 3) {
    printf("Usage: ./<nome_programma> <stringa_1> <stringa_2>");
      return -1;
  }
  
  /*char s1[BUFSIZ] = argv[1];
  s2[BUFSIZ] = argv[2];*/
  char s1[BUFSIZ], s2[BUFSIZ];
  strcpy(s1, argv[1]); strcpy(s2, argv[2]);

  int ord = lex(s1, s2);
  //printf("esito della funzione: %d\n", ord);

  if(ord > 0) {
    printf("s1 precede s2\n");
  } else if(ord < 0) {
    printf("s2 precede s1\n");
  } else printf("le due stringhe sono uguali\n");

  return EXIT_SUCCESS;
}

int lex(char *s, char *t) {

  int result = 0, i = 0;

  while(s[i] || t[i]) {
    if(s[i] < t[i]) {
       result = 1;
      return result;
    } else if(s[i] > t[i]) {
      result = -3;
      return result;
    }
    i++;
  }
  return result;
}
