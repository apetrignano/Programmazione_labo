import java.util.Scanner;


public class Euclide {
	
	public static void main(String []args) {

		int a, b;
		Scanner scan = new Scanner(System.in); // per poter dar input
						       //
		do {
			System.out.println("Inserire a > 0: ");
			a = scan.nextInt();
			System.out.println("inserire b > 0: ");
			b = scan.nextInt();
		} while(a <= 0 || b <= 0); // si esce solo se sia a che b sono > 0

		System.out.printf("m.c.d %d, %d: ", a, b);
		while(a != b) {
			if(a > b) a -= b;
			else b -= a;
		}
		System.out.printf("%d\n", a);
		scan.close();
	}
}
