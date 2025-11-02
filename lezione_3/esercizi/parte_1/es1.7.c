#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char string[BUFSIZ];

    while(string[0] != '\n') {

    printf("Inserire la stringa: ");
    fgets(string, sizeof(string), stdin);
    printf("%s", string);
    
    }

    return 0;
    
}