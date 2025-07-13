/* 4) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto superior
esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido por uma estrutura
Ponto,  a  qual  contém  as  posições  X  e  Y.  Faça  um  programa  que  declare  e leia
uma estrutura  Retângulo  e  exiba  a  área  e  o  comprimento  da  diagonal  e  o 
perímetro  desse retângulo. */

#include <stdio.h>
#include <math.h>
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

  printf("\nDigite as coordenadas do ponto superior esquerdo:\n");
  printf("X: ");
  scanf("%f",&retangulo.superior_esquerdo.x);
  printf("Y: ");
  scanf("%f",&retangulo.superior_esquerdo.y);

  printf("\nDigite as coordenadas do ponto inferior direito:\n");
  printf("X: ");
  scanf("%f",&retangulo.inferior_direito.x);
  printf("Y: ");
  scanf("%f",&retangulo.inferior_direito.y);

  float largura = retangulo.inferior_direito.x - retangulo.superior_esquerdo.x;
  float altura  = retangulo.superior_esquerdo.y - retangulo.inferior_direito.y;

  float area = largura * altura;
  float perimetro = 2 * (largura + altura);
  float diagonal = sqrt(largura * largura + altura * altura);

  printf("\nÁrea do retângulo: %.2f\n",area);
  printf("Perímetro do retângulo: %.2f\n",perimetro);
  printf("Comprimento da diagonal: %.2f\n\n",diagonal);

return 0;
}