// 1. Incluir bibliotecas
#include <stdio.h>
#include <stdlib.h> // rand() e srand()
#include <time.h> // time()

// 2. Definir a ordem da matriz
#define N 20
#define M 20

// 3. Gerar a matriz com valores aleatorios entre 0 e 255
void gerar_matriz(int matriz[N][M])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      matriz[i][j] = rand() % 256; // Com essa funcao que os valores aleatorios sao gerados
    }
  }
}

// 4. Aplicar o filtro da media com janelinha 5x5
void aplicar_filtro(int entrada[N][M], int saida[N][M])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      saida[i][j] = 0;
    }
  }

  for (int i = 2; i < N - 2; i++)
  {
    for (int j = 2; j < M - 2; j++)
    {
      int soma = 0;

      for (int x = -2; x <= 2; x++)
      {
        for (int y = -2; y <= 2; y++)
        {
          soma = soma + entrada[i + x][j + y];
        }
      }
      saida[i][j] = soma / 25;
    }
  }
}


// 5. Salvar a matriz em um arquivo.csv
void salvar_csv(int matriz[N][M], char *matriz_filtrada)
{
  FILE *arquivo = fopen(matriz_filtrada,"w");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      fprintf(arquivo,"[%3d]", matriz[i][j]);

      if(j < M - 1)
      {
        fprintf(arquivo, ",");
      }
    }
    fprintf(arquivo,"\n");
  }
  fclose(arquivo);
}

// 6. Juntar tudo na main
int main()
{
  int imagem[N][M];
  int filtrada[N][M];

  srand(time(NULL)); // Inicializa gerador aleatorio toda vez que compilar

  gerar_matriz(imagem);
  aplicar_filtro(imagem, filtrada);
  salvar_csv(filtrada, "matriz_filtrada.csv");

  printf("Pronto! Matriz aleatoria processada, filtrada e salva com sucesso no arquivo 'matriz_filtrada.csv'.\n");

return 0;
}