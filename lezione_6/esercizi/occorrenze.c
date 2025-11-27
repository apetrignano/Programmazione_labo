#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int occ(char *, char); // restituisce il num di occorrenze del carattere passato come parametro
int main(int argc, char *argv[]) {

  if(argc != 1) {
    printf("Usage: ./%s\n", argv[0]);
    return -1;
  }

  char stringa[] = "cigargarozaoz.";
  char lett = 'z';

  printf("numero occorrente di %c: %d\n", lett, occ(stringa, lett));




  return 0;
  
}

int occ(char *string, char car_seek) {
  
  if(string == NULL) { // se la stringa non ha caratteri allora si ritorna -1
    return -1;
  }
  if(string[0] == 0) { // caso base
    return 0;
  }
  if(string[0] == car_seek) {
    return occ(string + 1, car_seek) + 1;
  } else return occ(string + 1, car_seek);

  //printf("string = %s\n", string + 1);
}
