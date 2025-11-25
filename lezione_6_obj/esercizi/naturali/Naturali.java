import java.util.Scanner;

public class Naturali {

	public static int sommatoria(int a) {
		
		return a * (a + 1) / 2;
	}

	public static void main(String []args) {

		Scanner scan = new Scanner(System.in);
		int n;
		
		do {
			System.out.printf("Inserire un int >= 1:");
			n = scan.nextInt();
		} while(n < 1);

		System.out.printf("Somma dei primi %d numeri naturali: %d\n", n, sommatoria(n));
		scan.close();
	}
}


