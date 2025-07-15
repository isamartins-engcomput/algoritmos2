/* 4) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em seguida,
faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o imprima. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  int tamanho;

  printf("\nDigite o tamanho do vetor: ");
  scanf("%d",&tamanho);

  int *vetor = malloc(tamanho * sizeof(int));

  if (vetor == NULL)
  {
    printf("\nErro ao alocar memória.\n\n");
    return 1;
  }

  printf("\n");

  for (int i = 0; i < tamanho; i++)
  {
    printf("Digite o valor da posição %d: ",i);
    scanf("%d",&vetor[i]);
  }

  printf("\nValores no vetor:\n\n");
  for (int i = 0; i < tamanho; i++)
  {
    printf("Posição [%d] => Valor: %d\n",i,vetor[i]);
  }

  printf("\n");
  free(vetor);

return 0;
}