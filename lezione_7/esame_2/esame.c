#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>

#define M 5
#define N 5 

typedef struct {
  int h;
  int w;
  int **mat; // puntatore ad array di puntatori, la dimensione per ora non è nota, in quanto non sono stati inizializzati h e w, darebbe undefined behaviour
  int i;
  int j;

} Pattern;

// funzioni prima parte
void stampa(int [M][N]);
void inizializza(int [M][N]);
int vicini(int[M][N], int, int); // contatore di celle vicine vive
void nuovaGenerazione(int[M][N]); // modifica la matrice secondo certi criteri
void inizializza(int[M][N]); // si "genera" una griglia in modo randomico

// funzioni seconda parte
void inserisciPattern(int[M][N], Pattern);
int caricaPatterns(char *, Pattern*); // primo parametro: array di char, una stringa; secondo parametro: array di Pattern, quindi una moltitudine di patterns da caricare

int main() {

  int status[M][N];
  inizializza(status);

  printf("PRIMA PARTE\n");
  printf("==============\n");
	stampa(status);

  printf("==============\n");
	nuovaGenerazione(status);
	stampa(status);
  printf("==============\n");

  /*for(int i = 0; i < 10; i++) {
    stampa(status);
    printf("==============\n");
    nuovaGenerazione(status);
    sleep (1);
  }*/

  printf("SECONDA PARTE\n");

  Pattern *insieme_patterns;
  
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

	for(int i = riga - 1; i <= riga + 1; i++) {
		//printf("riga %d\n", i);
		for(int j = colonna - 1; j <= colonna + 1; j++) {
			//printf("cella a[%d][%d] = %d\n", i, j, stato[i][j]);
			if(stato[i][j] == 1 && (i >= 0 && i < M) && (j >= 0 && j < N)) {
				counter++;
				//printf("cella viva in posizione a[%d][%d]\n", i, j);
			}
			//printf("arrivato alla colonna %d\n", j);
		}

	}
	if(stato[riga][colonna] == 1) counter--; // se lo stato alle coordinate del centro è vivo, il contatore scende di 1

	return counter;

}

void nuovaGenerazione(int status[M][N]) {

  int contatori[M][N];

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      contatori[i][j] = vicini(status, i, j);
      //printf("a[%d][%d] = = %d\n", i, j, contatori[i][j]); // il numero di celle vive è conteggiato in modo corretto
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(status[i][j] == 1 && (contatori[i][j] < 2 || contatori[i][j] > 3)) {
        //printf("la cella a[%d][%d] ha valore %d, quindi diventa 0\n", i, j, contatori[i][j]);
        status[i][j] = 0;
      } else if(status[i][j] == 0 && contatori[i][j] == 3) {
        status[i][j] = 1;
      }
    }
  }
}



void inizializza(int stato[M][N]) {

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      stato[i][j] = rand();
      if(stato[i][j] % 2 == 0) {
        stato[i][j] = 1;
      } else stato[i][j] = 0;
    }
  }
}

void inserisciPattern(int griglia[M][N], Pattern enter) {

  for(int i =  enter.i; i < enter.h; i++) {
    for(int j = enter.j; j < enter.w; j++) {
      griglia[i][j] = enter.mat[i - enter.i][j - enter.j];
    }
  }
}




int caricaPatterns(char *input, Pattern *insieme) { // puntatore perchè è un insieme di Patterns, non uno singolo

  FILE *f_r = fopen(input, "r"); // apri il file passato come parametro
  
  if(f_r == NULL) {
    fprintf(stderr, "Open error!\n");
    exit(34);
  }

  int num_pattern;
  fscanf(f_r, "%d", &num_pattern); // il primo dato del file è sicuramente il numero di patterns; si assume che il file stesso sia formattato correttamente, quindi niente controllo dell'effettivo numero di patterns

  insieme = (Pattern*) malloc(num_pattern * sizeof(Pattern)); // si è creato un vettore allocato dinamicamente dell'esatta dimensione

  for(int i = 0; i < num_pattern; i++) { // bisogna inserire un ciclo che legga gli elementi della matrice
    fscanf(f_r, "%d %d", &insieme[i].h, &insieme[i].w); // legge i due numeri successivi per allocare dinamicamente la matrice con il pattern
    insieme[i].mat = (int**) malloc(insieme[i].h * insieme[i].w * sizeof(int)); // creazione di matrice h * w di int
    
    //ciclo che legge h * w elementi e li inserisce nella matrice delle medesime dimensioni (del pattern) appena allocata

    for(int j = 0; j < insieme[i].h; j++) {
      for(int k = 0; k < insieme[i].w; k++) {
        fscanf(f_r, "%d", &insieme[i].mat[j][k]);
      }
    }
  
  }
  if(fclose(f_r) != 0) {
    fprintf(stderr, "close error!\n");
    exit(35);
  }

  return num_pattern;
}
