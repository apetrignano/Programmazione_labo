#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    
    char n1 = 'a';
    char n2;
    /*int n3 = INT_MAX;
    int n4 = n3 + 1; //dovrebbe dare overflow
    */

    printf("Valore di %c è %d \n", n1, n1);

    n2 = n1 - 32;

    printf("Valore di %c è %d \n", n2, n2);

    //printf("Valore di %c è %d \n", n4, n4);

    /*
    per i valori in input: scanf("%d", &numero);
    */

    return 0;
}
