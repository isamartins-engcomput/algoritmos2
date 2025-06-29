/* Criar um programa em C que receba uma sequência de N números inteiros não negativos.
Cada número na sequência (que representa uma posição em um "vetor de saltos") indica o número máximo
de passos que você pode dar para frente a partir daquela posição. Seu objetivo é encontrar o número
mínimo de saltos necessários para alcançar o último elemento da sequência, começando do primeiro
elemento (índice 0). Se for impossível alcançar o último elemento, o programa deve retornar -1.

Detalhes: Você começa na posição 0. Se o valor na posição i for V, você pode saltar para qualquer
posição j tal que i < j <= i + V. O objetivo é chegar ao índice N-1.

Entrada: A primeira linha da entrada será composta por um único número inteiro N (1 ≤ N ≤ 100), que
representa o tamanho da sequência (o número de posições). Deve repetir a leitura enquanto o valor
de N não atender ao intervalo indicado. A segunda linha da entrada conterá N números inteiros não
negativos, separados por espaço, representando os valores de salto em cada posição.

Saída: O programa deve imprimir uma única linha contendo um único valor inteiro: o número mínimo de
saltos para alcançar o final, ou -1 se for impossível. */

#include <stdio.h>

int main()
{
  int N = 0;
  
  while(N < 1 || N > 100)
  {
    scanf("%d",&N);
  }
  
  int vetor[N];

  for(int i = 0; i < N; i++)
  {
    scanf("%d",&vetor[i]);
  }

  int saltos = 0;
  int fim = 0;
  int alcance = 0;

  for (int i = 0; i < N - 1; i++)
  {
    if (i + vetor[i] > alcance)
    {
      alcance = i + vetor[i];
    }

    if (i == fim)
    {
      saltos++;
      fim = alcance;

      if (fim <= i)
      {
        printf("-1");
        return 0;
      }
    }
  }

  printf("%d",saltos);

return 0;
}