#include <stdio.h>
#include <stdlib.h>

int equals(char *s, char *t); // return è positivo se le stringhe sono uguali, nullo se non lo son

int main(int argc, char *argv[]) {
	
	char a[BUFSIZ], b[BUFSIZ];

	printf("prima stringa: ");
	//fgets(a, BUFSIZ, stdin);
	if(fgets(a, BUFSIZ, stdin) == NULL) {
		printf("Scrivere una stringa\n");
		return -1;
	}

	printf("seconda stringa: ");
	//fgets(b, BUFSIZ, stdin);
	if(fgets(b, BUFSIZ, stdin) == NULL) {
		printf("scrivere una stringa\n");
		return -1;
	}

	// problema: mi richiede un \n in più per continuare il programma
	

	int flag = equals(a, b);

	if(!flag) {
		printf("le due stringhe non sono uguali\n");
	} else printf("le due strighe sono uguali\n");

	return 0;
}

int equals(char *s, char *t) {

	int i = 0;
	int flag = 1;
	while(s[i] || t[i] || flag) { // fa il confronto fino a quando non si arriva alla fine di una delle due stringhe oppure fino a quando non si trova un carattere diverso
		if(s[i] != t[i]) flag = 0;
		i++;
		}
	if(s[i] && !t[i] || !s[i] && t[i]) flag = 0;
	return flag;
}
