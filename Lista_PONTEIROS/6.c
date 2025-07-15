/* 6) Crie um programa que contenha um array com cinco elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  int numeros[5];

  printf("\nDigite 5 números inteiros...\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ",i + 1);
    scanf("%d",&numeros[i]);
  }

  printf("\nEndereços das posições com valores pares:\n\n");

  for (int i = 0; i < 5; i++)
  {
    if (numeros[i] % 2 == 0)
    {
      printf("Posição [%d] => Valor: %d => Endereço: %p\n",i,numeros[i],&numeros[i]);
    }
  }

  printf("\n");

return 0;
}