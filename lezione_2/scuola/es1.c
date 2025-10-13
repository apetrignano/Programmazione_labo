#include <stdio.h>
int main(void)
 {
  // int a=214, b=128; //Deve essere a,b > 0
  int a, b;
  int counter = 0;

  printf("inserire il primo numero positivo: \n");
  scanf("%d", &a);
  if(a <= 0) {
    printf("Non hai inserito un numero intero positivo\n");
    return -1;
  }
  printf("il valore inserito è %d \n", a);

  // printf("inserire il secondo numero positivo: \n");
  scanf("%d", &b);
  if(a <= 0) {
    printf("Non hai inserito un numero intero positivo\n");
    return -1;
  }
  // printf("il valore inserito è %d \n", b);

  /* if(a <= 0 || b <= 0) {
    printf("Uno dei due numeri non è positivo")
    return -1;
  } */ // Non so se sia meglio questo oppure scriverlo due volte, per ogni inserimento

  printf("Il m.c.d. di %d e %d e': ",a,b);

  while (a != b) {//Fino a quando a e b sono diversi...
    if (a > b) //Se a > b,
    a -= b; //sostituisci a con a-b.
    else //Altrimenti,
    b -= a; //sostituisci b con b-a.
    counter ++;
  }

  printf("%d\n",a);
  printf("Calcolo eseguito con %d passaggi\n", counter);

  return 0;
 }