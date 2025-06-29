/* Para redefinir as proporções da matriz de acordo com sua escolha coloque o número de linhas e
colunas nas pré-definições do código logo abaixo da biblioteca. */

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

void imprimir_matriz(int matriz[LINHAS][COLUNAS])
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

int calcular_mediana(int matriz[LINHAS][COLUNAS])
{
  int vetor[LINHAS * COLUNAS];
  int k = 0;

  // Passo 1: Copiar todos os valores da matriz para um vetor
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      vetor[k] = matriz[i][j];
      k++;
    }
  }

  // Passo 2: Ordenar o vetor do menor para o maior
  for(int i = 0; i < k - 1; i++)
  {
    for(int j = i + 1; j < k; j++)
    {
      if(vetor[i] > vetor[j])
      {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
      }
    }
  }

  // Passo 3: Pegar o valor do meio
  if(k % 2 == 1) // quantidade ímpar
  {
    return vetor[k / 2];
  }
  else // quantidade par (só por segurança)
  {
    return (vetor[k/2 - 1] + vetor[k/2]) / 2;
  }
}

int calcular_moda(int matriz[LINHAS][COLUNAS])
{
  int vetor[LINHAS * COLUNAS];
  int k = 0;

  // Passo 1: Copiar a matriz para um vetor
  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      vetor[k] = matriz[i][j];
      k++;
    }
  }

  // Passo 2: Contar quantas vezes cada número aparece
  int maior_frequencia = 0;
  int somatorio = 0;
  int quantidade = 0;

  for(int i = 0; i < k; i++) // pega um número, comecando por zero
  {
    int atual = vetor[i];
    int frequencia = 0;

    for(int j = 0; j < k; j++) // conta quantas vezes ele aparece
    {
      if(vetor[j] == atual)
      {
        frequencia++;
      }
    }

    if(frequencia > maior_frequencia)
    {
      // Encontramos nova moda
      maior_frequencia = frequencia;
      somatorio = atual;
      quantidade = 1;
    }
    else if(frequencia == maior_frequencia && atual != somatorio)
    {
      // Empatou com a moda, soma para fazer média depois
      somatorio += atual;
      quantidade++;
    }
  }

  // Passo 3: Calcular moda (ou média das modas)
  return somatorio / quantidade;
}

void gerar_csv(int matriz[LINHAS][COLUNAS])
{
  FILE *arquivo = fopen("arquivo.csv","w");

  if(arquivo == NULL)
  {
    printf("\nErro ao abrir arquivo!\n");
    return;
  }

  for(int i = 0; i < LINHAS; i++)
  {
    for(int j = 0; j < COLUNAS; j++)
    {
      fprintf(arquivo,"[%3d] ",matriz[i][j]);
      
      if(j < COLUNAS - 1)
      {
        fprintf(arquivo, ",");
      }
    }
    fprintf(arquivo,"\n");
  }

  fclose(arquivo);
}