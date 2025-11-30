import java.util.Scanner;

public class Calcolatrice_1 {

  public static double addizione(double x, double y) {return x + y;}
  public static double sottrazione(double x, double y) {return x - y;}
  public static double moltiplicazione(double x, double y) {return x * y;}
  public static double divisione(double x, double y) {return x / y;}

  public static void main(String[] args) {


    // inizializzazione dei valori
    int choice;
    Scanner scan = new Scanner(System.in); // si crea l'oggetto scanner
    System.out.println("Inserire a e b:");
    double a = scan.nextDouble();
    double b = scan.nextDouble();
    System.out.printf("a = %f\nb = %f\n", a, b);
    //scan.close();

    //Scanner scan2 = new Scanner(System.in);

    do {
      System.out.printf("1.\tAddizione\n2.\tSottrazione\n3.\tMoltiplicazione\n4.\tDivisione\n5.\tEsci\n> ");
      choice = scan.nextInt();
      //scan.close();
    

    switch(choice) {
      
      case 1:
        System.out.printf("a + b = %f\n", addizione(a, b));
        break;

      case 2:
        System.out.printf("a - b = %f\n", sottrazione(a, b));
        break;

      case 3:
        System.out.printf("a * b = %f\n", moltiplicazione(a, b));
        break;

      case 4:
        if(b == 0) {
          System.out.println("b deve essere maggiore di 0!");
        }
        System.out.printf("a / b = %f\n", divisione(a, b));
        break;

      case 5:
        return;

      default:
        break;
    }
  } while(choice != 5);
    scan.close();
}
}
