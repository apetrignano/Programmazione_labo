public class Contatore {

	int a;

	public Contatore() { // questo è il costruttore, che inizializza a ad un numero sensato
		a = 0;
	}

	public Contatore(int aa) { // altro costruttore, dato che c'è overloading di funzione piò esistere una cosa così
		a = aa;
	}

	void inc() {
		a++;
	}

	void reset() {
		a = 0;
	}
}
