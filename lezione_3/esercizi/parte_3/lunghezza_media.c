#include <stdlib.h>
#include <stdio.h>

int main() {

    double media = 0;
    double sum = 0;
    int counter = 0;
    char stringa[256];


    do {
        printf("Inserire la stringa: \n");
        fgets(stringa, 256, stdin);
        for(int i = 0; stringa[i] != '\0'; i++){
            sum ++;
        }
        sum --; // si toglie il carattere \n
        counter ++;


    } while(stringa[0] != '\n');
    // counter --; // viene conteggiata anche la stringa con il carattere di stop, questo non so come evitarlo
    media = sum / counter;

    printf("La lunghezza media delle stringhe inserite è %lf \n", media);
    return 0;

}