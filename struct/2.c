/* 2) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a origem
das coordenadas, isto é, a posição (0,0). */

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

  struct Ponto ponto;

  printf("\nDigite a coordenada X do ponto: ");
  scanf("%f",&ponto.x);

  printf("Digite a coordenada Y do ponto: ");
  scanf("%f",&ponto.y);

  float distancia = sqrt((ponto.x * ponto.x) + (ponto.y * ponto.y));

  printf("\nDistância até a origem (0,0): %.2f\n\n",distancia);

return 0;
}