#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int a, b;
    scanf("%d %d", &a, &b);
    int prod = a * b;

    if(prod >= 0){
        printf("il prootto tra i numeri forniti è positivo: %d\n", prod);
    } else printf("il prodotto tra i numeri forniti è negativo: %d\n", prod);

    return 0;
}