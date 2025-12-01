#include <stdlib.h>
#include <stdio.h>

#define M 3
#define N 3 

void stampa(int [M][N]);
void inizializza(int [M][N]);
int vicini(int[M][N], int, int); // contatore di celle vicine vive
void nuovaGenerazione(int[M][N]); // modifica la matrice secondo certi criteri

int main() {

	int status[M][N] = {    
				{0, 0, 1},
				{0, 1, 0},
				{1, 0, 0}
	};
	

	stampa(status);
	int j = 1;

	//printf("%c\n", status[j - 1][j + 1]);
	//int numero = vicini(status, 2, 2);

	//printf("numero vivi: %d\n", numero);

	nuovaGenerazione(status);
	
	stampa(status);

	return 0;

}


void stampa(int status[M][N]) {

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			//printf("%c", status[i][j]);
			if(status[i][j] == 1) {
				printf("#");
			} else printf(" ");
		}
		printf("\n"); // va a capo dopo la fine della riga
	}
}

int vicini(int stato[M][N], int riga, int colonna) {

	int counter = 0;

	for(int i = riga - 1; i <= riga + 1; i++) { // problema: deve entrare nel loop anche se le due condizioni ultime non sono rispettare, però non deve contare ciò che viene letto
		//printf("riga %d\n", i);
		for(int j = colonna - 1; j <= colonna + 1; j++) {
			//printf("cella a[%d][%d] = %d\n", i, j, stato[i][j]);
			if(stato[i][j] == 1 && (i >= 0 && i <= riga + 1 && i < M) && (j >= 0 && j <= colonna + 1 && j < N)) {
				counter++;
				//printf("cella viva in posizione a[%d][%d]\n", i, j);
			}
			//printf("arrivato alla colonna %d\n", j);
		}

	}
	if(stato[riga][colonna] == 1) counter--;

	return counter;

}

void nuovaGenerazione(int status[M][N]) {
	int contatori[M * N];
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			int num_vv = vicini(status, i, j);
			if((num_vv < 2 || num_vv > 3) && status[i][j] == 1) { // se ha meno di 2 o più di 3 celle vive vicine la cella è morta
				status[i][j] = 0;
			} else if(status[i][j] == 0 && num_vv == 3) { // se è morta ed ha esattamente 3 celle vive vicine la cella vive
				status[i][j] = 1;
			}  //else status[i][j] = 1;
		}
	}
	for(int i = 0; i < M * N; i++) {
		contatori[i] = vicini(status, 0, i);
	}

	


}
