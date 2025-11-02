#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    int size = 0;
    double sum = 0;
    // double media;

    while(size <= 0) {
        printf("Inserire il numero di elementi di cui calcolare la media: ");
        scanf("%d", &size);
    }

    double numeri[size];

    for(int i = 0; i < size; i++ ) {
        printf("Inserire numero %d: ", i+1);
        scanf("%lf", &numeri[i]);
        sum += numeri[i];
    }

    // media = sum / size;

    printf("Media: %lf \n", sum / size);

    return 0;
}