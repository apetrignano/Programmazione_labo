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
	
	int len = 0; 
  while(s[len] != '\n') {
    len++;
  }
  //
  printf("lunghezza della stringa: %d\n", len);
	int i = 0, j = len - 1, result = 1;

	do {
    printf("confronto tra s[%d] = %c e s[%d] = %c\n", i, s[i], j, s[j]);
		if(s[i] != s[j]) {
					result = 0;
				return result;
		}
		i++;j--;
	} while(i < len / 2 + 1);

	return result;
}
