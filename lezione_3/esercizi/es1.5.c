#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char nome[BUFSIZ];
    char check;
    int counter = 0;

    printf("Inserire la stringa: \n");
    scanf("%s", nome); getchar();
    printf("Inserire il carattere: \n");
    //scanf("%c", &check);
    check = getchar(); getchar();

    while(nome[counter] != '\0') {
        
        //si parte dall'indice 0, se è a posto va già a quello sucessivo
        

        /*printf("counter: %d \n", counter);
        printf("lettera letta: %c \n", nome[counter]);*/

        counter ++;

    }
    /*printf("counter: %d \n", counter);
    printf("lettera nel counter: %c \n", nome[counter -1]);
    printf("check: %c \n", check);*/

    if(nome[counter-1] == check) { // chiaramente l'ultimo indice salvato è quello del terminatore, che effettivamente rimane lì, quindi si considera il penultimo
        printf("Sì \n");
    } else printf("No \n");

    return 0;
}