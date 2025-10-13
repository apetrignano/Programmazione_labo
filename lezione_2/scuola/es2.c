#include <stdio.h>
#include <math.h>

int main() {

    int m;
    int counter = 0;
    int sum_linear = 0;
    int sum_algo_linear = 0;
    int sum_square = 0;
    int sum_algo_square = 0;
    int sum_cubic = 0;
    int sum_algo_cubic = 0;

    while(m < 1) {
        printf("Inserire un int maggiore o uguale a 1: \n");
        scanf("%d", &m);
    }

    // Calcolo somma lineare con approccio iterativo
    while(counter != m + 1) {
        sum_linear += counter;
        counter ++;
    }

    

    counter = 0;

    // Calcolo somma lineare con formula
    sum_algo_linear = m  * (m + 1) / 2;


    // Calcolo somma quadratica con approccio iterativo
    while(counter != m + 1) {
        sum_square += counter * counter;
        counter ++;
    } 

    counter = 0;

    /*
    Si prova ad usare la funzione pow
    while(counter != m + 1) {
        sum_square += pow((double)counter, 2);
        counter ++;
    }*/

    // Calcolo somma quadratica con la formula
    sum_algo_square = m * (m + 1) * (2 * m + 1) / 6;

    // Calcolo somma subica con approccio iterativo
    while(counter != m + 1) {
        sum_cubic += counter * counter * counter;
        //sum_cubic += pow(counter, 3);
        counter ++;
    }

    // Calcolo somma cubica con la formula

    sum_algo_cubic = m * m * (m + 1) * (m + 1) / 4;


    printf("la somma lineare dei primi %d numeri naturali è: %d \n", m, sum_linear);
    printf("la somma lineare dei primi %d numeri naturali (ottenuta tramite la formula 1) è: %d \n", m, sum_algo_linear);
    printf("la somma quadratica dei primi %d numeri naturali è: %d \n", m, sum_square);
    printf("la somma quadratica dei primi %d numeri naturali (ottenuta tramite la formula 2) è: %d \n", m, sum_algo_square);
    printf("la somma cubica dei primi %d numeri naturali è: %d \n", m, sum_cubic);
    printf("la somma cubica dei primi %d numeri naturali (ottenuta tramite la formula 3) è: %d \n", m, sum_algo_cubic);


    


    return 0;
}