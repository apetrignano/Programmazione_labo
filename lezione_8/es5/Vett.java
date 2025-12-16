import java.lang.Math;

public class Vett {

  protected double x;
  protected double y;
  protected double norm;

  public Vett() {
    x = 0;
    y = 0;
    norm = 0;
  }

  public Vett(double p_x, double p_y) {
    x = p_x;
    y = p_y;
    CalcolaNorma();
  }

  public Vett(Vett v) {
    //x = v.GetX();
    //y = v.GetY();
    x = v.x;
    y = v.y;
    CalcolaNorma();
  }

  // metodo per muovere un Vett, lo incrementa delle coordinate passate

  public void Move(double x_add, double y_add) {

    this.x += x_add;
    this.y += y_add;
    CalcolaNorma();

  }

  // Metodo per fare moltiplicazione scalare

  public void MultScal(double n) {

    this.x *= n;
    this.y *= n;

  }

  public void init() {
    x = 0;
    y = 0;
    CalcolaNorma();
  }

  /* Metodi privati */

  private void CalcolaNorma() { // ricalcola la norma ogni volta che serve

    norm = Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y ,2));

  }

  public double GetX() {
    return x;
  }

  public double GetY() {
    return y;
  }

  public double GetNorm() { // per accedere al campo norma nel main

    return norm;

  }


}
