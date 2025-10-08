#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    int a;
    double b;
    float c;

    printf("inserire un valore intero:\n");
    scanf("%d", &a);
    printf("valore inserito è %d\n", a);

    printf("fare la stessa cosa con un double:\n");
    scanf("%lf", &b);
    printf("valore inserito di tipo double è %f\n", b);

    /*printf("fare la stessa cosa con un float:\n");
    scanf("%f", &c);
    printf("valore inserito di tipo float è %f\n", c);*/

    return 0;
}