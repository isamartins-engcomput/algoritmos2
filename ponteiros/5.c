/* 5) Crie um programa que contenha um array de inteiros com cinco elementos. Utilizando apenas
aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  int numeros[5];
  int *p;

  p = numeros;

  printf("\nDigite 5 números inteiros...\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ",i + 1);
    scanf("%d",(p + i));
  }

  printf("\nDobro dos valores digitados:\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Dobro do número %d: %d\n",i + 1,2 * (*(p + i)));
  }

  printf("\n");

return 0;
}