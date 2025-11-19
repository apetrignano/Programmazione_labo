#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef enum{FALSE, TRUE} bool;

void bubble_sort(char**, int, bool);
void swap(char*, char*);

int main() {

  char *puntatori_stringhe[N];
  char buffer[BUFSIZ];
  char s[N][BUFSIZ];
  bool scambio = TRUE;
  
  for(int i = 0; i < N; i++) {
    printf("Inserire la stringa: ");
    fgets(buffer, BUFSIZ, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    strcpy(s[i], buffer);
    puntatori_stringhe[i] = s[i];
  }


  bubble_sort(puntatori_stringhe, N, scambio);

  /*for(int i = 0; i < N - 2; i++) {
    printf("confronto tra la stringa %d e la successiva:\n", i);
    printf("%d\n", strcmp(s[i], s[i+1]));
  }*/

  for(int i = 0; i < N; i++) {
    printf("stringa %d: %s\n", i + 1, s[i]);
  }

  return 0;
}

void bubble_sort(char **s, int len, bool scambio) {
  while(scambio == TRUE) {
    scambio = FALSE;
    for(int i = 0; i < len - 2; i++) {
      if(strcmp(s[i], s[i+1]) > 0) { // se s[i] è più lungo della stringa successiva si scambiano
        swap(s[i], s[i+1]);
        scambio = TRUE;
      }
    }
  }
}

void swap(char *a, char *b) {
  char *tmp = a;
  a = b;
  b = tmp;
}
