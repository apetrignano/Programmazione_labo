#include <stdlib.h>
#include <stdio.h>

int main() {

    // Punto 1: con le divisioni

    /* int a = 2;
    int b = 4;
    int mcd, tmp;

    while(b != 0) {

        tmp = b;
        b = a % b;
        a = tmp;
    } */

    // Punto 2: con input da utente

    int a, b;
    int mcd, tmp;
    int i = 0;
    printf("Inserire i due numeri: \n");
    scanf("%d", &a);
    /* if(a < 0) {
        printf("a deve essere positivo");
        return -1;
    } */
    scanf("%d", &b);
    /* if(b < 0) {
        printf("b deve essere positivo");
        return -1;
    } */

    // printf("%d, %d \n", a, b);

    // Punto 3: messaggio di errore

    if(a < 0 || b < 0) {
        printf("Errore: entrambi i numeri devono essere positivi");
        return -1;
    }

    while(b != 0) {

        tmp = b;
        b = a % b;
        a = tmp;
        i++;
    }


    printf("M.C.D: %d raggiunto in %d divisioni\n", a, i);




    return 0;
}