/* 18) Escreva uma função que receba como parâmetro duas matrizes, A e B, e seus tamanhos.
A função deve retornar o ponteiro para uma matriz C, em que C é o produto da multiplicação
da matriz A pela matriz B. Se a multiplicação das matrizes não for possível, retorne um
ponteiro nulo. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int** multiplicar_matrizes(int **A, int l1, int c1, int **B, int l2, int c2)
{
  if (c1 != l2)
  {
    return NULL;
  }

  int **C = malloc(l1 * sizeof(int*));

  if (C == NULL)
  {
    printf("\nErro ao alocar memória para a matriz C.\n\n");
    return NULL;
  }

  for (int i = 0; i < l1; i++)
  {
    C[i] = malloc(c2 * sizeof(int));

    if (C[i] == NULL)
    {
      printf("\nErro ao alocar linha %d da matriz C.\n\n",i);
      return NULL;
    }

    for (int j = 0; j < c2; j++)
    {
      C[i][j] = 0;

      for (int k = 0; k < c1; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return C;
}

int main()
{
  setlocale(LC_ALL,"");

  int l1, c1, l2, c2;

  printf("\nDigite as dimensões da matriz A (linhas e colunas): ");
  scanf("%d %d",&l1,&c1);

  printf("Digite as dimensões da matriz B (linhas e colunas): ");
  scanf("%d %d",&l2,&c2);

  int **A = malloc(l1 * sizeof(int*));
  int **B = malloc(l2 * sizeof(int*));

  if (A == NULL || B == NULL)
  {
    printf("\nErro ao alocar memória para as matrizes.\n\n");
    return 1;
  }

  for (int i = 0; i < l1; i++)
  {
    A[i] = malloc(c1 * sizeof(int));
  }

  for (int i = 0; i < l2; i++)
  {
    B[i] = malloc(c2 * sizeof(int));
  }

  printf("\nDigite os valores da matriz A (%dx%d):\n\n",l1,c1);
  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < c1; j++)
    {
      printf("A[%d][%d]: ",i,j);
      scanf("%d",&A[i][j]);
    }
  }

  printf("\nDigite os valores da matriz B (%dx%d):\n\n",l2,c2);
  for (int i = 0; i < l2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      printf("B[%d][%d]: ",i,j);
      scanf("%d",&B[i][j]);
    }
  }

  int **C = multiplicar_matrizes(A, l1, c1, B, l2, c2);

  if (C == NULL)
  {
    printf("\nNão é possível multiplicar as matrizes.\n\n");
    return 1;
  }

  printf("\nMatriz resultante C (%dx%d):\n\n",l1,c2);
  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      printf("|%3d|",C[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < l1; i++) free(A[i]);
  for (int i = 0; i < l2; i++) free(B[i]);
  for (int i = 0; i < l1; i++) free(C[i]);

  free(A);
  free(B);
  free(C);
  printf("\n");

return 0;
}