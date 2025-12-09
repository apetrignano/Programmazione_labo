public class Main {
	public static void main(String[] args) {

		Complex num0 = new Complex(); // inizializzazione di numero complesso nullo
		Complex num1 = new Complex(1, 2);
		Complex num2 = new Complex(3, 4);

		System.out.printf("Debug: num1 = %f + %f\n", num1.re, num1.im);

		num0.sum(num1);

		System.out.printf("num0 + num 1 = %f + %f\n", num0.re, num0.im);

	}
}

