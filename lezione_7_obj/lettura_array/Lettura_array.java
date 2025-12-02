import java.util.Scanner;

public class Lettura_array {

	public static int[] readArray(){

		int n;
		System.out.printf("Numero di elementi dell'array: ");
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		int [] v = new int[n];

		for(int i = 0; i < v.length; i++) {
			v[i] = scan.nextInt();
		}
		scan.close();

		return v;
	}



	public static void main(String[] argc) {

		int []  vec = readArray();
		
		for(int j : vec) {
			System.out.println(j);
		}

	
	}
}
