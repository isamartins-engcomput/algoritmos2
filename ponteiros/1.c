/* 1) Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços
e exiba o maior endereço. */

#include <stdio.h>

int main()
{
  int a = 2;
  int b = 5;

  int *pa;
  int *pb;

  pa = &a;
  pb = &b;

  printf("\nEndereço de a: %p",pa);
  printf("\nEndereço de b: %p",pb);

  if (pa > pb)
  {
    printf("\n\nMaior endereço => Endereço de a: %p\n\n",pa);
  }
  else
  {
    printf("\n\nMaior endereço => Endereço de b: %p\n\n",pb);
  }

return 0;
}