public class Complex {
	
	double re;
	double im;

	public Complex() {
		re = 0;
		im = 0;
	}

	public Complex(double p_re, double p_im) {
		re = p_re;
		im = p_im;
	}

	/*Complex sum(Complex z1, Complex z2) {
		this.re = z1.re + z2.re;
		this.im = z1.im + z2.im;

		return this;
	}*/

	Complex sum(Complex add) {
		this.re += add.re;
		this.im += add.im;

		return this;
	}



}

	
	




