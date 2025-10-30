#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Deve leggere in ingresso una stringa inserita da utente, poi un carattere;
bisogna calcolare la frequenza di quel carattere all'interno della stringa;
frequenza definita come rapporto (di tipo double) tra # di occorrenze del carattere e la lunghezza della stringa
*/

int main(int argc, char *argv[]) {

    char stringa[256];
    char target;
    int length = 0;
    double frequency = 0;
    int i = 0; // vorrei poter togliere questa i, non è necessaria in realtà, ma l'indice non può essere di tipo double

    printf("Inserire una stringa:\n");
    fgets(stringa, 256, stdin);
    printf("Ora inserire il carattere di cui calcolare la frequenza:\n");
    // scanf("%c", &target);
    target = getchar();
    while(stringa[length] != '\n') {
        if(stringa[length] == target) {
            frequency++;
        }
        length++;
        i++;
    }

    printf("Frequenza del carattere %c: %lf\n", target, frequency / length);
    //printf("In forma frazionaria: %d / %d\n", (int)frequency, (int)length);

    return 0;
}