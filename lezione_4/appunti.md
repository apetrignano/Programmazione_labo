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