#include <stdio.h>
#include <stdlib.h>
#include <math.h> //per avere fmod

int main(int argc, char *argv[]) {

    double a, b;

    printf("inserire due valori di tipo double:\n");
    scanf("%lf %lf", &a, &b);
    printf("somma: %f\ndifferenza: %f\nprodotto: %f \nrapporto: %f\nresto: %f", a + b, a - b, a * b, a / b, fmod(a, b));

    return 0;
}