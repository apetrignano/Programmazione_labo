#include <stdio.h>
#include <stdlib.h>

int lung(char *); // Accetta in ingresso una stringa e ne restituisce la lunghezza, implementazione della funzione deve essere ricorsiva

int main() {

	char s[] = "ciao";

	//printf("%c\n", s + 1); // in questo caso non decade ancora a puntatore

	printf("lunghezza stringa: %d\n", lung(s));

	return 0;
}

int lung(char *s) {
	if(s[0] == 0) {
		return 0; 
	}

	printf("passo ricorsivo\n");
	
	return lung(s + 1) + 1;
}
