# Lezione 8: Programmazione object-oriented

Ora si programma ad oggetti per davvero; infatti d'ora in avanti il codice sarà in termini di *oggetti* ch einteragiscono tra loro; la struttura di un oggetto è definita da una classe in termini di *attributi* e *metodi*. Si può dire che è un'evoluzione del concetto di `struct`.

In Java quindi si lavora con le classi, i cui attributi corrispondono ai campi della struct, inoltre vale un principio detto `principio di incapsulamento`: gli attributi possono essere definiti come `private`: è buona norma  nascondere a chi usa la `class` come essa è stata implementata, e si agisce sugli attributi tramite i metodi. Quindi riassumendo: gli attributi sono `private`, i metodi `public` o `protected`.

è importante il *costruttore*: è un metodo che crea un'istanza della classe, di seguito un esempio: `MyClass variabile = new MyClass(parametri);`; di base se non si specifica il costruttore Java ne crea uno con valori di default, che però non è il massimo se si sta lavorando con oggetit complessi; di base se non si specifica il costruttore Java ne crea uno con valori di default, che però non è il massimo se si sta lavorando con oggetit complessi.

Se per caso ci troviamo con dei parametri dello stesso nome degli attributi si ha un problema di ambiguità: per evitare ciò si può usare la keyword `this`, che si riferisce all'istanza dell'oggetto su cui viene chiamato, quindi l'oggetto corrente(il concetto di `ths` è estremamente importante, perciò va ripassato bene).

Si è poi parlato dei modificatori `static` e `final`: quest ultimo significa che l'attributo `final` non può essere modificato da classi figlie.

### Cartelle e Import

Una classe può essere usata all'interno di un'altra classe senza dover fare `import` o cose strane, inoltre si compila solo il `main`: il compilatore capisce da solo che deve compilare anche le classi chiamate dal `main`.

### Metodo `toString`

Si tratta di un metodo che restituisce una String, che rappresenta iun forma testuale la classe, è utile per fare debugging, se non definito da noi viene agginto in automatico, anche se non è molto utile, dato che il formato di default non è propro comprensibile.

### Metodo `equals`

Metodo che restituisce un booleano, il quale indica se due oggetti sono uguali, ossia se *puntano alla stessa regione di memoria*, non se hanno gli stessi identici attributi, se vogliamo ciò dobbiamo "ridefinire" il metodo `equals`.
