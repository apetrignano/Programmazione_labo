#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    char stringa[256];
    int i = 0;

    printf("Inserire la stirnga da convertire:\n");
    fgets(stringa, 256, stdin);

    while(stringa[i] != '\n') {
        stringa[i] = toupper(stringa[i]);
        i++;
    }

    printf("Stringa convertita: \n%s", stringa);

    return 0;
}