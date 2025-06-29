/*Dado dois numeros, faça a soma deles e apresente o resultado na tela.*/

#include <stdio.h>

int main ()
{
  int a, b;
  int soma = 0;

  scanf("%d",&a);
  scanf("%d",&b);

  soma = a + b;

  printf("A soma dos numeros foi: %d",soma);

return 0;
}