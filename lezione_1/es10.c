#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int a, b;

    printf("inserire due valori di tipo int:\n");
    scanf("%d %d", &a, &b);

    printf("somma: %d\ndifferenza: %d\nprodotto: %d \nrapporto: %d\nresto: %d", a + b, a - b, a * b, a / b, a % b);
    return 0;
}