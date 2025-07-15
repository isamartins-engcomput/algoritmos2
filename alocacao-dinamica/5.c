/* 5)  Faça  um  programa  que  leia  um  valor  inteiro  N  não  negativo.  Se  o  valor
de N  for inválido,  o  usuário  deverá  digitar  outro  até  que  ele  seja  válido 
(ou seja,  positivo).  Em seguida, leia um vetor V contendo N posições de inteiros, em que
cada valor deverá ser maior ou igual a 2. Esse vetor deverá ser alocado dinamicamente. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");

  int N;

  do
  {
    printf("\nDigite um valor inteiro não negativo para N: ");
    scanf("%d",&N);

    if (N < 0)
    {
      printf("Valor inválido! N deve ser >= 0.\n");
    }

  } while (N < 0);

  int *vetor = malloc(N * sizeof(int));

  if (vetor == NULL)
  {
    printf("\nErro ao alocar memória.\n\n");
    return 1;
  }

  printf("\n");

  for (int i = 0; i < N; i++)
  {
    do
    {
      printf("Digite um valor >= 2 para a posição %d: ",i);
      scanf("%d",&vetor[i]);

      if (vetor[i] < 2)
      {
        printf("\nValor inválido! Deve ser maior ou igual a 2.\n\n");
      }

    } while (vetor[i] < 2);
  }

  printf("\nValores no vetor de tamanho %d:\n\n",N);
  for (int i = 0; i < N; i++)
  {
    printf("Posição [%d] => Valor: %d\n",i,vetor[i]);
  }

  printf("\n");
  free(vetor);

return 0;
}