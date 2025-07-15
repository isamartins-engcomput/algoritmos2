/* 16) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e N
colunas, e um vetor B de tamanho N. A função deve retornar o ponteiro para um vetor C de
tamanho N alocado dinamicamente, em que C é o produto da matriz A pelo vetor B. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* multiplicar_matriz_vetor(int **A, int *B, int N)
{
  if (N <= 0)
  {
    return NULL;
  }

  int *C = malloc(N * sizeof(int));

  if (C == NULL)
  {
    printf("\nErro ao alocar memória para o vetor C.\n\n");
    return NULL;
  }

  for (int i = 0; i < N; i++)
  {
    C[i] = 0;

    for (int j = 0; j < N; j++)
    {
      C[i] += A[i][j] * B[j];
    }
  }

  return C;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nDigite o valor de N (dimensão da matriz e dos vetores): ");
  scanf("%d",&N);

  int **matrizA = malloc(N * sizeof(int*));
  int *vetorB = malloc(N * sizeof(int));

  if (matrizA == NULL || vetorB == NULL)
  {
    printf("\nErro ao alocar memória para matriz A ou vetor B.\n\n");
    return 1;
  }

  for (int i = 0; i < N; i++)
  {
    matrizA[i] = malloc(N * sizeof(int));

    if (matrizA[i] == NULL)
    {
      printf("\nErro ao alocar linha %d da matriz A.\n\n", i);
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

  printf("\nDigite os valores do vetor B:\n\n");
  for (int i = 0; i < N; i++)
  {
    printf("B[%d]: ",i);
    scanf("%d",&vetorB[i]);
  }

  int *vetorC = multiplicar_matriz_vetor(matrizA, vetorB, N);

  if (vetorC == NULL)
  {
    printf("\nNão foi possível calcular o vetor C.\n\n");
    return 1;
  }

  printf("\nVetor C (Matriz A * Vetor B):\n\n");
  for (int i = 0; i < N; i++)
  {
    printf("C[%d] = %d\n",i,vetorC[i]);
  }

  for (int i = 0; i < N; i++)
  {
    free(matrizA[i]);
  }

  free(matrizA);
  free(vetorB);
  free(vetorC);
  printf("\n");

return 0;
}