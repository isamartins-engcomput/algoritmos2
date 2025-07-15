/* 6) Escreva um programa que aloque dinamicamente uma matriz de inteiros.As dimensões da
matriz deverão ser lidas do usuário. Em seguida, escreva uma função que receba um valor e
retorne 1, caso o valor esteja na matriz,ou retorne 0, no caso contrário. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int verificar_valor(int **matriz, int linhas, int colunas, int valor)
{
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      if (matriz[i][j] == valor)
      {
        return 1;
      }
    }
  }

return 0;
}

int main()
{
  setlocale(LC_ALL,"");

  int linhas, colunas;

  do
  {
    printf("\nDigite o número de linhas da matriz: ");
    scanf("%d",&linhas);

    if (linhas <= 0)
    {
      printf("\nValor inválido! O número de linhas deve ser > 0.\n");
    }

  } while (linhas <= 0);

  do
  {
    printf("Digite o número de colunas da matriz: ");
    scanf("%d",&colunas);

    if (colunas <= 0)
    {
      printf("\nValor inválido! O número de colunas deve ser > 0.\n\n");
    }

  } while (colunas <= 0);

  int **matriz = malloc(linhas * sizeof(int *));

  if (matriz == NULL)
  {
    printf("\nErro ao alocar memória para as linhas.\n\n");
    return 1;
  }

  for (int i = 0; i < linhas; i++)
  {
    matriz[i] = malloc(colunas * sizeof(int));

    if (matriz[i] == NULL)
    {
      printf("\nErro ao alocar memória para as colunas.\n\n");
      return 1;
    }
  }

  printf("\nDigite os elementos da matriz:\n\n");
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("Elemento [%d][%d]: ",i,j);
      scanf("%d",&matriz[i][j]);
    }
  }

  int valor_busca;
  
  printf("\nDigite um valor para buscar na matriz: ");
  scanf("%d",&valor_busca);

  if (verificar_valor(matriz, linhas, colunas, valor_busca))
  {
    printf("\nO valor %d está presente na matriz!\n\n",valor_busca);
  }
  else
  {
    printf("\nO valor %d NÃO está presente na matriz!\n\n",valor_busca);
  }

  for (int i = 0; i < linhas; i++)
  {
    free(matriz[i]);
  }

  free(matriz);

return 0;
}