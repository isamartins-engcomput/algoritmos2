/* 8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo tipo do
vetor.  A  função  deverá  preencher  os  elementos  de  vetor  com  esse  valor.  Não
utilize índices para percorrer o vetor, apenas aritmética de ponteiros. */

#include <stdio.h>
#include <locale.h>

void preencher_vetor(int *vetor, int tamanho, int valor)
{
  int *fim = vetor + tamanho;

  while (vetor < fim)
  {
    *vetor = valor;
    vetor++;
  }
}

int main()
{
  setlocale(LC_ALL,"");

  int numeros[5];
  int valor;

  printf("\nDigite o valor que deseja preencher no vetor: ");
  scanf("%d",&valor);

  preencher_vetor(numeros,5,valor);

  printf("\nVetor preenchido:\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Posição [%d] => Valor: %d\n",i,numeros[i]);
  }

  printf("\n");

return 0;
}