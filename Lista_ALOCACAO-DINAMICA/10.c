/* 10) Escreva uma função que receba um valor inteiro positivo N por parâmetroe retorne
o ponteiro para um vetor de tamanho N alocado dinamicamente.Esse vetor deverá ter os seus
elementos  preenchidos  com  certo  valor,também  passado  por  parâmetro.  Se  N  for
negativo ou igual a zero, um ponteiro nulo deverá ser retornado. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* criar_vetor(int N, int valor)
{
  if (N <= 0)
  {
    return NULL;
  }

  int *vetor = malloc(N * sizeof(int));

  if (vetor == NULL)
  {
    printf("\nErro ao alocar memória.\n\n");
    return NULL;
  }

  for (int i = 0; i < N; i++)
  {
    vetor[i] = valor;
  }

  return vetor;
}

int main()
{
  setlocale(LC_ALL,"");

  int N, valor;

  printf("\nDigite o tamanho do vetor (N > 0): ");
  scanf("%d",&N);

  printf("\nDigite o valor para preencher o vetor: ");
  scanf("%d",&valor);

  int *vetor = criar_vetor(N, valor);

  if (vetor == NULL)
  {
    printf("\nNão foi possível criar o vetor.\n\n");
    return 1;
  }

  printf("\nVetor de tamanho %d preenchido com o valor %d:\n\n", N, valor);
  for (int i = 0; i < N; i++)
  {
    printf("Posição [%d] => Valor: %d\n",i,vetor[i]);
  }

  printf("\n");
  free(vetor);

return 0;
}