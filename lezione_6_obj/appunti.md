# Lezione 6 Seconda parte

Nella lezione si intrduce Java, senza particolari riferimenti alla teoria, pertanto molte cose andranno prese per buone.

#### Esempio

```java
public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello, world!"); // stampa una riga e va automaticamente a capo
    }
}
```
A differenza di come si fa ora in C, ogni progetto deve avere una cartella dedicata. Inoltre la compilazione è diversa: infatti essa produce un file `.class`, il quale non è specifico per l'architettura, bensì è valido su ogni computer che abbia `JVM`.

Nella pratica, sia Hello.java il nostro programma, per compilare si farà `javac Hello.java`, e per eseguire il file `.class` si fa `java Hello`(non bisogna specificare l'estensione quindi, se si fa è un errore).

Tutto il codice deve essere inserito in una class(per convenzione hanno la maiuscola iniziale, e il nome del file deve essere lo stesso nome della classe all'interno).

Per leggere dei valori da terminale bisogna "creare un oggetto scanner", tipo così:
```java
Scannner scan = new Scanner(System.in);

System.out.println("Inserire un intero.");
int i = scan.NextInt(); // se avessi voluto un double avrei scritto .NextDouble()
System.out.printf("%d\n", i);

scan.close();
```
Come si vede dall'esepmio alla slide 13, la sintassi è molto simile al C nella definizione delle funzioni, la dichiarazione delle variabili, i cicli, le selezioni o chiamate a funzioni.

*Cosa utile*: `println` può essere utile per concatenare variaibli:
```java
System.out.println("format: "Sommatoria: " + sum + "formula: " + formula);
// Ciò credo che concateni le stringhe
```

