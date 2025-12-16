public class Main {
  
  public static void main(String[] args) {
    
    Vett v = new Vett(2, 2); // p(2, 2)

    Cerchio cerchio = new Cerchio(v, 3); // Cerchio con centro in (2, 2) e di raggio r

    
    System.out.printf("Coordinate del centro della circonferenza: (%f, %f)\n", cerchio.GetC().GetX(), cerchio.GetC().GetY());
    System.out.printf("P = %f\n", cerchio.GetPer());

  }

}
