/* 3) Crie uma estrutura para representar as coordenadas de um ponto no plano
(posições X e Y). Em seguida, declare e leia do teclado dois pontos e exiba a
distância entre eles. */

#include <stdio.h>
#include <math.h>
#include <locale.h>

struct Ponto
{
  float x;
  float y;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Ponto ponto1, ponto2;

  printf("\nDigite as coordenadas do primeiro ponto...\n");
  printf("X1: ");
  scanf("%f",&ponto1.x);
  printf("Y1: ");
  scanf("%f",&ponto1.y);

  printf("\nDigite as coordenadas do segundo ponto...\n");
  printf("X2: ");
  scanf("%f",&ponto2.x);
  printf("Y2: ");
  scanf("%f",&ponto2.y);

  float distancia = sqrt(((ponto2.x - ponto1.x) * (ponto2.x - ponto1.x)) + ((ponto2.y - ponto1.y) * (ponto2.y - ponto1.y)));

  printf("\nDistância entre os pontos: %.2f\n\n",distancia);

return 0;
}