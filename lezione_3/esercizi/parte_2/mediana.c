#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef enum {false, true} bool;

int main() {
    int size = 0;
    int tmp;
    double sum_media = 0;
    double sum_var = 0;
    double media, varianza, dev_std, mediana;
    bool scambio = true;

    while(size <= 0) {
        printf("Inserire il numero di elementi di cui calcolare la media: ");
        scanf("%d", &size);
    }

    double numeri[size];

    for(int i = 0; i < size; i++ ) { // prende in input i numeri e calcola sommatoria per la media
        printf("Inserire numero %d: ", i+1);
        scanf("%lf", &numeri[i]);
        sum_media += numeri[i];
    }

    // Calcolo media
    media = sum_media / size;

    // Calcolo varianza
    for(int i = 0; i < size; i++) {
        sum_var += pow(numeri[i] - media, 2);
    }
    varianza = sum_var / size;

    // Calcolo dev std
    dev_std = sqrt(varianza);

    // Ordinamento e calcolo mediana
    while(scambio == true) {
        scambio = false;
        for(int i = 0; i <= size - 2; i++) {
            if(numeri[i] > numeri[i+1]){
            tmp = numeri[i];
            numeri[i] = numeri[i+1];
            numeri[i+1] = tmp;
            scambio = true;
            // counter ++;
            }
        }
    }

    /*
    =============
    DEBUG
    =============
    printf("Numeri ordinati: \n");
    for(int i = 0; i < size; i++) {
        printf("%lf ", numeri[i]);
    }
    printf("\n"); */

    if(size % 2 == 0) {
        mediana = (numeri[size / 2 - 1] + numeri[(size / 2)]) / 2; // Si sottrae un indice perchè si parte da 0
    } else mediana = numeri[(size + 1) / 2 - 1];


    // Output
    printf("Media: %lf \n", sum_media / size);
    printf("Varianza: %lf \n", varianza);
    printf("Deviazione std: %lf \n", dev_std);
    printf("Mediana: %lf \n", mediana);


    return 0;
}