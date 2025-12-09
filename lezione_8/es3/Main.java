public class Main {
  
  public static void main(String[] args) {
    Vett v1 = new Vett(); // punto che corrisponde all'origine
    Vett v2 = new Vett(2, 2); // p(2, 2)
    Vett v3 = new Vett(v2);

    System.out.printf("Coordinate di v1: (%f, %f)\n", v1.GetX(), v1.GetY());
    System.out.printf("Coordinate di v2: (%f, %f)\n", v2.GetX(), v2.GetY());
    System.out.printf("Coordinate di v3: (%f, %f)\n", v3.GetX(), v3.GetY());

    //v1.Move(1, 1);
    //System.out.printf("Coordinate di v1 dopo lo spostamento: (%f, %f)\n", v1.GetX(), v1.GetY());

  }
}
