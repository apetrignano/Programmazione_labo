public class Cerchio {
  
  private Vett c;
  private double r;
  private double per;

  public Cerchio() {

    c.init(); // non va bene, risulta che c è null
    //c.x = 0;
    //c.y = 0;
    r = 0;
    CalcolaPer();

  }

  public Cerchio(Vett m_c, double m_r) { // creazione di Cerchio a partire da un centro già esistente e un raggio

    this.c = m_c;
    this.r = m_r;
    CalcolaPer();

  }

  public Vett GetC() {
    return c;
  } 

  public double GetPer() {
    return per;
  }

  private void CalcolaPer() {

    per = 2 * 3.14 * this.r;

  }

  public double CalcolaArea() {
    return 3.41 * this.r * this.r;
  }

  public boolean isConcentric(Cerchio c) {

    return (this.c == c.c);

  }
}
