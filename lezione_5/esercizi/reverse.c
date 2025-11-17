#include <stdio.h>
#include <stdlib.h>

void reverse(char *, char *);
int main(int argc, char *argv[]) {


	char str1[BUFSIZ], str2[BUFSIZ];

	printf("Inserire una stringa: ");
	if(fgets (str1, BUFSIZ, stdin) == NULL) {
		printf("Errore in lettura\n");
		return -1;
	}

	int i = 0;
	for(; str1[i] != '\n'; i++);
	str1[i] = '\0';

	reverse(str1, str2);


	printf("stringa al contrario:\n%s\n", str2); 



	return 0;
}

// procedura: legge la prima stringa e la scrive in ordine inverso nella seconda stringa, tutte e due della stessa dimensione

void reverse(char *s, char *t) {
	
	int end = 0;
	
	while(s[end]) { // scorre l'array fino ad arrivare alla fine, 
		end++;
	}

	end--; // sinceramente non mi viene in mente un modo per evitare questa istruzione

	for(int i = 0; end >= 0; end--, i++) {
		t[i] = s[end];
		printf("assegnamento di s[%d](%c) a t[%d](%c)\n", end, s[end], i, t[i]);
	}

}
