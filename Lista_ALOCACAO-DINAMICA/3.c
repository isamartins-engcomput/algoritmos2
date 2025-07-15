/* 3) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade
e o endereço de uma pessoa. Agora, escreva uma função que receba um inteiro positivo N
e retorne o ponteiro para um vetor de tamanho N, alocado dinamicamente, dessa estrutura.
Solicite também que o usuário digite os dados desse vetor dentro da função. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Cadastro
{
  char nome[100];
  int idade;
  char endereco[100];
};

struct Cadastro* criar_cadastro(int N)
{
  struct Cadastro *vetor;

  vetor = malloc(N * sizeof(struct Cadastro));

  if (vetor != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      printf("\nCADASTRO %d\n",i + 1);

      printf("Nome: ");
      getchar();
      fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin);
      vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';

      printf("Idade: ");
      scanf("%d",&vetor[i].idade);
      getchar();

      printf("Endereço: ");
      fgets(vetor[i].endereco, sizeof(vetor[i].endereco), stdin);
      vetor[i].endereco[strcspn(vetor[i].endereco, "\n")] = '\0';
    }
  }

  return vetor;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nQuantas pessoas deseja cadastrar? ");
  scanf("%d",&N);

  struct Cadastro *cadastros = criar_cadastro(N);

  printf("\n--- DADOS CADASTRADOS ---\n");

  for (int i = 0; i < N; i++)
  {
    printf("\nPESSOA %d\n",i + 1);
    printf("Nome: %s\n",cadastros[i].nome);
    printf("Idade: %d\n",cadastros[i].idade);
    printf("Endereço: %s\n",cadastros[i].endereco);
  }

  printf("\n");
  free(cadastros);

return 0;
}