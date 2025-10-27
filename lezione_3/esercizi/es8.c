/*eco con stringhe*/

// es 1.3 ed 1.4 nel file di esercizi
#include <stdlib.h>
#include <stdio.h>

#define LENGTH 100

int main() {

    char frase[LENGTH+1];
    int counter = 0;
    /*printf("Inserire fase: \n");
    fgets(frase, sizeof(frase), stdin);
    printf("Frase ripetuta con fgets: \n%s", frase);*/
    
    /*lunghezza della stringa*/

    printf("Inserire una stringa: \n");
    scanf("%s", frase);
    for(int i = 0; i < LENGTH + 1 ; i++) {
        if(frase[i] != '\0') {
            counter ++;
        }
    }
    printf("dimensione della stringa: %d \n", counter);



    return 0;
}