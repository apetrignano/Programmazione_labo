#include <stdlib.h>
#include <stdio.h>

int equals(char *s, char *t); // valore positivo se stringhe sono uguali, nullo altrimenti

int main(int argc, char *argv[]) {

  char s1[BUFSIZ], s2[BUFSIZ];

  printf("Inserire stringa 1: ");
  if(fgets(s1, BUFSIZ, stdin) == NULL) {
    printf("Errore di lettura!\n");
    return -1;
  }

  printf("Inserire stringa 2: ");
  if(fgets(s2, BUFSIZ, stdin) == NULL) {
    printf("Errore di lettura!\n");
    return -1;
  }

  int res = equals(s1, s2);
  
  if(res == 0) {
    printf("Le due stringhe non sono uguali.\n");
  } else {
    printf("Le due stringhe sono uguali.\n");
  }

  return 0;
}

int equals(char *s, char *t) {

  int flag = 1;
  

  for(int i = 0; s[i] != '\0'  && t[i] != '\0'; i++) {
    if (s[i] != t[i]) {
      flag = 0;
    }
  }

  return flag;

}
 // okay ma l'algoritmo non è efficiente, ci penserò in un secondo momento
