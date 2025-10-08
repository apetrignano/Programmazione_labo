#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[]) {

    float num = FLT_MIN; //si assegna il valore min
    float max = FLT_MAX; //si assegna il valore max
    float divide = num / max;

    printf("Valore della variabile num = %f\n", num); //visualizza il falore di float
    printf("Valore della variabile piccola divisa la grande: %f\n", divide); //visualizza il rapporto

    //esce lo stesso numero piccolo, non so se è corretto

    return 0;
}