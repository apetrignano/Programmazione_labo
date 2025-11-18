#include <stdio.h>
#include <stdlib.h>

void clean(char *s, char *t, char *u);

int main(int argc, char *argv[]) {

  char c1[BUFSIZ]; // s, stringa da ripulire
  char c2[BUFSIZ]; // t, stringa ripulire
  //char c3[BUFSIZ]; // u, occorrenze da togliere
  //
  //
  char c3[] = "a";

  printf("Inserire la stringa:\n");
  fgets(c1, BUFSIZ, stdin);
  //getchar();

  int i = 0;
  /*
  while(c3[i] != '\0') {
  printf("eliminare: %c\n", c3[i]);
  i++;
  }*/
while(i < 5) {
    printf("carattere ASCII di t[%d] = %d\n", i, c2[i]);
    i++;
  }
  i = 0;
  clean(c1, c2, c3);
  /*
  printf("%c\n", c2[0]);
  printf("%c\n", c2[1]);
  printf("%c\n", c2[2]);
  printf("%c\n", c2[3]);
  */

  printf("Risultato:\n%s\n", c2);
  /*while(i < 5) {
    printf("carattere ASCII di t[%d] = %d\n", i, c2[i]);
    i++;
  }*/
  
  return EXIT_SUCCESS;
}

void clean(char *s, char *t, char *u) {

  int i = 0, j = 0, counter = 0;

  while(s[i]!= '\n') {
	  printf("carattere %c\n", s[i]);
	  while(u[counter]) {
		  //printf("confronto tra %c e %c\n", s[i], u[counter]);
      if(s[i] != u[counter]) {
			  t[j] = s[i];
        printf("inserimento del carattere %c (ASCII %d) in c2[%d]\n", t[j], t[j], j);
			  counter++;
		  } else {
        counter = 0;
		    i++;
      }
		  //counter = 0;
		  //j++;
	  }
    printf("contenuto di t[%d]: %c\n", j, t[j]);
    counter = 0;
    i++;
	  j++;
  }
  t[j] = 0;
  // "problema": devo aggiungere manualmente il terminatore alla fine dei vari cicli

}
