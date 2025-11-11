# Lezione 4
# Prima parte (funzioni e array multidimensionali)
## Funzioni
Ora si inizia a "spezzare" il codice tramite le funzioni, ossia sottoprogrammi, i quali svolgono compiti specifici, ciò è utile per rendere il codice più "personalizzabile" e riutilizzabile (in realtà nel mondo dell'informatica è un obbligo); lo stesso `main` è una funzione; la regola è che se una parte di codice compare più volte allora va costruita una funzione *ad hoc*. 

Ci sono tre *steps* per definirli:
- definizione del *prototipo*, aggiunge una nuova riga alla tabella dei simboli, viene usata per dire effettivamente al compilatore che più avanti ci sarà una funzione con quel nome e quei parametri in ingresso, per "farlo stare tranquillo";
- definizione della funzione, oppure *implementazione*;
- uso effettivo della funzione, definito *chiamata*.
Spesso in realtà capiterà che l'implementazione coincide con la dichiarazione.
#### Definizione
```c 
int my_func() { // abbiamo in ordine: tipo restituito al chiamante, nome della funzione e parametri in ingresso
    int result;
    return result; // valore ritornato dalla funzione al chiamante, del datatype della funzione
}
```
#### Utilizzo
```c
int main() {
    int result = my_func(); // la variaible result non è la stessa della variabile locale alla funzione
    return 0;
}
```

Il passaggio dei parametri in ingresso può essere per valore e per indirizzo, nel primo caso le modifiche della funzione non influenzano i parametri fuori dallo scope, il valore viene copiato e basta, mentre nel secondo appunto si passa per indirizzo, se si modifica qualcosa queste si ripercuotono direttamente nelle celle di memoria; per essere pignoli il `C` supporta solo il passaggio per valore, mentre "simula" quello per indirizzo, usando i puntatori.
#### Esempio
```c
int sum(int a, int b){
    return a + b; // non sono le stesse variabili passate in ingresso
}
int main(){
    int n1 = 10;
    int n2 = 20;
    int result;
    result = sum(n1, n2);
}
```
#### Esempio 2
```c
void swap(int *a, int *b){ // si sta "copiando" il valore degli indirizi, quindi tecnicamente è un passaggio per valore
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n1 = 10;
    int n2 = 20;
    swap(&n1, &n2);
}
```
### Come strutturare un programma in funzioni

Se una parte del codice si ripete, va implementata una funzione per che svolge il compito di quella parte; è utile perchè in caso di modifiche ma toccata solo una parte del programma; tendenzialmente la funzione deve fare una singola cosa, in quanto rende la fase di testing più semplice, se notiamo che ci ne fa più di una, è buona norma spezzare ancora il sottoprogramma.

#### Esempio
```c
int maxArray(int a[N]){

    int max = -9999;

    printf("Inserisci i valori dell'array\n");

    for(int i=0; i<N; i++)
        scanf("%d",&a[i]);

    for(int i=0; i<N; i++)
        if (max < a[i])
            max = a[i];

    return max;
}
```
Nell'esempio appena presentato la funzione sta:
1. Inizializzando l'array con i valori inseriti dall'utente;
1. facendo un confronto tra il max ed ogni elemento dell'array.
è evidente che essa fa due cose: inizializzare e confrontare, questo è un esempio di funzione non ottimale, andrebbero scritte due funzioni distinte per ogni azione.
### Return multipli (anticipo)

Il `C` "obbliga" a restituire al massimo un solo valore, a volte però serve restituirne più di uno, un modo per "barare" e fare ciò è dichiarare le variabili che ci servono fuori dalla funzione e poi passarle per indirizzo; altrimenti si può passare una `struct` o un `array`, a seconda dell'omogeneità tra i dati trattati. Questo verrà trattato più avanti.

## Array multidimensionali

Abbiamo visto gli `array` come una sequenza *contigua* di un certo numero di elementi dello stesso `datatype`, beh, una matrice è semplicemente una sequenza *a più dimensioni*, sempre di elementi dello stesso `datatype`; il numero delle dimensioni (Anisetti *docet*) deve essere noto *a priori*, di norma usando la direttiva `#define`; come già visto a teoria, in realtà in memoria la matrice è salvata come una riga molto più lunga di quello che ci si aspetta, di `M x N` elementi, e non c'è controllo sull'indice degli elementi della matrice.

#### Esempio di definizione di una matrice 

```c
#define M 3
#define N 4
int matrice[M][N] = {
    {10, 20, 30, 40},
    {11, 21, 31, 41},
    {12, 22, 32, 42}
};
```
Se noi volessimo accedere all'elemento `matrice[3][6]` potremmo tranquillamente farlo, avremmo il valore `21`, quindi bisogna fare attenzione.

# Seconda parte (Puntatori)
Breve correzione degli esercizi di ieri, in particolare il primo; unico errore: la dichiarazione della funzione va fatta *prima* del `main`.

#### Accasa
Scrivere una funzione come la `read_int`, che però possa lavorare con qualsiasi limite destro e sinistro arbitrario.

### Definizione
Come già visto in svariate lezioni, la memoria in ogni processo è organizzata come un insieme *contiguo* di celle (si pensi alla MdT), come invece visto ad archi, più celle "unite" formano una *parola*, detta *word*, che dipende dall'architettura, 32 o 64, quindi 4 oppure 8 celle da 1 byte. Ogni variabile occupa un numero specifico di celle consecutive, in base al `datatype`, nel caso non ci si ricordi il numero specifico, si può usare la funzione `sizeof()`, la quale torna un # di byte occupato di tipo < tipo >, ogni cella ha un indirizzo, ceh va da 0 a N-1, espresso in esadecimale, l'indirizzo specifico di una variabile è l'indirizzo della prima cella occupata (questo perchè conoscendo il tipo dalla cella di partenza è facile sapere quanto spostarsi); l'indirizzo è okay in esadecimale, quindi è alla fine un numero intero, però non è salvato come `int`, bensì ha un tipo specifico: proprio il tipo *puntatore*; esso include anche la specifica del tipo puntato, di seguit ola sintassi:
```c
<tipo_puntato> *<identificatore>;
// Esempio
int *pointer;
```
Di seguito viene presentato un programma che utilizza la funzione `sizeof()` e le rispettive uscite derivanti dall'esecuzione del programma:
```c
#include <stdio.h>
int main() {
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    // dimensione di un puntatore
    printf("sizeof(void*) = %zu\n", sizeof(void*)); return 0;
}
```
```
sizeof(char) = 1
sizeof(shor) = 2
sizeof(int) = 4
sizeof(long) = 8
sizeof(void*) = 8
```

### Operatore &

Semplicemente ritorna l'indirizzo di un oggetto, si usa nelle `printf` o in fase di assegnazione di un puntatore.

### Operatore `*`

Lontano dalla dichiarazione di un puntatore, ma sempre associato ad esso(non funziona con tipi diversi dal puntatore), ritorna il valore dell'oggetto puntato dal puntatore; di seguito un esempio(sulle slides della lezione è presente un cartoon di quello che avviene in memoria).

```c
int n1 = 10, n2;
int *p; // dichiarazione puntatore
p = &n1; // inizializzazione di un puntatore ad un indirizzo
n2 = *p; // il valore dell'oggetto puntato da p ha adesso il valore di n2
```
#### Attenzione

La priorità di `*`, chiamato anche *operatore di dereferenziazione*, non è massima, è intermedia tra = e ++/--/[]/., quindi non si può fare qualcosa come `*p++`, se l'obiettivo è aumentare di 1 il valore della variabile puntata da `p`, prima si fa `*p`, poi si incremente p di 1(a casa si può provare a vedere il comportamento di `a = b++`).

## Ritorni multipli

Funzione termina quando incontra nel flusso il primo `return`, che, come già detto svariate volte, è singolo, c'è bisogno di soluzioni *ad hoc* per fare ciò:
- Passare i parametri in ingresso della funzione per indirizzo;
- Restituire una `struct`, se i dati sono eterogenei;
- restituire un `array`, se invece i dati sono omogenei.

#### Esempio di applicazione

```c
int trovaMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    if (n<=0)
        return -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
    return 1;
}
```