/* 17) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e N
colunas. A função deve retornar o ponteiro para um vetor B de tamanho N alocado
dinamicamente, em que cada posição de B é a soma dos números daquela coluna da matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* somar_colunas(int **A, int N)
{
  if (N <= 0)
  {
    return NULL;
  }

  int *B = malloc(N * sizeof(int));

  if (B == NULL)
  {
    printf("\nErro ao alocar memória para o vetor B.\n\n");
    return NULL;
  }

  for (int j = 0; j < N; j++)
  {
    B[j] = 0;

    for (int i = 0; i < N; i++)
    {
      B[j] += A[i][j];
    }
  }

  return B;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nDigite o valor de N (dimensão da matriz NxN): ");
  scanf("%d",&N);

  int **matrizA = malloc(N * sizeof(int*));

  if (matrizA == NULL)
  {
    printf("\nErro ao alocar memória para a matriz A.\n\n");
    return 1;
  }

  for (int i = 0; i < N; i++)
  {
    matrizA[i] = malloc(N * sizeof(int));

    if (matrizA[i] == NULL)
    {
      printf("\nErro ao alocar linha %d da matriz A.\n\n",i);
      return 1;
    }
  }

  printf("\nDigite os valores da matriz A (%dx%d):\n\n",N,N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("A[%d][%d]: ",i,j);
      scanf("%d",&matrizA[i][j]);
    }
  }

  int *vetorB = somar_colunas(matrizA, N);

  if (vetorB == NULL)
  {
    printf("\nNão foi possível calcular o vetor B.\n\n");
    return 1;
  }

  printf("\nVetor B (soma das colunas da matriz A):\n\n");
  for (int j = 0; j < N; j++)
  {
    printf("B[%d] = %d\n",j,vetorB[j]);
  }

  for (int i = 0; i < N; i++)
  {
    free(matrizA[i]);
  }

  free(matrizA);
  free(vetorB);
  printf("\n");

return 0;
}