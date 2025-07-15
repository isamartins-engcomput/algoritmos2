/* 7) Faça uma função que retorne o ponteiro para um vetor de N elementos inteiros alocados
dinamicamente. O array deve ser preenchido com valores de 0 a N − 1. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* criar_vetor(int N)
{
  int *vetor = malloc(N * sizeof(int));

  if (vetor == NULL)
  {
    printf("\nErro ao alocar memória para o vetor.\n\n");
    return NULL;
  }

  for (int i = 0; i < N; i++)
  {
    vetor[i] = i;
  }

  return vetor;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  do
  {
    printf("\nDigite um valor inteiro positivo para N: ");
    scanf("%d",&N);

    if (N <= 0)
    {
      printf("\nValor inválido! N deve ser > 0.\n");
    }

  } while (N <= 0);

  int *vetor = criar_vetor(N);

  if (vetor == NULL)
  {
    return 1;
  }

  printf("\nVetor preenchido com valores de 0 até %d:\n\n",N - 1);
  for (int i = 0; i < N; i++)
  {
    printf("Posição [%d] => Valor: %d\n",i,vetor[i]);
  }

  printf("\n");
  free(vetor);

return 0;
}