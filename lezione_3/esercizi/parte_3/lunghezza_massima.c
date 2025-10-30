#include <stdlib.h>
#include <stdio.h>

int main() {

    char stringa[256];
    int max = 0;
    int num;

    while(stringa[0] != '\n') {

    printf("Inserire la stringa: \n");
    fgets(stringa, 256, stdin);
    for(int i = 0; stringa[i] != '\n'; i++) {
        if (i >= max) { 
            max = i + 1; // devo aggiungere 1 perchè con gli array si parte da 0, e se questa condizione si realizza la stringa ha lunghezza i + 1, non i, in quanto il primo carattere è il primo, non lo zeresimo
            // max++;
        }
    }
    }

    printf("La stringa di lunghezza massima è lunga %d caratteri.\n", max);

    return 0;
}