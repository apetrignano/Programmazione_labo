public class Vett3d extends Vett {
	
	private double z; // aggiunta di un campo
	
	public Vett3d() {

    x = 0;
    y = 0;
	  z = 0;
    CalcolaNorma();


  }

  public Vett3d(double m_x, double m_y, double m_z) {

    x = m_x;
    y = m_y;
    z = m_z;
    CalcolaNorma();

    /*
     * super(m_x, m_y);
     * z 0 m_z;
     * CalcolaNorma();
     */
  }

  public double GetZ() {
    return z;
  }
	
	// ridefinizione del calcolo della norma

  @Override // in questo modo si ridefinisce effettivamente il calcolo della norma

  protected void CalcolaNorma() {

    norm = Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y ,2) + Math.pow(this.z, 2));

  }

  @Override

  protected void init() {
    super.init();
    this.z = 0;
    CalcolaNorma();
  }

}
