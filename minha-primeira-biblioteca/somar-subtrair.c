#include <stdio.h>
#include "minhabiblioteca.h"

int main ()
{
  int num1, num2, a, b;
  int soma = 0, subtracao = 0;
  
  printf ("\n///// SOMA /////\n");
  printf ("\nDigite um numero 1: ");
  scanf ("%d",&num1);
  printf ("Digite um numero 2: ");
  scanf ("%d",&num2);
  
  printf ("\n\n///// SUBTRACAO /////\n");
  printf ("\nDigite um numero a: ");
  scanf ("%d",&a);
  printf ("Digite um numero b: ");
  scanf ("%d",&b);

  soma = somar (num1, num2);
  subtracao = subtrair (a, b);

  printf ("\n\n///// RESULTADOS: /////\n");
  printf ("\nResultado da SOMA de %d e %d = %d",num1,num2,soma);
  printf ("\nResultado da SUBTRACAO de %d e %d = %d\n\n",a,b,subtracao);

return 0;
}
