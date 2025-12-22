public class Debug {

	public static void main(String[] args) {

		/*Auto a = new Auto("1234", "OPEL", 2030, 3, 6); // costruita Auto

		System.out.println("targa: " + a.getTarga());
		System.out.println("modello: " + a.getModello());
		System.out.println("anno: " + a.getAnno());
		System.out.println("numero di noleggi: " + a.getNumNoleggi());
		System.out.println("numero di persone ammesse: " + a.getNumeroPax());
		*/

		Auto a = new Auto("1234", "OPEL", 2012, 3, 6);
		Moto b = new Moto("3343", "HARLEY", 2022, 2, 900);

		Noleggio n = new Noleggio();

		n.aggiungiVeicolo(a);
		n.aggiungiVeicolo(b);
		

	}
}


