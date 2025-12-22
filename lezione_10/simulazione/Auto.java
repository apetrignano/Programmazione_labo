public class Auto extends Veicolo {

	private int numeroPax;

	// Costruttore
	public Auto(String m_targa, String m_modello, int m_anno, int m_numNoleggi, int m_numeroPax) {

		super(m_targa, m_modello, m_anno, m_numNoleggi);
		if(m_numeroPax > 2 && m_numeroPax < 8) { numeroPax = m_numeroPax; } else numeroPax = 5;
	}

	public int getNumeroPax() { return numeroPax; }

}

