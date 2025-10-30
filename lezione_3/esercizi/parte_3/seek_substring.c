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
    int i = 0, j = 0;

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

    while(substring[j] != '\0' && string[i] != '\0') {
        while(substring[i] != string[j] && substring[i] != '0' && string[j] != '\0') { // scorre, tenendo fissa la substring, fino a trovare i due caratteri coincidenti
            printf("Confronto tra %c e %c, non sono uguali\n", substring[j], string[i]);
            j++;
        }
        printf("Raggiunto primo carattere uguale: %c \n", substring[i]);
        while(substring[i] == string[j]) { // confronta per vedere se da quel momento in poi i caratteri coincidono
            printf("Confronto tra %c e %c, i caratteri coincidono\n", substring[i], string[j]);
            j++; i++;
            if(substring[i] == '\0') { // coincidono fino alla fine: vuol dire che sono uguali
                flag = 1;
                printf("flag\n");
            } // se flag == 1 si esce dal ciclo, dato che sicuramente substring[j] == '\0'
        } if(!flag) i = 0;
    }

    if(flag) printf("Sì\n");
    else printf("No\n");

    return 0;
}