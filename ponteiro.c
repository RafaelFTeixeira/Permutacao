#include <stdlib.h>
#include <stdio.h>

void imprimir(int *b) {
  printf("%d ", *b);
}

int main () {

  int a = 3;
  int *b = &a;
  a = 5;
  imprimir(b);

  return 0;
}

