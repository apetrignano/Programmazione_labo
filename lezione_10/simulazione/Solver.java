import java.util.Scanner;
import java.util.ArrayList;

public class Solver {

	public static void Main(String[] args) {

		Scanner sc = new Scanner(System.in); // creazione di uno scanner che legge le righe del file di testo

		// scorrere elenco fino
		Noleggio park = new Noleggio(); // creato un array con attualmente 0 veicoli 
		while(sc.hasNext()) {
			String command = sc.next();

			switch(command) {

				case "ADD": // si suppone il formato ADD <tipo_veicolo> targa modello anno numNoleggi cavalli/numPax

					type = sc.next();
					String plate = sc.next();
					String modello = sc.next();
					int year = sc.nextInt();
					int number = sc.nextInt();
					int personalize = sc.nextInt();
					// quindi prima si salva tutti i campi, poi si crea Auto o Moto

					if(type == "Auto") {
						Auto a = new Auto(plate, modello, year, number, personalize); // creazione di auto
						park.aggiungiVeicolo(a); // aggiunta di Auto alla lista di veicoli
					} else if(type == "Moto") {
						Moto a = new Moto(plate, modello, year, number, personalize);
						park.aggiungiVeicolo(a);
					} else {
						// scrivere gestione eccezioni
					}

					break;

				case "R": // si suppone il formato R targa (sufficiente questo per identificare veicolo in modo univoco)

					String plate = sc.next();

					

				case "S": // semplicemente riordina la lista di veicoli, quindi non ha altri parametri sulla riga

					park.sort();

					break;


			}
		}
	}
}



					
					  
