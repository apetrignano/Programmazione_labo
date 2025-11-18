#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STRINGS 5

typedef enum{FALSE, TRUE} bool;
void length_sorting(char **, int);
void swap(char*, char*);
int main(int argc, char *argv[]) {

  char *puntatori_stringhe[NUM_STRINGS];
  char buffer[BUFSIZ];
  char strings[NUM_STRINGS][BUFSIZ];

  for(int i = 0; i < NUM_STRINGS; i++) {
    printf("stringa %d: ", i + 1);
    fgets(buffer, BUFSIZ, stdin); // inserimento della stringa in una stringa buffer
    buffer[strcspn(buffer, "\n")] = '\0'; // aggiunta manuale del terminatore nell'indice ove presente il carattere di invio
    //
    strcpy(strings[i], buffer); // copia dell'array buffer all'interno della corrispondente riga dell'insieme di stringhe
    puntatori_stringhe[i] = strings[i]; // assegnamento del puntatore alla stringa appena inserita
  }
  swap(strings[0], strings[1]);




  return EXIT_SUCCESS;
}

void length_sorting(char **s, int len) { // char **s chiaramente è strings,il quale è un puntatore ad array di puntatori
  //
  for(int i = 0; i < len; i++) {
   for(int j = i + 1; j < len; j++) {
      if(strlen(s[i]) > strlen(s[j])) {
        swap(s[i], s[j]);
      }

    } 
  }

  /*scambio = true;
  while(scambio == TRUE) {
    scambio = FALSE;
    for(int i = 0; i < NUM_STRINGS - 2; i++) {
      if
    }
  }


 /*while(scambio == TRUE) {
        scambio = FALSE;
        for(int i = 0; i <= N - 2; i++) {
            if(v[i] > v[i+1]){
            tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = tmp;
            scambio = TRUE;
            counter ++;
            }
            
        }
    }*/

}

void swap(char *s1, char *s2) {
  printf("stringhe prima della conversione: \n%s \n%s \n", s1, s2);
  char tmp[BUFSIZ];
  strcpy(tmp, s1); // copia del contenuto di s1 in tmp
  strcpy(s1, s2);
  strcpy(s2, tmp);

  printf("stringhe dopo la conversione: \n%s \n%s \n", s1, s2);
}
