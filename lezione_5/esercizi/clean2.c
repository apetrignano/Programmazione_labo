#include <stdio.h>
#include <stdlib.h>

void clean(char *s, char *t, char *u);

int main(int argc, char *argv[]) {

  char c1[BUFSIZ]; // s, stringa da ripulire
  char c2[BUFSIZ]; // t, stringa ripulire
  //char c3[BUFSIZ]; // u, occorrenze da togliere
  //
  //
  char c3[] = "cfg";

  printf("Inserire la stringa:\n");
  fgets(c1, BUFSIZ, stdin);
  //getchar();

  /*printf("inserire parametri da eliminare:\n");
  fgets(c3, BUFSIZ, stdin);*/

  /*int i = 0;
  while(c3[i] != '\0') {
  printf("eliminare: %d\n", c3[i]);
  i++;
  }*/

  clean(c1, c2, c3);

  printf("Risultato:\n%s", c2);
  
  return EXIT_SUCCESS;
}

void clean(char *s, char *t, char *u) {

  int i = 0, j = 0, counter = 0;
   /*while(u[counter] != '\0') { // non va bene controllare un solo carattere alla volta
    printf("controllo della presenza di %c\n", u[counter]);
      while(s[i]) {
        if(s[i] != u[counter]) { // inserisci in t solo se valore è diverso dal check
         t[j] = s[i];
         printf("%c va bene\n", s[i]);
         j++;
        //problema: per ora il check successivo viene fatto su s, non sulla stringa modificata
        }
        i++;
      }
    i = 0; j = 0;
    counter++;
    }*/ 
  while(s[i]) {
    printf("inizio controllo\n");
    while(u[counter]) {
      while(s[i] != u[counter]) {
        printf("controllo tra %c e %c\n", s[i], u[counter]);
        t[j] = s[i];
        counter++;
      }
      j++;
    }
    i++;
    counter = 0;
  }
}
