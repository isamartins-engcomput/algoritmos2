/* 13) Escreva um programa que leia um inteiro N e crie uma matriz alocada dinamicamente
contendo N linhas e N colunas. Essa matriz deve conter o valor 0 na diagonal principal, 
o valor 1 nos elementos acima da diagonal principal e o valor −1 nos elementos abaixo da
diagonal principal. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int** criar_matriz(int N)
{
  if (N <= 0)
  {
    return NULL;
  }

  int **matriz = malloc(N * sizeof(int*));

  if (matriz == NULL)
  {
    printf("\nErro ao alocar memória para as linhas.\n\n");
    return NULL;
  }

  for (int i = 0; i < N; i++)
  {
    matriz[i] = malloc(N * sizeof(int));

    if (matriz[i] == NULL)
    {
      printf("\nErro ao alocar memória para a linha %d.\n\n", i);
      return NULL;
    }

    for (int j = 0; j < N; j++)
    {
      if (i == j)
        matriz[i][j] = 0;
      else if (j > i)
        matriz[i][j] = 1;
      else
        matriz[i][j] = -1;
    }
  }

  return matriz;
}

int main()
{
  setlocale(LC_ALL,"");

  int N;

  printf("\nDigite o tamanho da matriz (N > 0): ");
  scanf("%d",&N);

  int **matriz = criar_matriz(N);

  if (matriz == NULL)
  {
    printf("\nNão foi possível criar a matriz.\n\n");
    return 1;
  }

  printf("\nMatriz %dx%d com 0 na diagonal principal, 1 acima e -1 abaixo:\n\n",N,N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("|%3d|",matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < N; i++)
  {
    free(matriz[i]);
  }

  free(matriz);
  printf("\n");

return 0;
}