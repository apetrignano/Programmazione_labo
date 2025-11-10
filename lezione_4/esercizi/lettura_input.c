#include <stdlib.h>
#include <stdio.h>

int main() {
    int read_int();
    int a, b, sum;

    a = read_int();
    b = read_int();

    printf("%d + %d = %d\n", a, b, a + b);

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