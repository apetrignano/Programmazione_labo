#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SIZE 5

int main() {

    double numeri[SIZE];
    double sum = 0;

    for(int i = 0; i < SIZE; i++ ) {
        printf("Inserire numero %d: ", i+1);
        scanf("%lf", &numeri[i]);
    }
    
    for(int i = 0; i < SIZE; i++) {
        sum += numeri[i];
    }
    printf("Media: %lf \n", sum / SIZE);


    return 0;
    
}