#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char nome[BUFSIZ];
    int i = 0;

    printf("Scrivere un nome: \n");
    scanf("%s", nome);

    while(nome[i] != '\0') {
        i++;
    }
    i--;
    if(nome[i] == 'a' || nome[i] == 'e') {
        printf("Il nome è femminile. \n");
    } else if(nome[i] == 'o' || nome[i] == 'e') {
        printf("Il nome è maschile. \n");
    } else printf("Non è possibile trarre conclusioni. \n");


    return 0;
}