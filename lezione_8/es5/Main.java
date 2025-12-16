public class Main {
  
  public static void main(String[] args) {
    
    Vett v = new Vett(2, 2); // p(2, 2), bisognava creare preliminarmente il centro

    Cerchio cerchio = new Cerchio(v, 3); // Cerchio con centro in (2, 2) e di raggio r
    Cerchio circle = new Cerchio(); // Cerchio di raggio 0 e centro in (0, 0), non si riesce a creare il centro in sostanza

    
    System.out.printf("Coordinate del centro della circonferenza: (%f, %f)\n", cerchio.GetC().GetX(), cerchio.GetC().GetY());
    System.out.printf("P = %f\n", cerchio.GetPer());
    System.out.println("cerchio e circle sono concentrici: " + (cerchio.isConcentric(circle)));

  }

}
