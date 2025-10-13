/*
==============================
Equazioni di secondo grado 
==============================
*/

#include <stdio.h>
#include <math.h>


int main() {

    double a = 0;
    double b, c, delta;
    double sol_1;
    double sol_2;

    while(a == 0) {
        printf("Inserire a: \n");
        scanf("%lf", &a);
    }

    printf("Inserire b: \n");
    scanf("%lf", &b);
    printf("Inserire c: \n");
    scanf("%lf", &c);

    delta = b * b - 4 * a * c;
    // printf("%lf", delta);

    
    if(delta < 0) {
        printf("L'equazione non ha nessuna soluzione nel campo R \n");
    } else if(delta == 0) {
        printf("L'equazione ha una soluzione nel campo R: \nx = %lf \n", -b + sqrt(delta) / (2 * a));
    } else printf("L'equazione ha due soluzioni nel campo R: \nx_1 = %lf \nx_2 = %lf \n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));



    return 0;
}