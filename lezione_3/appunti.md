# Lezione 3 (array e stringhe)
## Recap della lezione precedente

Si inizia con il debug del codice della scorsa volta appunto, si cerca di "formalizzare" l'analisi:
1. Si semplifica il programma, si tolgono gli `scanf`, considerando come variabili dei valori che possiamo usare anche per "simulare" a mano il programma, ma chiaramente non troppo piccoli; si aggiunge anche l'indentazione se assente;
1. Si aggiungono dopo ogni operazione i `printf` per visualizzare il valore della variabile modificato, per capire se un'operazione fa qualcosa che non dovrebbe fare o se il flusso di muove in modo inaspettato;
1. Ho troppo sonno per scrivere tutto il resto.

## Vettori/array
In sostanza sono dei vettori, durante l'assegnamento si scrive `<datatype> a[N];` è una sequenza di variabili dello stesso tipo, di lunghezza N; va inizializzato prima dell'uso e per ora la dimensione è stack, fissa, la definiamo tramite una direttiva `#define`; va ricordato che non si può "copiare" il valore di ogni dimensione del vettore in un altro array con un singolo assegnamento, va fatto un ciclo `for` che accede sequenzialmente ad ogni posizione dell'array e copia ogni elemento rispettivamente nell'altro array, va fatto elemento per elemento. \
nota bene: in C non esiste un controllo per le condizioni `i > 0` e `i < N`, con N dimensione del vettore, cosa direi importante per la sicurezza dello stesso. \
Quando si dichiara un array, vengono allocate celle CONSECUTIVE, non a caso, sono perfettamente ordinate.
#### Esempio
``` c
#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(){

    int a[N] = {1, 2, 3, 4, 5}

    for (int i=0; i<N; i++){
        printf("Inserisci %d-esimo elemento: \n",i);
        scanf("%d",&a[i]);
        }
    for (int i=0; i<N; i++)
        printf("%d-esimo elemento: %d\n",i,a[i]);

return 0;
}
```
L'output è del tipo: 
```
0-esimo elemento: 1
1-esimo elemento: 2
2-esimo elemento: 3
3-esimo elemento: 4
4-esimo elemento: 5
```
Ricorda: dato che non esistono dei controlli per gli intervalli dell'array può capitare di superare il limite di esso, quando capita succede che viene considerata la cella di memoria successiva, per una dimensione uguale a quella degli elementi dell'array (ripeto: questa cosa è da sapere per quanto riguarda la sicurezza die dati). \
### Copia di un array
Sian a e b due array di dimensione N:
```c
int a[N] = {1, 2, 3, 4, 5};
int b[N];
a = b // è sbagliato!!
for(int i = 0; i < N; i++) { // questo è il metodo corretot
    b[i] = a[i];
}
```
## Stringhe
Durante la manipolazione di un testo, lo strumento proprio base è la stringa, la quale è semplicemente un array di char "speciale"(in altri linguaggi di programmazione esistono strumenti ad hoc), il quale è del tipo `char a[N+1]`, il +1 è un "terminatore", un carattere speciale che, per struttura del C, indica la fine della stringa; per convenzione la dimensione massima di una stringa è 1024. Dato che è un array speciale l'assegnamento può avvenire "di seguito", al contrario degli array visti in precedenza:
```c
#define N 5

int main() {

    char a[N+1] = "ciao"; // 4 caratteri ed il terminatore, il sesto carattere non sappiamo che sta contenendo(non abbiamo inizializzato), ma non è necessario

    return 0;
}
```
Possiamo quindi riservare in eccesso lo spazio dedicato alla stringa. \
Negli `scanf` non va utilizzata la `&`. \
#### Leggere una stringa di più parole

Si usa la funzione `fgets`, la cui sintassi è `fgets(stringa, sizeof(stringa), stdin)`
```c
char a[N+1];
printf("Inserisci la stringa\n");
fgets(a, sizeof(a), stdin);
printf("Stringa inserita:\n%s\n",a);
```
### Input `stdin`
Praticamente macchina di Turing as expected; in sostanza, la memoria si può considerare un nastro, con una testina che si muove e legge i caratteri scritti nelle celle; la lettura si dice che "consuma" l'input letto, lasciando lì quello non letto (si dice che lascia i caratteri non letti nel buffer), se il buffer è vuoto allora aspetterà un input dall'utente, se invece è pieno, legge ciò che "vede" e valuta se il contenuto corrisponde alle variabili da leggere effettivamente, se corrisponde la variabile viene aggiornata, altrimenti il dato viene consumato e va avanti. Per questo motivo la spaziaura tra l'inserimento di una o più variabili non è rigorosa: volendo si potrebbe usare in modo indifferenze la spaziatura singola, il tab e alle volte anche l'invio, in quanto la spaziatura (a meno che non venga indicato diversamente) non viene riconosciuta come un tipo della variabile, e il dato viene consumato.

## Compito accasa
Su Ariel verrà caricato un programma con un algoritmo specifico, bisogna trovare gli eventuali errori, quindi fare debugging (se ci si riesce si ottimizza).