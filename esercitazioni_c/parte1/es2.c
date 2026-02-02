#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  char s1[] = "Stringa numero 1";
  char s2[] = "Galileo 2";


  char *p1 = s1;
  char *p2 = s2;


  printf("%s\n", p1);
  printf("%s\n", p2);

  char *tmp = p1;
  p1 = p2;
  p2 = tmp;

  printf("%s\n", p1);
  printf("%s\n", p2);


  return 0;
}

