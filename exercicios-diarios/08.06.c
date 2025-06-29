/* Criar um programa em C que receba uma sequência de N números inteiros.
Seu objetivo é determinar o número mínimo de trocas necessárias para reorganizar a
sequência de forma que os elementos adjacentes tenham paridades alternadas. Uma sequência
de paridade alternada significa que um número par é seguido por um ímpar, que é seguido
por um par, e assim por diante (Ex: Par, Ímpar, Par, Ímpar...) OU (||) um número ímpar é
seguido por um par, que é seguido por um ímpar, e assim por diante...
(Ex: Ímpar, Par, Ímpar, Par...).
Importante: Primeiro, verifique se é possível formar uma sequência de paridade alternada.
Isso só é possível se a diferença absoluta entre a quantidade total de números pares e a
quantidade total de números ímpares na sequência original for menor ou igual a 1. Se não
for possível formar uma sequência de paridade alternada, o programa deve imprimir -1.
Uma troca envolve a permuta de dois elementos quaisquer na sequência.
Entrada: A primeira linha da entrada será composta por um único número inteiro N (1≤N≤100),
que representa o tamanho da sequência. A segunda linha da entrada conterá N números
inteiros, separados por espaço. Cada número estará no intervalo de 0 a 10^9.
Saída: O programa deve imprimir uma única linha contendo um único valor inteiro: o número
mínimo de trocas para alcançar uma sequência de paridade alternada, ou -1 se for impossível.
Exemplo de Entrada: 5 1 2 3 4 5
Saída Esperada para o Exemplo: 0 */

#include <stdio.h>
#include <stdlib.h>

int verificar_num(int num)
{
  return num % 2 == 0;
}

int calcular_trocas(int *sequencia, int n, int comeca_par)
{
  int errados_pares = 0;
  int errados_impares = 0;

  for (int i = 0; i < n; i++)
  {
    int paridade_atual = verificar_num(sequencia[i]);
    
    int esperado_par;
    if (i % 2 == 0)
    {
      esperado_par = comeca_par;
    }
    else
    {
      esperado_par = !comeca_par;
    }

    if (paridade_atual != esperado_par)
    {
      if (paridade_atual == 1)
      {
        errados_pares++;
      }
      else
      {
        errados_impares++;
      }
    }
  }

  if (errados_pares != errados_impares)
  {
    return -1;
  }

  return errados_pares;
}

int main()
{
  int n;
  int sequencia[100];
  int qtd_pares = 0, qtd_impares = 0;
  int resultado;

  scanf("%d",&n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d",&sequencia[i]);

    if (verificar_num(sequencia[i]))
    {
      qtd_pares++;
    }
    else
    {
      qtd_impares++;
    }
  }

  if (abs(qtd_pares - qtd_impares) > 1)
  {
    printf("-1");
    return 0;
  }
  
  if (qtd_pares > qtd_impares)
  {
    resultado = calcular_trocas(sequencia, n, 1);
  }
  else if (qtd_impares > qtd_pares)
  {
    resultado = calcular_trocas(sequencia, n, 0);
  }
  else
  {
    int caso1 = calcular_trocas(sequencia, n, 1);
    int caso2 = calcular_trocas(sequencia, n, 0);
    
    if (caso1 < caso2)
    {
      resultado = caso1;
    }
    else
    {
      resultado = caso2;
    }
  }

  if (resultado != -1)
  {
    resultado = (resultado + 1) / 2;;
  }

  printf("%d",resultado);
  return 0;
}