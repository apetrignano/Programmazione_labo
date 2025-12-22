import java.util.ArrayList;
import java.util.List;

public class Noleggio {

	private List<Veicolo> listaVeicoli; // elemento qualsiasi classe figlia di Veicolo

	public Noleggio() { // Costruttore (?)
		
		this.listaVeicoli = new ArrayList<>();
	}


	public void aggiungiVeicolo(Veicolo v) { // metodo che aggiunge un Veicolo nella lista, può essere auto o moto

		this.listaVeicoli.add(v);

	}


	public Auto noleggiaAuto(int m_numeroPax, int m_anno) { // deve scorrere l'array fino alla prima occorrenza delle specifiche desiderate, oppure restituire null se non esiste veicolo con specifiche desiderate

		for(int i : listaVeicoli) {

			if(listaVeicoli[i] instanceof Auto && listaVeicoli[i].getNumeroPax() >= m_numeroPax && listaveicoli[i].getAnno() >= m_anno) {

				listaVeicoli.remove(i); // rimuove dall'array l'i-esimo elemento se si verificano le condizioni
				return listaVeicoli[i]; // interrompe il ciclo e restituisce l'intera Auto
			}
		}
		return null;
	}

	public Moto noleggiaMoto(String m_modello, int m_cavalli) { 

		for(int i : listaVeicoli) { // equivalente di for(int i = 0; i < listaVeicoli.length; i++)

			if(listaVeicoli[i] instanceof Moto && listaVeicoli[i].getModello().equals(m_modello) && listaVeicoli[i].getCavalli() >= m_cavalli) {
				listaVeicoli.remove(i);
				return listaVeicoli[i];
			}
		}
		return null;
	}


	public void sort() {

		this.sort(anno); // dovrebbe essere std

	}

	public void getLista() { return listaVeicoli; }
}

