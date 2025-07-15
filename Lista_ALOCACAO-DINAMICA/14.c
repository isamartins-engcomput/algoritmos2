/* 14) Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho N cada.
A função deve retornar o ponteiro para um vetor C de tamanho N alocado dinamicamente,
em que C[i] = A[i] + B[i]. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* somar_vetores(int *A, int *B, int N)
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
    C[i] = A[i] + B[i];
  }

  return C;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nDigite o tamanho dos vetores (N > 0): ");
  scanf("%d",&N);

  int *vetorA = malloc(N * sizeof(int));
  int *vetorB = malloc(N * sizeof(int));

  if (vetorA == NULL || vetorB == NULL)
  {
    printf("\nErro ao alocar memória para os vetores A ou B.\n\n");
    return 1;
  }

  printf("\nDigite os valores do vetor A:\n\n");
  for (int i = 0; i < N; i++)
  {
    printf("A[%d]: ",i);
    scanf("%d",&vetorA[i]);
  }

  printf("\nDigite os valores do vetor B:\n\n");
  for (int i = 0; i < N; i++)
  {
    printf("B[%d]: ",i);
    scanf("%d",&vetorB[i]);
  }

  int *vetorC = somar_vetores(vetorA, vetorB, N);

  if (vetorC == NULL)
  {
    printf("\nNão foi possível criar o vetor C.\n\n");
    return 1;
  }

  printf("\nVetor C (Vetor A + Vetor B):\n\n");
  for (int i = 0; i < N; i++)
  {
    printf("C[%d] = %d\n",i,vetorC[i]);
  }

  free(vetorA);
  free(vetorB);
  free(vetorC);
  printf("\n");

return 0;
}