/* 10) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os
dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo. */

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
  struct Atleta temp;

  for (int i = 0; i < 5; i++)
  {
    printf("\nATLETA %d\n", i + 1);

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

  for (int i = 0; i < 4; i++)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (atletas[j].idade > atletas[i].idade)
      {
        temp = atletas[i];
        atletas[i] = atletas[j];
        atletas[j] = temp;
      }
    }
  }

  printf("\nAtletas em ordem decrescente de idade (do mais velho para o mais novo):\n");

  for (int i = 0; i < 5; i++)
  {
    printf("\nNome: %s\n",atletas[i].nome);
    printf("Esporte: %s\n",atletas[i].esporte);
    printf("Idade: %d anos\n",atletas[i].idade);
    printf("Altura: %.2f m\n",atletas[i].altura);
  }

  printf("\n");

return 0;
}