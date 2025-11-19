#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STRINGS 5

typedef enum{FALSE, TRUE} bool;

//void length_sorting(char **, int);
void swap(char*, char*);
void length_BubSort(char **, int);
int main(int argc, char *argv[]) {

  char *puntatori_stringhe[NUM_STRINGS];
  char buffer[BUFSIZ];
  char strings[NUM_STRINGS][BUFSIZ];
  int len = NUM_STRINGS;

  for(int i = 0; i < NUM_STRINGS; i++) {

    printf("stringa %d: ", i + 1);
    fgets(buffer, BUFSIZ, stdin); // inserimento della stringa in una stringa buffer
    buffer[strcspn(buffer, "\n")] = '\0'; // aggiunta manuale del terminatore nell'indice ove presente il carattere di invio
    
    strcpy(strings[i], buffer); // copia dell'array buffer all'interno della corrispondente riga dell'insieme di stringhe
    puntatori_stringhe[i] = strings[i]; // assegnamento del puntatore alla stringa appena inserita
    
  }
  //swap(strings[0], strings[1]);

  length_BubSort(puntatori_stringhe, len);
  printf("Ordinamento stringhe:\n");

  for(int i = 0; i < len; i++) {
    printf("Stringa %d: %s\n", i + 1, strings[i]);
  }

  return EXIT_SUCCESS;
}


void length_BubSort(char **s, int len) {
  bool scambio = TRUE;
  while(scambio == TRUE) {
    scambio = FALSE;
    for(int i = 0; i <= len - 2; i++) {
      if(strlen(s[i]) > strlen(s[i+1])) { // se s[i] è più lungo della stringa successiva si scambiano
        printf("confronto tra\n%s\n%s\nLa prima stringa è più lunga, pertanto si scambia\n", s[i], s[i+1]);
        swap(s[i], s[i+1]);
        scambio = TRUE;
      }
    }
  }

}

void swap(char *s1, char *s2) {
  //printf("stringhe prima della conversione: \n%s \n%s \n", s1, s2);
  char tmp[BUFSIZ];
  strcpy(tmp, s1); // copia del contenuto di s1 in tmp
  strcpy(s1, s2);
  strcpy(s2, tmp);

  //printf("stringhe dopo la conversione: \n%s \n%s \n", s1, s2);
}
