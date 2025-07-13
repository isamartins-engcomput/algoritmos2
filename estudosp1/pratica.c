#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

void inserir_matriz(int matriz[LINHAS][COLUNAS])
{
  printf("\n");
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      printf("Digite um valor para a linha %d coluna %d: ",i + 1,j + 1);
      scanf("%d",&matriz[i][j]);
    }
  }
}

void printar_matriz(int matriz[LINHAS][COLUNAS])
{
  printf("\n");
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      printf("[%3d] ",matriz[i][j]);
    }
  printf("\n");
  }
}

float calcular_media(int matriz[LINHAS][COLUNAS])
{
  float soma = 0;
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      soma = soma + matriz[i][j];
    }
  }
  return soma / (float)(LINHAS * COLUNAS);
}

void gerar_csv(int matriz[LINHAS][COLUNAS])
{
  FILE *arquivo = fopen("operacoes_matriz.csv","w");

  if(arquivo == NULL)
  {
    printf("\nErro ao abrir arquivo!\n\n");
  }

  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      fprintf(arquivo,"[%3d] ",matriz[i][j]);

      if (j < COLUNAS - 1)
      {
        fprintf(arquivo,",");
      }
    }
    fprintf(arquivo,"\n");
  }
  fclose(arquivo);
}

int main ()
{
  int matriz[LINHAS][COLUNAS];

  inserir_matriz(matriz);
  printar_matriz(matriz);

  printf("\nMedia: %.2f\n\n",calcular_media(matriz));

  gerar_csv(matriz);

return 0;
}