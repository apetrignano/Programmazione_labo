#include <stdlib.h>
#include <stdio.h>

// es1.1 ed es1.2 nel file di esercizi

/*dichiara variabile str di tipo array di char e una variabile di tipo char, valori assegnati:
costante stringa "Pippo" e costante carattere 'z', il programa prima di finire mostra queste due variabili*/

int main() {

    /*caratteri con printf*/

    /*char str[5] = {'P', 'i', 'p','p','o'};
    char c = 'Z';*/

    /*caratteri con getchar*/
    char c1;
    char c2;

    /*for(int i = 0; i < 5; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    printf("%c \n", c);*/

    do{

    printf("Inserire c1 e c2: \n");
    c1 = getchar(); getchar();
    c2 = getchar(); getchar(); 
    } while (c1 == '\n' || c2 == '\n');

    printf("c1 = %c, c2 = %c\n", c1, c2);
    


    return 0;
    
}