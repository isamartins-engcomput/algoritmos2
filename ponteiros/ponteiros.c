#include <stdio.h>

int main ()
{
  int a = 5;
  int *pa;
  pa = &a;

  printf ("\nEndereco do ponteiro: %p",&pa);
  printf ("\nEndereco da variavel que foi atribuida ao ponteiro: %p",pa);
  printf ("\nValor da variavel sendo impresso pelo ponteiro: %d",*pa);
  printf ("\nEndereco da variavel: %p\n",&pa);

  int *p = pa;

  printf ("\nEndereco do ponteiro: %p",&p);
  printf ("\nEndereco da variavel que foi atribuida ao ponteiro: %p",pa);
  printf ("\nValor da variavel sendo impresso pelo ponteiro: %d",*p);
  printf ("\nEndereco da variavel: %p\n",&pa);

  int b = 15;
  *pa = b;
  pa = &b;

  printf ("\nEndereco do ponteiro: %p",&pa);
  printf ("\nEndereco da variavel que foi atribuida ao ponteiro: %p",pa);
  printf ("\nValor da variavel sendo impresso pelo ponteiro: %d",*pa);
  printf ("\nEndereco da variavel: %p\n\n",&pa);

return 0;
}