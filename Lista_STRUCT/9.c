/* 9)  Crie  uma  estrutura  representando  um  atleta.  Essa  estrutura  deve  conter  o
nome  do atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados
de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho. */

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Atleta
{
  char nome[100];
  char esporte[100];
  int idade;
  float altura;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Atleta atletas[5];

  int indice_mais_alto = 0;
  int indice_mais_velho = 0;

  for (int i = 0; i < 5; i++)
  {
    printf("\nATLETA %d\n",i + 1);

    printf("Nome: ");
    fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
    atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';

    printf("Esporte: ");
    fgets(atletas[i].esporte, sizeof(atletas[i].esporte), stdin);
    atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d",&atletas[i].idade);

    printf("Altura (metros): ");
    scanf("%f",&atletas[i].altura);

    getchar();
  }

  for (int i = 1; i < 5; i++)
  {
    if (atletas[i].altura > atletas[indice_mais_alto].altura)
    {
      indice_mais_alto = i;
    }

    if (atletas[i].idade > atletas[indice_mais_velho].idade)
    {
      indice_mais_velho = i;
    }
  }

  printf("\n\nAtleta mais alto: %s\n",atletas[indice_mais_alto].nome);
  printf("Esporte: %s\n",atletas[indice_mais_alto].esporte);
  printf("Altura: %.2f m\n",atletas[indice_mais_alto].altura);

  printf("\nAtleta mais velho: %s\n",atletas[indice_mais_velho].nome);
  printf("Esporte: %s\n",atletas[indice_mais_velho].esporte);
  printf("Idade: %d anos\n\n",atletas[indice_mais_velho].idade);

return 0;
}