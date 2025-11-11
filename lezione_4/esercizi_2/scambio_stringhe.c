#include <stdlib.h>
#include <stdio.h>

int main() {

	char s1[] = "Contenuto 1";
	char s2[] = "Contenuto 2";
	char *pointerA = &(s1[0]), *pointerB = &(s2[0]), *pointerTemp;
	//char *pointerA = &s1, *pointerB = &s2, *pointerTemp;

	pointerTemp = pointerA;
	pointerA = pointerB;
	pointerB = pointerTemp;

	printf("Stringa 1: %s\nStringa 2: %s\n", *pointerA, *pointerB);
	
	return 0;
}
