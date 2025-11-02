#include <stdio.h>

//#define NOT_FOUND -1

int main() {
    int n, k, i;
    int result = -1;
    
    do {
        printf("n, k: ");
        scanf("%d %d", &n, &k);
    } while(n <= 0 || k <= 0); // Errore, appena una delle due condizioni non è rispettata il ciclo ricomincia
    /*while(!(n <= 0 && k <= 0))*/

    for(i = 1; i < n; i++) { // Errore, altrimenti si avrebbe divisione per 0
        if(/*i % k == 0*/ k % i == 0) { // Errore, bisogna dividere k per i, non il contrario, così non si trova il divisore di k
            result = i;
        }
    }

    for(i = n - 1; i >= 1 /*result == -1 || NOT_FOUND*/; i--) {
        if(k % i = 0){
            result = i;
            break; // In teoria non andrebbe bene, perchè viola la programmazione strutturata
            //printf("mcd = %d \n", result);
            //exit(0);
        }
    }

    if(result == -1 /*|| NOT_FOUND*/) {
        printf("nope \n");
    } else {
        printf("mcd = %d \n", result);
    }
    /*Ottimizzazione: si parte dal numero più alto possibile,
     e il primo # che è divisibile per k è il numero cercato*/

 
    return 0;
}

// Olè, ho trovato tutti gli errori da solo