#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 7

typedef enum {FALSE, TRUE} bool;

int main() {


    //int v[N] = {2, 5, 8, 3, 6, 13,4};
    int v[N] = {13, 8, 6, 5, 4, 3, 2};
    int tmp, counter = 0;
    bool scambio = TRUE;

    printf("Array non ordinato: \n");
    for(int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    while(scambio == TRUE) {
        scambio = FALSE;
        for(int i = 0; i <= N - 2; i++) {
            if(v[i] > v[i+1]){
            tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = tmp;
            scambio = TRUE;
            counter ++;
            }
            
        }
    }

    printf("Array ordinato: \n");
    for(int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Scambi richiesti: %d \n", counter);
    printf("N^2 / 2: %d \n", N * N / 2);
    return 0;
}