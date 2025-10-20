# Lezione 2 (Prima parte)
## Recap della lezione precedente
I datatype primitivi sono `int` `char` `float` `double`, esprimono variabili, per utilizzarle chiaramente bisogna dichiararle, a inizio del programma (possono avere solo lettere minuscole), e comunque prima del loro uso. 
Una cosa curiosa: come si vede dalla tabella ASCII (sulle slides), il `char` in realtà è un `int`, quindi le parole si possono modificare molto facilmente, basta fare somme o sottrazioni (si veda l'algoritmo della crittografia di Cesare). Per definire delle costanti di usa quesa sintassi: `#define N 10`, oppure `#define LETTERA A`, come si vede dagli esempi, le costanti, al contrario delle variabili, hanno solo lettere maiuscole per convenzione; in fase di compilazione esse vengono trattate come dei veri e propri letterali, è interessante notarlo.
## I/O: scanf e printf
Fanno parte della libreria `stdio.h`, usare per leggere input e scrivere output del programma, funzionano più o meno allo stesso modo, sono basate su una stringa di formato e successive variabili; la stringa di formato serve per tipizzare la lettura/scrittura della variabili, di seguito sono indicati i placeholder.
- %d, int; 
- %c, char;
- %f, float;
- %lf, double. \
Utilizzo generale di printf:
```
printf(<format string>, var1, var2, ..., varn)
```
Esempio di utilizzo di printf:
```c
#define PI 3.14
int num = 0;
char c = 'a';
printf("PI: %lf, num: %d, c: %c\n", PI, num, c);
```
Si ricorda che dopo la parte di printf che definisce cosa deve venire stampato, quindi dopo le virgolette, bisogna mettere in ordine le variabili, nell'ordine in cui si vuole che vengano stampate. Inoltre ciò che viene stampato al posto dei placeholder non è una variabile propriamente, bensì un'espressione, concetto estremamente in c. \
Bisogan stare attenti a specificare il tipo corretto, alcune azioni possono essere accettare dal compilatore ma non portare ai risultati sperati, vengono definiti "undefined behavior", quindi è necessario conoscerli per poterli correggere; di seguito viene riportato un esempio:
```c
int num = 3;
printf("as int %d, as double: %lf\n", num, num);
```
l'output verrebbe qualcosa come:
```
as int 3, as double 0.000000
```
Questo è strano, non converte automaticamente un int in double (non c'è static_cast), la cosa utile del compilatore è che ok che permette di compilare il programma, però viene dato al programmatore un messaggio di warning.
## Funzione `getchar`
Si tratta di una funzione di `stdio.h` che legge un singolo carattere, restituendo un un valore char, utilizato specificatamente al posto di `scanf`. \
Cosa importantissima: quando si chiede all'utente di digitare più di un valore, tranne l'ultimo da inserire, bisogna inserire dopo ogni input un altro getchar, perchè quando si digita invio quello è un carattere, pertanto viene salvato nel successivo getchar, sui lucidi è stato portato che risultato darebbe, di seguito invece viene presentato un esempio di utilizzo corretto di `getchar`:
```c
#include <stdio.h>
int main(){
char c1, c2;
printf("Inserisci il primo carattere: ");
c1 = getchar(); getchar();
printf("Inserisci il secondo carattere: ");
c2 = getchar();
printf("Hai inserito \'%c\' e \'%c\'\n", c1, c2);
return 0;
}
```
Chiaramente non è molto smart come cosa scrivere praticamente il doppio delle funzioni che ci servono, pertanto è più utilizzata la funzione `scanf`.
## Disquisizione su scanf
Definita in `stdio.h`, usata per leggere da `stdin`, converte l'input secondo il formato specificato, utilizzo:
```c
scanf(<format_string>, &var1, &var2, ..., &varn)
```
Il valore restituito è un int che indica il numero di elementi assegnati; di seguito viene riportato un frammento di codice che legge un intero  un float, separati da spazio, usando solo `scanf`, il quale verifica che la lettura è andata a buon fine:
```c
int n1;
float n2;
int ret_val = scanf("%d %f", &n1, &n2);
printf("numero di variabili: %d \n", ret_val)
```

## Selezione
Si tratta di un algoritmo che si è già visto a teoria, nella sostanza è un costrutto `if then (else)`, in cui nell'espressione viene valutato il valore logico, che in C non è ancora di tipo `true` o `false`, ma numerico: lo 0 è falso, tutti gli altri numeri sono veri, per convenzione si usa solo 1. \
### Priorità degli operatori
Ci possono essere casi di ambiguità, come quello che viene presentato di seguito:
```c
int a = 0, b, = 0, c;
c = !a || b;
```
c viene inizializzata come 1, perchè l'operatore `!` ha la precedenza rispetto a `||`, e il contrario di 0 è 1.
#### Esempio di programma con algoritmo di selezione

```c
#include <stdio.h>
/* Scrivere un programma che prende in input un voto e scrive
"promosso" se >= 18 */
#define SOGLIA 18

int main() {
    int voto = 19;

    if(voto >= SOGLIA) {
        printf("Promosso") } else {
        printf("Bocciato")}

    return 0;
}
```
Adesso vengono mostrati dai lucidi i diagrammi di flusso degli algoritmi di selezione.

## Come impostare un programma
Chiaramente, per scrivere un programma in modo efficace, bisogna "scomporlo" in parti:
1. Dichiarazione delle variabili;
1. Ottenimento degli input;
1. Fase principale, di calcolo;
1. Restituzione di output;
1. Conclusione: return.

## Ciclo while
Costrutto in c: `while <espressione> <blocco>`, come prima, di `espressione` si valuta il valore logico. \
Esempio di utilizozdi `while`:
```c
#include <stdio.h>

void main() {
    // Loop infinito
    while(true) {
        .
        .
        printf("Sono in un loop aiutatemi \n");
    }
    printf("non verrà mai stampata questa riga. \n");
}
```
Non è molto utile questo esempio, vediamo quindi un frammento migliore:
```c
int x = 0;

while (x < 10) { // Per il primo valore si ha 0, viene verificato che x < 9, quindi viene eseguito quello che c'è tra parentesi
    printf ("x = %d\n", x);
    x++;
    }

printf("ho finito!\n");
```
Nota bene: è importante saper fare "debugging", ovvero praticamente eseguire a mano il programma (per quelli semplici) per capire cosa sta facendo in ogni momento, e comprendere subito dove nel caso c'è un problema con il codice (in particolare all'esame direi). \
Ora vediamo un esempio di ciclo `while`, prima con alcuni errori, poi nel modo corretto:
```c
int x; // Ecco l'errore: si ha un unexpected behavior
while (x <= 0) {
    printf("Inserisci un valore > 0\n");
    scanf("%d",&x);
    printf("Hai inserito %d ",x);
    if (x<=0)
        printf(" e non va bene\n");
    }
printf("\nHai inserito %d e va bene.",x);
```
Corretto:
```c
int x = -1; //OK! Uso valore fuori dal dominio
while (x <= 0) {
    printf("Inserisci un valore > 0\n");
    scanf("%d",&x);
    printf("Hai inserito %d ",x);
    if (x<=0)
        printf(" e non va bene\n");
}
printf("\nHai inserito %d e va bene.",x);
```
Ora si presenta lo stesos esempio con un nuovo ciclo: il `do while`:
```c
int x; //Non serve inizializzare
do //con il do-while viene eseguito almeno 1
{
    printf("Inserisci un valore > 0\n");
    scanf("%d",&x);
    printf("Hai inserito %d ",x);
    if (x<=0)
    printf(" e non va bene\n");
} while (x<=0);
printf("\nHai inserito %d e va bene. \n",x);
```
Ricorda: dopo il while non ci va il punto e virgola, perchè è un comando, farebbe entrare il programma in loop. \
Ricorda 2: se bisogna inserire un valore e controllare che esso rispetta dei parametri, bisogna utilizzare il costrutto `do while`; questa cosa non è chiaramente sempre vera, 
quando nel ciclo ci sono doppi controlli, è più appropriato usare il costrutto `while`; quando un programma entra in loop, bisogna come prima cosa controllare questi costrutti. Se il codice ha meno ramificazioni, meno if, meno controlli, va bene duplicare righe di codice. La semplicità batte l'ultra performanza del codice.  \
Esempio:
```c
x = 0;
while(x<10) ;
    {
    x++;
    printf("%c ", x);
}

printf("\n");
```
### Esercizi 
In particolare vanno svolti: 
- 1.4 (per arrivarci si passa dagli esercizi intermedi) \
Consiglio: prima di arrivare ad un programma "generale", in cui si chiedono all'utende gli input, si mettono direttamente nel codice e si valuta la robustezza
- 2.5, 2.6, 2.7, 2.8
- 3.12

# Lezione 2 (seconda parte)
Nella lezione di oggi non vengono mostrati mollti nuovi argomenti, l'obiettivo è formalizzare le "buone pratiche" di programmazione dette in modo informale ieri. 

### Costrutto `while`
```c
int i = 0; // Variabile inizializzata al valore iniziale
while (i < n) { // Confronto con soglia
    // calcoli vari
    i++; // Contatore si modifica affinchè ad un certo punto l'espressione del while diventi false
}
```
C'è un modo più compatto per scrivere il `while`, e questo è il ciclo `for`:
```c
for(int i = 0; i < n; i++) {
    //Calcoli
}
```
Come si può vedere, c'è ancora la variabile inizializzata al valore iniziale, il confronto con la soglia e la modifica del contatore. \\

### Costrutto `switch`

```c
int a = ...;
switch(a) {
    case 0: // Confronto con variabile a, quindi "nel caso a == 0, fai questa azione"
        // Operazione
        break;
    case 1: // "nel caso a == 1, fai questa azione"
        // Operazione
        break;
    ...
    default:
        // Operazione

}
```
Il break serve perchè "forza" l'uscita dallo switch dopo l'esecuzione dell'operazione desiderata, altrimenti verrebbero fate tutte di seguito.

##  Variabili sentinella o "flag"

Noi sappiamo che in C non esiste il datatype boolenao, per questo si usano queste variabili qui, le quali identifiano se un dato evento è successo oppure no; si usa in questi casi:
- Se un risultato è stato ottenuto;
- se input è valido o meno;
- se una condizioneè verificata.
#### Esempio:
Scrivere un programma che chiede all’utente, in un numero prefissato di
tentativi, di indovinare un valore intero che viene deciso a compile time (quindi bisogna inserire una costante).
Per ogni tentativo, il programma avvisa l’utente se il numero da trovare è
maggiore o minore del tentativo.
```c
int trovato = 0;
do {
counter++;
    printf("Tentativo numero %d\nInserisci valore\n",counter);
    scanf("%d",&guess);
    if(guess > N)
        printf("valore troppo alto!\n\n");
    if(guess < N)
        printf("valore troppo basso!\n\n");
    if(guess == N)
        trovato = 1; // Vale 1 se e solo se il numero è stato indovinato
} while (counter < TENTATIVI && !trovato);
if (trovato) // Questa espressione ha lo stesso valore della variabile, non serve operatore di confronto
printf("Hai trovato il valore %d in %d tentativi\n",N,counter);
```
## Vanno aggiunti i confronti tra i costrutti in modo formale

#### Esercizio assegnato a lezione
Scrivere un programma che, dato un numero n, trova tutti i numeri primi fino ad n. \
Processo risolutivo: doppio ciclo for, parte da 1, confronta il numero con  tutti i numeri positivi precedenti, se n % num_prec != 0 fino alla fine, si stampa a schermo il numero primo, 
durante li ciclo, appena n % num_prec = 0, si passa all'indice successivo, quindi serve un "flag".