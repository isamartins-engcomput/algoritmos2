// QUESTAO 3 - fatorial

#include <stdio.h>

int main ()
{
  int n, fatorial = 1;
  
  printf ("\nDigite um numero inteiro e positivo: ");
  scanf ("%d",&n);
  
  for (int i = 1; i <= n; i++)
  {    
    fatorial = fatorial * i;
  }
  
  printf ("\nFatorial de %d: %d\n\n",n,fatorial);
  
return 0;
}
