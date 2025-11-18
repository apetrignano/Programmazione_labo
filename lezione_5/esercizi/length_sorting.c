#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STRINGS 5

void length_sorting(char **, int);
int main(int argc, char *argv[]) {

  char *puntatori_stringhe[NUM_STRINGS];
  char buffer[BUFSIZ];
  char strings[NUM_STRINGS][BUFSIZ];

  for(int i = 0; i < NUM_STRINGS; i++) {
    printf("stringa %d: ", i + 1);
    fgets(buffer, BUFSIZ, stdin); // inserimento della stringa in una stringa buffer
    buffer[strcspn(buffer, '\n')] = '\0'; // aggiunta manuale del terminatore nell'indice ove presente il carattere di invio
    //
    strcpy(strings[i], buffer); // copia dell'array buffer all'interno della corrispondente riga dell'insieme di stringhe
    puntatori_stringhe[i] = strings[i]; // assegnamento del puntatore alla stringa appena inserita
  }




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

}
