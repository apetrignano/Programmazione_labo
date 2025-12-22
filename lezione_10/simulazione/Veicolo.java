public abstract class  Veicolo {

	protected String targa;
	protected String modello;
	protected int anno;
	protected int numNoleggi;

	// Costruttore padre
	protected Veicolo(String m_targa, String m_modello, int m_anno, int m_numNoleggi) {


		targa = m_targa;
		modello = m_modello;
		if(m_anno > 1800 && m_anno < 2025) {
			anno = m_anno;
		} else anno = 2025;
		numNoleggi = m_numNoleggi;
	}

	// metodi per accedere ai campi protetti da main
	public String getTarga() { return targa; }
	public String getModello() { return modello; }
	public int getAnno() { return anno; }
	public int getNumNoleggi() { return numNoleggi; }

}
