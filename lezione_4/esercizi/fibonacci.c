#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
int main(void){

    int read_int();
    int fibonacci(int); // calcola n-esimo valore della successione di F
    

    int n = read_int(); //il programma calcola F(n)
    // LEGGERE n, che dev'essere > 0
    printf("F(%d)=",n);

    
    printf("%d\n",fibonacci(n));

    return 0;

}

int read_int() {
    int num;

    do {
        printf("Inserire numero intero > 0:\n");
        scanf("%d", &num);
    } while(num <= 0);

    return num;

}

int fibonacci(int n) {

    int i; //contatore del ciclo for
    int f_i=1,f_prec=1; //valori iniziali F(2)=F(1)=1

    for (i=3;i<=n;i++) //il ciclo comincia da i=3
    {
        int aux=f_i; //variabile ausiliaria aux
        f_i += f_prec; //somma ad f_i il valore di f_prec
        f_prec=aux; //f_prec = f_i prima dell'iterazione
    }

    return f_i;

 }
