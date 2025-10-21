#include <stdlib.h>
#include <stdio.h>

int main() {

    double a, b, risultato;
    int operazione;
    
    /* printf("Inserire due numeri reali: \n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("1: somma \n2: sottrazione \n3: moltiplicazione \n4: divisione\n");
    scanf("%d", &operazione); */

    // Punto 1: calcolatrice usa e getta

    // è tutto già scritto

    // Punto 2: calcolatrice usa e getta con gestione degli errori

    /* if(operazione < 1 || operazione > 4) {
        printf("Operazione non deifnita \n");
        return -1;
    } */


    // Punto 3: calcolatrice riutilizzabile

    /* while(1) {


    do {
        printf("Inserire due numeri reali: \n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("1: somma \n2: sottrazione \n3: moltiplicazione \n4: divisione\n");
        scanf("%d", &operazione);
    } while (operazione < 1 || operazione > 4 || (operazione == 4 && b == 0)); // Non visualizza un messaggio di errore così

    if(operazione == 1) {
        risultato = a + b;
    } else if(operazione == 2) {
        risultato = a - b;
    } else if(operazione == 3) {
        risultato = a * b;
    } else {
        risultato = a / b;
    } */

    // Punto 4: calcolatrice riutilizzabile con pulsante off
        while(1) {


    do {

        printf("Inserire due numeri reali: \n");
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("1: somma \n2: sottrazione \n3: moltiplicazione \n4: divisione\n altro tasto: spegni il programma");
        scanf("%d", &operazione);

    } while (operazione == 4 && b == 0); 

    if(operazione == 1) {
        risultato = a + b;
    } else if(operazione == 2) {
        risultato = a - b;
    } else if(operazione == 3) {
        risultato = a * b;
    } else if(operazione == 4){
        risultato = a / b;
    } else {
        printf("Programma interrotto \n");
        return 0;
    }

    // In teoria si potrebbe usare il costrutto switch, ma non lo sopporto

    printf("Risultato: %lf \n", risultato);
}    

    return 0;
}