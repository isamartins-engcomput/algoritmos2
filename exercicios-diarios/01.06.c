/* Criar um programa em C que receba uma matriz de N linhas e M colunas, contendo números inteiros
não negativos. Você deve encontrar o caminho do elemento na posição inicial (0, 0) (primeira linha,
primeira coluna) até o elemento na posição final (N-1, M-1) (última linha, última coluna), de forma
que a soma dos valores dos elementos ao longo do caminho seja a maior possível. Você só pode se
mover de uma célula (r, c) para a célula adjacente à direita (r, c+1) ou para a célula adjacente
para baixo (r+1, c).

Restrição de Movimento: Você SÓ pode se mover para uma célula (r_destino, c_destino) se o valor
dessa célula matriz[r_destino][c_destino] for estritamente maior que o valor da célula de origem
matriz[r_origem][c_origem]. Se uma célula não puder ser alcançada por um caminho válido sob essa
regra, ela não deve ser considerada. Se não houver caminho possível que satisfaça as restrições
até o elemento final (N-1, M-1), ou se a maior soma de um caminho válido for negativa, o programa
deve imprimir 0. Caso contrário, imprima a maior soma.

Entrada: A primeira linha da entrada conterá dois números inteiros N e M (1 ≤ N, M ≤ 50), separados
por espaço, representando o número de linhas e colunas da matriz, respectivamente. Caso o valor
digitado para N ou M esteja fora do intervalo aceitável, o algoritmo deve ler novamente (até que
valor válido seja informado). As próximas N linhas conterão M números inteiros cada, separados por
espaço, representando os valores da matriz. Cada número estará no intervalo de 0 a 1000. Garantir
que apenas valores nesse intervalo sejam aceitos.

Saída: O programa deve imprimir uma única linha contendo um único valor inteiro: a maior soma do
caminho, ou 0 se nenhum caminho válido terminar no destino ou se a maior soma for negativa.

Exemplo de Entrada: 3 3 1 2 3 4 5 6 7 8 9
Saída Esperada para o Exemplo: 29 */

#include <stdio.h>

int matriz[50][50];
int memo[50][50];
int N, M;

int calcular_maior_soma(int i, int j)
{
  if (i >= N || j >= M)
  {
    return -1;
  }

  if (memo[i][j] != -2)
  {
    return memo[i][j];
  }

  int atual = matriz[i][j];

  if (i == N - 1 && j == M - 1)
  {
    memo[i][j] = atual;
    return atual;
  }

  int maior = -1;

  if (i + 1 < N && matriz[i + 1][j] > atual)
  {
    int soma = calcular_maior_soma(i + 1, j);
    if (soma > maior)
    {
      maior = soma;
    }
  }

  if (j + 1 < M && matriz[i][j + 1] > atual)
  {
    int soma = calcular_maior_soma(i, j + 1);
    if (soma > maior)
    {
      maior = soma;
    }
  }

  if (maior == -1)
  {
    memo[i][j] = -1;
    return -1;
  }

  memo[i][j] = atual + maior;
  return memo[i][j];
}

int main()
{
  do
  {
    scanf("%d %d", &N, &M);
  }
  while (N < 1 || N > 50 || M < 1 || M > 50);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      do
      {
        scanf("%d",&matriz[i][j]);
      }
      while (matriz[i][j] < 0 || matriz[i][j] > 1000);

      memo[i][j] = -2;
    }
  }

  int resultado = calcular_maior_soma(0, 0);

  if (resultado < 0)
  {
    printf("0");
  }
  else
  {
    printf("%d",resultado);
  }

return 0;
}