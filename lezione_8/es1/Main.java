public class Main {
	public static void main(String[] args) {
		
		Contatore counter1 = new Contatore(); // creazione di un Contatore inizializzato a 0
		Contatore counter2 = new Contatore(2); // creazione di un Contatore inizializzato a 2
		
		counter1.inc();
		counter2.inc();

		System.out.printf("contatore1 = %d\ncontatore2 = %d\n", counter1.a, counter2.a);
		System.out.println("Valori attesi sono 1 e 3");

	}
}



