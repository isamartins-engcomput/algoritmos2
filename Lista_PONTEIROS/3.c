/* 3)  Crie  um  programa  que  contenha  um  array  de  float  com  10  elementos. 
Imprima  o endereço de cada posição desse array. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  float numeros[10];

  printf("\nEndereços das posições do vetor:\n\n");

  for (int i = 0; i < 10; i++)
  {
    printf("Posição [%d] => Endereço: %p\n",i,&numeros[i]);
  }

  printf("\n");

return 0;
}