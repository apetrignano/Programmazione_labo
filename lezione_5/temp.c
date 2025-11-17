#include <stdio.h>
#include <stdlib.h>

int main() {

	int N = 6;

	struct persona {
		char fn[N];
		char sn[N];
		char ssn[N];
	};

	struct persona personaTest;

	printf("dimensione del tipo persona: %zu\n", sizeof(personaTest));
	printf("indirizzo di fn: %p\n", &personaTest.fn);
	printf("indirizzo di sn: %p\n", &personaTest.sn);
	printf("indirizzo di ssn: %p\n", &personaTest.ssn);


	return 0;
}
