#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
in ingresso una stringa inserita da utente, poi un'altra stringa, deve 
stampare sì se la seconda stringa è in qualche modo contenuta nella prima, 
no altrimenti
*/
/*
Con questo esercizio sto avendo difficoltà
*/
int main(int argc, char *argv[]) {

    char string[256];
    char substring[256];
    int flag = 0; // 0 significa no, 1 invece sì

    printf("Inserire la stringa principale:\n");
    fgets(string, 256, stdin);
    printf("Inserire la sottostringa da cercare:\n");
    fgets(substring, 256, stdin);

    /*while(substring[j] != '\n') {
    while(substring[j] != string[i] && string[i] != '\n'){ // scorre string fino a quando non si trova un carattere uguale, oppure alla fine della stringa
        printf("%c e %c sono caratteri diversi\n", substring[j], string[i]);
        i++;
    }
    printf("primo carattere uguale: %c\n", string[i]);
     // continua il ciclo fino alla fine della sottostringa
    while(substring[j] == string[i]) { // scorre contemporaneamente le stringhe fino a quando sono uguali
        printf("%c e %c sono caratteri uguali\n", substring[j], string[i]);
        i++; j++;
        if(substring[j] == '\n') {
            flag = 1;
        }
    }
    
}*/

    for(int i = 0; i != '\n'; i++) {
        int j = 0;

        while(string[])
    }

    
        if(flag == 1) printf("Sì\n");
            else printf("No\n");

    return 0;
}