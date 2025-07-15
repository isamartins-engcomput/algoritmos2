/* 1)Escreva um programa que mostre o tamanho em byte que cada
tipo de dados ocupa na memória: char, int, float, double. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  printf("\nTamanho de char: %zu bytes\n",sizeof(char));
  printf("Tamanho de int: %zu bytes\n",sizeof(int));
  printf("Tamanho de float: %zu bytes\n",sizeof(float));
  printf("Tamanho de double: %zu bytes\n\n",sizeof(double));

return 0;
}