/* 10) Considere a seguinte declaração: int a, *b, **c, ***d. Escreva um programa que leia
a variável a e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando
apenas os ponteiros b, c e d. O ponteiro b deve ser usado para calcular o dobro, c, o
triplo, e d, o quádruplo. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  int a;
  int *b;
  int **c;
  int ***d;

  printf("\nDigite um valor inteiro para 'a': ");
  scanf("%d",&a);

  b = &a;
  c = &b;
  d = &c;

  int dobro = (*b) * 2;
  int triplo = (**c) * 3;
  int quadruplo = (***d) * 4;

  printf("\nDobro de %d = %d\n",a,dobro);
  printf("Triplo de %d = %d\n",a,triplo);
  printf("Quádruplo de %d = %d\n\n",a,quadruplo);

return 0;
}