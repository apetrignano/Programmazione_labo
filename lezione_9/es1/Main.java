public class Main {
  
  public static void main(String[] args) {


    Vett3d v1 = new Vett3d();
    Vett3d v2 = new Vett3d(2, 3, 4);

    System.out.printf("Coordinate di v1: (%f, %f, %f)\n", v1.GetX(), v1.GetY(), v1.GetZ());
    System.out.printf("Coordinate di v2: (%f, %f, %f)\n", v2.GetX(), v2.GetY(), v2.GetZ());
  }
}
