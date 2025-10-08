#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    float a = FLT_MAX;
    double b = DBL_MAX;
    
    printf("valore float positivo maggiore: %g \nvalore double positivo maggiore: %g\n", a, b);

    return 0;
}