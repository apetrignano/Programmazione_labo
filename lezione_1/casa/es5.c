#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    char cM = CHAR_MAX;
    char cm = CHAR_MIN;
    int iM = INT_MAX;
    int im = INT_MIN;

    printf("char max = %c \nchar min = %c \nint max = %d \nint min = %d\n", cM, cm, iM, im);

    //per codificare un valore int , il cui valore massimo è 2147483648, servono log2(max)+1 bit, dato che il valore pos più alto ha un bit in meno del numero negativo più grande, quindi 31 + 1 bit

    return 0;

}