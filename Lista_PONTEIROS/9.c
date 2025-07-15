/* 9) Crie uma função que receba como parâmetro um vetor e o imprima. Não utilize índices
para percorrer o vetor, apenas aritmética de ponteiros. */

#include <stdio.h>
#include <locale.h>

void imprimir_vetor(int *vetor, int tamanho)
{
  int *fim = vetor + tamanho;
  int *inicio = vetor;

  while (vetor < fim)
  {
    int posicao = vetor - inicio;
    printf("Posição [%d] => Valor: %d\n", posicao, *vetor);
    vetor++;
  }
}

int main()
{
  setlocale(LC_ALL,"");

  int numeros[5];

  printf("\nDigite 5 números inteiros:\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ",i + 1);
    scanf("%d",&numeros[i]);
  }

  printf("\nValores do vetor:\n\n");
  imprimir_vetor(numeros,5);

  printf("\n");

return 0;
}