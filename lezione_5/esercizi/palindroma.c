#include <stdio.h>
#include <stdlib.h>

int palindroma(char *);

int main(int argc, char *argv[]) {

	char s[BUFSIZ];

	fgets(s, BUFSIZ, stdin);

	int pal = palindroma(s);

	if(!pal) {
		printf("la stringa non è palindroma\n");
	} else printf("la stringa è palindroma\n");


	return 0;
}

int palindroma(char *s) { // non bisogna allocare nuova memoria per una copia di s da confrontare
	
	int len = sizeof(s) - 1; // si toglie 1 perchè ultimo carattere è il terminatore
	int i = 0, j = len, result = 1;
	
	do {
		if(s[i] != s[j]) {
					result = 0;
				return result;
		}
		i++;j--;
	} while(i <= len /*/ 2*/);

	return result;
}
