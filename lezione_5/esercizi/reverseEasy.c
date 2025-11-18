#include <stdlib.h>
#include <stdio.h>

void reverseEasy(char*, char*);

int main() {
	

void reverseEasy(char *s, char* srev){
    int length, c;
    char *end = s;
    length = strlen(s);
    for (c = 0; c < length - 1; c++)
        end++;

    for (c = 0; c < length; c++){
        *srev = *end;
        srev++;
        end--;
    }
}
