/* Para redefinir as proporcoes da matriz de acordo com seu escolha troque os valores das linhas e
colunas respectivamente na frente de suas definicoes logo abaixo da biblioteca */

#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

void gerar_matriz(int matriz[LINHAS][COLUNAS])
{
  printf("\n");
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      printf("Digite um valor para a linha %d coluna %d: ",i+1,j+1);
      scanf("%d",&matriz[i][j]);
    }
    printf("\n");
  }
}

void printar_matriz(int matriz[LINHAS][COLUNAS])
{
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      printf("[%3d] ",matriz[i][j]);
    }
    printf("\n");
  }
}

int calcular_media(int matriz[LINHAS][COLUNAS])
{
  int soma = 0;
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      soma = soma + matriz[i][j];
    }
  }
  return soma / (LINHAS*COLUNAS);
}

int calcular_mediana(int matriz[LINHAS][COLUNAS])
{
  int vetor[LINHAS*COLUNAS];
  int k = 0;

  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      vetor[k] = matriz[i][j];
      k++;
    }
  }

  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      if(vetor[i] > vetor[j]);
      {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
      }
    }

    if(k % 2 == 1)
    {
      return vetor[k/2];
    }
    else
    {
      return (vetor[k/2 - 1] + vetor[k/2])/2;
    }
  }
}

void gerar_csv(int matriz[LINHAS][COLUNAS])
{
  FILE *arquivo = fopen("operacoes_matriz","w");

  if(arquivo == NULL)
  {
    printf("Erro ao abrir arquivo!");
    return;
  }

  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      fprintf(arquivo,"[%3d] ",matriz[i][j]);
      if(j < COLUNAS - 1)
      {
        fprintf(arquivo,",");
      }
    }
  }

  fclose(arquivo);
}