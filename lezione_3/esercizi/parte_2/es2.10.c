#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    int size = 0;
    double sum_media = 0;
    double sum_var = 0;
    double media, varianza, dev_std;


    while(size <= 0) {
        printf("Inserire il numero di elementi di cui calcolare la media: ");
        scanf("%d", &size);
    }

    double numeri[size];

    for(int i = 0; i < size; i++ ) {
        printf("Inserire numero %d: ", i+1);
        scanf("%lf", &numeri[i]);
        sum_media += numeri[i];
    }

    media = sum_media / size;

    for(int i = 0; i < size; i++) {
        sum_var += pow(numeri[i] - media, 2);
    }

    varianza = sum_var / size;
    dev_std = sqrt(varianza);

    printf("Media: %lf \n", sum_media / size);
    printf("Varianza: %lf \n", varianza);
    printf("Deviazione std: %lf \n", dev_std);

    return 0;
}