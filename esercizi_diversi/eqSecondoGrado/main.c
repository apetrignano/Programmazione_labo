#include <stdilib.h>
#include <stdio.h>
#include <math.h>

int main() {

  double delta(double, double, double);

  double a = 2, b = 3, c = 5;
  double discr = delta(a, b, c);

  if(delta(a, b, c) < 0) {
    printf("Nessuna soluzione nel campo reale\n");
  } else if(discr == 0) {
    printf("Unica soluzione all'equazione omogenea: %lf\n", (-b + sqrt(discr)) / (2 * a);
  } else {
    printf("Due soluzioni:\n1.\t%lf\n2.\t%lf\n", (-b - sqrt(discr)) / (2 * a),(-b + sqrt(discr)) / (2 * a));
  }

  return 0;
}

double delta(double a, double b, double c) {
  return b * b - 4 * a * c;
}

