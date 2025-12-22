public class Moto extends Veicolo {

	private int cavalli;

	// Costruttore
	public Moto(String m_targa, String m_modello, int m_anno, int m_numNoleggi, int m_cavalli) {

		super(m_targa, m_modello, m_anno, m_numNoleggi); // chiamo il costruttore del padre per assegnar edirettamente questi valori, comuni ad Auto e Moto
		if(m_cavalli > 200 && m_cavalli < 2000) { cavalli = m_cavalli; } else cavalli = 1000;
	}

	public int getCavalli() { return cavalli; }

}


