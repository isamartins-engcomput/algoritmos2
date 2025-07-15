/* 8) Escreva uma função que receba um valor inteiro positivo N por parâmetroe retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente.Se N for negativo ou igual a
zero, um ponteiro nulo deverá ser retornado. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* criar_vetor(int N)
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

  return vetor;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nDigite um valor inteiro positivo para N: ");
  scanf("%d",&N);

  int *vetor = criar_vetor(N);

  if (vetor == NULL)
  {
    printf("\nNão foi possível criar o vetor. Valor de N inválido ou erro de memória.\n\n");
    return 1;
  }

  printf("\nVetor de tamanho %d criado com sucesso!\n\n",N);

  for (int i = 0; i < N; i++)
  {
    vetor[i] = i * 10;
    printf("Posição [%d] => Valor: %d\n",i,vetor[i]);
  }

  printf("\n");
  free(vetor);

return 0;
}