# Lezione 6

Ultima lezione di C! Dalla prossima parte di lezione di farà Java.

# Ricorsione

*definizione*: viene usata quando la soluzione del problema è definita in termini di soluzioni su istanze più piccole del problema stesso; la soluzione è quindi definita in termini di caso base e termine ricorsivo.

#### Esempio
```c
if recursive_f(int a) {
    if(a == 1) {
        return 1,
    }
    return a + recursive_f(a - 1); // ecco la soluzione dell'istanza più piccola del problema
}
```
Questo esempio calcola la somma di tutti i numeri interi da `1` ad `a`. Ad ogni passo ricorsivo si apre un nuovo record di attivazione.

La cosa complicata con questo tipo di funzioni è riuscire a fare finire (e in modo corretto) l'algoritmo; quanto capitano errori d questo tipo semplicemente si continuano ad aprire record di attivazione, fino a sforare lo `stack`, in quel momento il programa viene terminato dal sistema operativo (forzatura, quindi se c'è qualche file aperto oppure qualcosa di memoria verrà cancellato).

Altro appunto: per quanto riguarda la scrittura, è sicuramente la forma più elegante, però la memoria viene consumata molto, dato che vengono creati tanti record di attivazione, inoltre il debug non è per niente immediato, quindi il loro utilizzo va ponderato.

#### Esempio

Nel primo frammento di codice abbiamo chiamato `n` record di attivazione, invece nel secondo solo uno, è evidente quale sia la scelta ottimale.
```c
long sommatoria(long a) {
    if(a == 1l) {
        return 1l;
    }
    
    return a + sommatoria(a - 1);
}
```
```c
long sommatoria (long a) {
    long sum = 0, i;
    for(i = 1; i <= a; i++) {
        sum += i;
    }
    
    return sum;
}

```

# Liste concatenate

Si tratta di un modo "comodo" per gestire strutture dati estremamente dinamiche, e meglio di un array ottenuto con una `malloc`; l'idea è che si definisce una struttura dati `nodo`, composta da un dato del `datatype` che vogliamo, e un altro dato di tipo puntatore ad elemento di tipo nodo, in particolare al successivo; è da notare che questa definizione di struttura dati è ricorsiva. Come già visto a teoria, il costo di memoria ed efficienza è elevato, però nei corsi successivi si imparerà ad utilizzarle in modo ottimale (e quindi a sapere quando effettivametne usarle), per ora si introducono e basta, senza curarsi dell'ambiente che roviniamo con questi costi di esecuzione elevati.

!!!Scrivere una lista è un tipico esercizio d'esame!!!

#### Esempio di utilizzo

```c
..
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node *head = NULL; // è la testa della lista
    ...
}
```
In memoria obv l'occupazione in memoria non è sequenziale, poò essere "a casaccio".

Si ricordi: quando si finisce di usare la struttura dati, bisogna liberare la memoria allocata, dato che in C non c'è gestione automatica della memoria. Se ci sono tanti cambiamenti del numero di parametri la lista concatenata risulta migliore della `realloc`, che si ricorda essere una nuova allocazione di memoria della nuova dimensione e copia del vettore di partenza nella nuova memoria.

*Slide 31*: c'è la funzione di ridimensionamento dell'array dinamico, che capita all'esame, quindi attenzione.


# Undefined behaviour

```c
int increase(int *a) {
    *a += 1;
    return *a;
}
int main() {
    int x = 0;
    printf("%d %d %d\n", x, increase(&x), x);
    return 0;
}
```
Noi ci aspetteremmo un output del tipo `0 1 1`, ma in realtà nel C non c'è una vera definizione dell'ordine di esecuzione delle istruzioni, dipende dal compilatore, potrebbe capitare che prima vengano calcolate prima le x e poi l'increase, quindi si avrebbe come output `0 1 0`; si tratta di `undefined behaviour`, la cui definizione è un comportamento che dipende dal compilatore; è un errore; un altro esempio potrebbe essere:

```c
int x = 1;
x++;
printf("%d\n", x);
```
Potrebbe prima fare `x++` e poi assegnare il valore 1 ad esempio.

In fase di compilazione bisogna aggiungere -Wall per vedere tutti gli errori, anche quelli silenti come gli undefined behaviour.

