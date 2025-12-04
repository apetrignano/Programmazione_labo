#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
int caricaPatterns(char *, Pattern**); // primo parametro: array di char, una stringa; secondo parametro: array di Pattern, quindi una moltitudine di patterns da caricare

int main() {

  int status[M][N];
  /*
  inizializza(status);

  printf("PRIMA PARTE\n");
  printf("==============\n");
	stampa(status);

  printf("==============\n");
	nuovaGenerazione(status);
	stampa(status);
  printf("==============\n");

  */

  /*for(int i = 0; i < 10; i++) {
    stampa(status);
    printf("==============\n");
    nuovaGenerazione(status);
    sleep (1);
  }*/

  printf("SECONDA PARTE\n");

  Pattern *insieme_patterns;
  char nome_file[BUFSIZ];
  int num_g;

  printf("Nome file: ");
  //fgets(nome_file, BUFSIZ, stdin); // non molto efficace perchè bisogna togliere manualmente il newline
  scanf("%s", nome_file);
  printf("Numero di generazioni: ");
  scanf("%d", &num_g);

  caricaPatterns(nome_file, &insieme_patterns);
  printf("patterns caricati\n");
  //inserisciPattern(status, insieme_patterns) // "errore": in questo modo si presuppone che i pattern debbano essere caricati in una matrice le cui dimensioni sono note a priori, mentre invece credo che serva che anche essa sia allocata dinamicamente
  for(int i = 0; i < num_g; i++) {
    inserisciPattern(status, insieme_patterns[i]);
  }

  int counter = 0;

    printf("==============\n");
  while(counter < num_g) {

    stampa(status);
    nuovaGenerazione(status);
    sleep(1);
    counter++;
    printf("==============\n");
  }

  free(insieme_patterns);
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
    printf("riga %d\n", i);
    for(int j = enter.j; j < enter.w; j++) {
      griglia[i][j] = enter.mat[i - enter.i][j - enter.j];
    }
  }
  //free(enter);
}




int caricaPatterns(char *input, Pattern **insieme) { // puntatore perchè è un insieme di Patterns, non uno singolo

  FILE *f_r = fopen(input, "r");
  
  if(f_r == NULL) {
    fprintf(stderr, "Open error!\n");
    exit(34);
  }

  int num_pattern;
  fscanf(f_r, "%d", &num_pattern); // il primo dato del file è sicuramente il numero di patterns; si assume che il file stesso sia formattato correttamente, quindi niente controllo dell'effettivo numero di patterns
  //printf("salvato il numero di patterns presenti nel file, i quali sono %d\n", num_pattern);

  *insieme = (Pattern*) malloc(num_pattern * sizeof(Pattern)); // forse è qui il problema: non si sa ancora il numero di bytes realmente occupati da ogni Pattern, perchè la matrice non ha un numero definito di elementi
  //printf("creato insieme: dimension: %lu\n", sizeof(Pattern));
  Pattern *array_semplice = (Pattern*) malloc(num_pattern * sizeof(Pattern));

  for(int i = 0; i < num_pattern; i++) { // bisogna inserire un ciclo che legga gli elementi della matrice
    printf("ciclo %d\n", i + 1);
    fscanf(f_r, "%d %d", &array_semplice[i].h, &array_semplice[i].w); // legge i due numeri successivi per allocare dinamicamente la matrice con il pattern
    
    // già questo comando non viene eseguito mi sembra
    printf("letti i due numeri, creata una mat %d x %d\n", array_semplice[i].h, array_semplice[i].w);

    array_semplice[i].mat = (int**) malloc(array_semplice[i].h * sizeof(int*)); // creazione di h puntatori, ognuno ad una riga della matrice
    //printf("creazione di puntatori\n");
    // sizeof(int*) perchè poi gli elementi non sono int, bensì puntatori ad int, nella malloc successiva si utilizzerà sizeof(int)
    for(int j = 0; j < array_semplice[i].h; j++) {
     // printf("parte del ciclo\n");
      array_semplice[i].mat[j] = (int*) malloc(array_semplice[i].w * sizeof(int)); // creazione di puntatore alla colonna
    }
    
    //ciclo che legge h * w elementi e li inserisce nella matrice delle medesime dimensioni (del pattern) appena allocata
    //printf("inizio del ciclo\n");

    for(int j = 0; j < array_semplice[i].h; j++) {
      for(int k = 0; k < array_semplice[i].w; k++) {
        //printf("verifica\n");
        fscanf(f_r, "%d", &array_semplice[i].mat[j][k]); // attualmente sta qui l'errore
        //printf("verifica 2\n");
        printf("letto int = %d da inserire nella matrice in posizione [%d][%d]\n", array_semplice[i].mat[j][k], j, k);
      }
    }

    // lettura delle coordinate da cui partire per inserire il pattern nella matrice

    fscanf(f_r, "%d %d", &array_semplice[i].i, &array_semplice[i].j);
    printf("inserito anche da dove partire per l'inserimento, ossia da v[%d][%d]\n", array_semplice[i].i, array_semplice[i].j);
  
    printf("ciclo %d finito correttamente\n", i + 1);
  }
  if(fclose(f_r) != 0) {
    fprintf(stderr, "close error!\n");
    exit(35);
  }

  *insieme = array_semplice;
  return num_pattern;
}
