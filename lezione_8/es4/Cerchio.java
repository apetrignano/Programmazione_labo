public class Cerchio {
  
  private Vett c;
  private double r;
  private double per;

  public Cerchio() {

    c.init();
    r = 0;
    CalcolaPer();

  }

  public Cerchio(Vett m_c, double m_r) {

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
}
