#include <stdio.h>
#include <ctype.h>

int main () {

    // Lettere maiuscole e minuscole

    /*
    char c;

    printf("Inserire un carattere \n");
    c = getchar();
    
    if(isalpha(c) == 0) {
        printf("Il carattere %c non è alfabetico\n", c);
        return -1;
    }
    if(isupper (c) == 0) {
        printf("Il carattere %c è una lettera minuscola \n", c);
    } else printf("il carattere %c è una lettera maiuscola \n", c);

    */

    // Lettere maiuscole e minuscole iterate

    /*char c;

    while(c != '\n' ){

    printf("Inserire un carattere \n");
    c = getchar(); 

    //if(c == '\n') goto stop;

    getchar();
    

    if(isalpha(c) == 0) {
        printf("Il carattere %c non è alfabetico\n", c);
    } else if(isupper (c) == 0) {
        printf("Il carattere %c è una lettera minuscola \n", c);
    }
    else printf("il carattere %c è una lettera maiuscola \n", c);
    }
    */


    /*stop: */ 

    // Conversione in maiuscola o minuscola

    char c;
    int selector;

    printf("Inserire un carattere alfabetico: \n");
    scanf("%c", &c);

    if(isalpha(c) == 0) {
        // printf("Carattere digitato: %c \n", c);
        printf("Errore, non si è digitato un carattere alfabetico \n");
        return -1;
    } else {

        printf("Conversione in maiuscola o minuscola? (1 = maiuscola, altro numero = minuscola) \n");
        scanf("%d", &selector);
        
        if(selector == 1) {
            printf("Carattere maiuscolo: %c \n", toupper(c));
        } else {
            printf("Carattere minuscolo: %c \n", tolower(c));
        }
    }

    
    /*
    else if (isupper(c) == 0){
        printf("Carattere convertito in maiuscolo: %c \n", toupper(c));
    } else {
        printf("Carattere convertito in minuscolo: %c \n", tolower(c));
    }
    */

    // Conversione in maiuscola o minuscola con controllo dell'errore

    return 0;

}