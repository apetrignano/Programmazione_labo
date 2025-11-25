public class Euclide {
	public static void main(String []args) {
		int a = 214, b = 128;
		System.out.printf("m.c.d. di %d e %d è: ", a, b);

		while(a != b) {
			if(a > b) a = a-b;
			else b = b - a;
		}
		System.out.printf("%d\n", a);
	}
}
