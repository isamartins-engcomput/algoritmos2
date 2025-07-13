/* 5) Usando a estrutura Retângulo do exercício anterior, faça um programa que declare e leia
uma estrutura Retângulo e um Ponto, e informe se esse ponto está ou não dentro do retângulo. */

#include <stdio.h>
#include <locale.h>

struct Ponto
{
  float x;
  float y;
};

struct Retangulo
{
  struct Ponto superior_esquerdo;
  struct Ponto inferior_direito;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Retangulo retangulo;
  struct Ponto ponto;

  printf("\nDigite as coordenadas do ponto superior esquerdo do retângulo:\n");
  printf("X: ");
  scanf("%f",&retangulo.superior_esquerdo.x);
  printf("Y: ");
  scanf("%f",&retangulo.superior_esquerdo.y);

  printf("\nDigite as coordenadas do ponto inferior direito do retângulo:\n");
  printf("X: ");
  scanf("%f",&retangulo.inferior_direito.x);
  printf("Y: ");
  scanf("%f",&retangulo.inferior_direito.y);

  printf("\nDigite as coordenadas do ponto a ser testado:\n");
  printf("X: ");
  scanf("%f",&ponto.x);
  printf("Y: ");
  scanf("%f",&ponto.y);

  if (ponto.x >= retangulo.superior_esquerdo.x && ponto.x <= retangulo.inferior_direito.x && ponto.y <= retangulo.superior_esquerdo.y && ponto.y >= retangulo.inferior_direito.y)
  {
    printf("\nO ponto está dentro do retângulo!\n\n");
  }
  else
  {
    printf("\nO ponto NÃO está dentro do retângulo!\n\n");
  }

return 0;
}