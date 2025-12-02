# Lezione 7

### Incremento prefisso o suffisso

nel caso del suffisso, l'espressione ha il valore della variabile, poi si incrementa, il contrario avviene con il prefisso, quindi il *side effect* c'è in ogni caso, cambia "solo"il valore dell'espressione.

# Array in `java`

```java
int []c = new int[10];
```
In questo caso la creazione e l'allocazione dell'array possono essere anche eventi separati, la grandezza di esso è fissa, eprò esiste la riallocazione:
```java

int [] c;
...
c = new int[10];
...
c = new int[20];
```
Di fatto il *garbage collector* rende questo tipo di dichiarazioni una *malloc de facto*.

In questo linguaggio di programmazione non si può tanto sforare gli indici dell'array, se capita viene sollevata un'eccezione che blocca il programma, quindi gestita direttamene dal programma in autonomia.

Se la lunghezza è nota a priori bisogna usare qualcosa di molto simile alla define, ossia: `final int N = <numero>`

#### Modo alternativo di scorrere l'array
```java
int [] arr = {1, 2, 3, 4, 5};
for(int i : arr)
    System.out.println(i);
```

Dietro le quinte, l'array quando viene passato in una funzione viene sempre passato per indirizzo, rispetto al C è fatot in modo più trasparente.

Inoltre, in Java una matrice non può essere sempre considerata come una grande vettore con gli elementi tutti in fila, dato che tutto viene allocato in modo abbastanza dinamico.


# Ricorda
 Provare a fare le implementazioni dei metodi visti, tipo add, remove etc, sono cose che potrebbero capitare all'esame!!!
