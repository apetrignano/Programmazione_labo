#include <stdlib.h>
#include <stdio.h>



int main() {

    int read_int(), n = read_int();
    int fattoriale(int n), fact = fattoriale(n);
    int cypher_count(int fattoriale);

    printf("%d! = %d\n", n, fact);
    printf("numero di cifre di %d: %d\n", fact, cypher_count(fact));

    return 0;
}

int read_int() {
    int num;

    do {
        printf("Inserire numero intero > 0:\n");
        scanf("%d", &num);
    } while(num <= 0);

    return num;

}

int fattoriale(int n) {

    int i;
    int res = 1;
     for(i = 1; i <= n; i++) {
        res *= i;
    }

    return res;
}

int cypher_count(int fattoriale) {

    int counter = 0;

    while(fattoriale != 0) {
        fattoriale /= 10;
        counter ++;
    }

    return counter;

}