#include <stdlib.h>
#include <stdio.h>
//#include <limits.h>
#include <float.h>

#define SPECIAL 3.14

void calcola_stats(double, double*, double*, double*);

int main(int argc, char *argv[]) {

  double somma = 0, num, min, max;
  double *ps = &somma, *pM = &max, *pm = &min;
  int flag = 0;

while(1) {
    printf("Inserire numero: ");
    scanf("%lf", &num);

    if(!flag) {min = num; max = num;}
    if(num == SPECIAL) break;

    calcola_stats(num, ps, pm, pM);
    flag = 1;

    printf("Somma: %lf, Min: %lf, Max: %lf\n", somma, min, max);
  }

  return 0;
}

void calcola_stats(double num, double *somma, double *min, double *max) {

  *somma += num;

  if(num > *max) *max = num;
  else if(num < *min) *min = num;

}

/*
Per ora devo dire che il programma va, però non mi sembra molto elegante, vorrei farlo un po' più carino, non è possibile che sia necessario usare una flag
*/
