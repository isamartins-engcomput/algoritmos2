// 4 - Faça um procedimento que recebe por parâmetro os valores necessário para o cálculo da fórmula de báskara e imprima as suas raízes, caso seja possível calcular.

#include <stdio.h>
#include <math.h>

void baskara (float a, float b, float c)
{
  float delta, raiz1, raiz2;

  delta = (b * b) - (4 * a * c);

  if (delta < 0)
  {
    printf("\nNao existem raizes reais.\n\n");
  }
  else if (delta == 0)
  {
    raiz1 = -b / (2 * a);
    printf("\nExiste uma raiz real: %.2f\n\n", raiz1);
  }
  else
  {
    raiz1 = (-b + sqrt(delta)) / (2 * a);
    raiz2 = (-b - sqrt(delta)) / (2 * a);
    printf("\nExistem duas raizes reais: %.2f e %.2f\n\n", raiz1, raiz2);
  }
}

int main ()
{
  int a, b, c;

  printf("\nDigite os coeficientes a, b e c respectivamente: ");
  scanf("%d %d %d", &a, &b, &c);

  baskara(a, b, c);
  
return 0;
}

