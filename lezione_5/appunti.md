# Lezione 5
## Aritmetica dei puntatori

I puntatori sono variabili che contengono un certo *datatype*, il quale è un numero (pure i caratteri sono dei numeri in C!), pertanto non è assurdo pensare che si possano manipolare tramite operazioni aritmetiche e di confronto, dato un puntatore p ed un intero j qualsiasi: `p + j` vale `(int)p + sizeof(*p) * j`, ossia indirizzo del valore puntato da p (convertito in `int`, anche se in teoria l'indirizzo è del tipo `long int`, precisamente il dato è sempre lungo `64 bit`, ossia `8 byte`), a cui si somma il valore di j, moltiplicato per il numero di celle che occupa il tipo della variabile j.
#### Esempio:
Supponiamo `j = 1`: il contenuto di p viene trattato come int -> 1, e il valore di j è `sizeof(*p) * j` -> `4 * 1`.

Quindi, aggiungere 1 ad un puntatore è proprio spostarsi in avanti del numero di celle necessarie per memorizzare una variabile delle dimensioni del tipo puntato

Deve essere super chiaro: quando si fanno operazioni nell'aritmetica dei puntatori il "valore base" è la dimensione dell'oggetto puntato.

#### Esempio 2:

```c
#include <stdio.h>
#define N 25

int main() {
    char str[N] = "Hello World";
    char *ptr = &str[0]; // c'è equivalenza tra puntatori ed array
    /* &p[0] equivale a scrivere str*/

    printf("%li %li %li\n",str, ptr, ptr+1);
    printf("offset: %lu\n", sizeof(*ptr));
    printf("%c %c\n",*ptr,*(ptr+1));

    int arr[N] = {1,2,3,4,5,6,7,8};
    int *ptr2 = &arr[0];

    printf("%li %li %li\n",arr, ptr2, ptr2+1);
    printf("offset: %lu\n", sizeof(*ptr2));
    printf("%d %d\n",*ptr2,*(ptr2+1));

    return 0;
}

```
Il nome di un'array è il puntatore alla sua prima cella.

## Matrici e puntatori

Rivedere con più attenzione l'esempio a dx nella slide 28.

Ricorda: una matrice non è un puntatore ad array, non decade a puntatore di puntatori.

#### Esempio:
```c
printf("%p %p %p %p\n",m,m[0],m[0]+1,m+1);
```
- `m` si riferisce all'indirizzo del primo elemento, ossia l'indirizzo della prima riga;
- `m[0]` fa la stessa cosa del precedente, `m[0]` è l'indirizzo del primo elemento, ed in quanto è un puntatore ad array avrà l'indirizzo del primo array, il quale è la prima riga;
- `m[0] + 1` è l'indirizzo del secondo elemento del primo array;
- `m + 1` fa spostare una riga in avanti (m sarebbbe come m[0], dato che il nome è un puntatore al primo elemento dell'array).
si ricordi che m è un puntatore ad array di dimensione 2

```c
printf("%d %d %d %d\n",**m,*m[0],*(m[0]+1),**(m+1));
```
- `**m` mostra il valore del primo elemento della prima riga;
- `*m[0]` stessa cosa, data equivalenza tra puntatori ed array;
- `m[0] + 1` invece stampa il secondo elemento del primo array;
- `**(m + 1)` stampa il primo elemento della seconda riga

## Funzioni e puntatori

In realtà ho trovato più istruttivo ascoltare senza prendere appunti, quindi amen.

#### Accasa
Il trova l'errore a quanto pare è carino, bisogna capirlo, dire perchè a volte funziona e altre no, e fornire una soluzione al problema.