#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char stringa[256];
    char target;
    double length = 0;
    double frequency = 0;
    int i = 0; // vorrei poter togliere questa i, non è necessaria in realtà, ma l'indice non può essere di tipo double
    while(1) { // Ho tolto stringa[0] != '\n'

        printf("Inserire una stringa:\n");
        fgets(stringa, 256, stdin);
        if(stringa[0] == '\n') break; // Sinceramente non so se va bene mettere qui un break, ma non vedo altro modo per bloccare subito il blocco
        printf("Ora inserire il carattere di cui calcolare la frequenza:\n");
        target = getchar();
        //scanf("%c", &target); getchar();
        while(stringa[i] != '\n') {
            if(stringa[i] == target) {
                frequency++;
            }
            length++;
            i++;
        }   

        printf("Frequenza del carattere %c: %lf\n", target, frequency / length);
        getchar();

    }

    return 0;
}