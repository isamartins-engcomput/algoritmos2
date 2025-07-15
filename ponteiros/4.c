/* 4)  Crie  um  programa  que  contenha  uma  matriz  de  float  com  três  linhas  e
três  colunas. Imprima o endereço de cada posição dessa matriz. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  float matriz[3][3];

  printf("\nEndereços das posições da matriz:\n\n");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Posição [%d][%d] => Endereço: %p\n",i,j,&matriz[i][j]);
    }
  }

  printf("\n");

return 0;
}