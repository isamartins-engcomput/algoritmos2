// 1. Faça uma função que retorne 1 se o número digitado for positivo e 0 se o número digitado for negativo.

#include <stdio.h>



int verificar (int numero)
{
  if (numero > 0)
  {
    printf ("\n1 - numero positivo");
  }
  else
  {
    printf ("\n0 - numero negativo");
  }
}

int main ()
{
  int num;
  
  printf ("\nDigite um numero: ");
  scanf ("%d",&num);
  
  numero = num;
  
  verificar(num);
  printf ("\n\n");
  
return 0;
}
