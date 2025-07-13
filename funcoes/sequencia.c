// 3. Dada uma sequência de n números, calcule a soma de todos os números primos e exiba o resultado. Para tanto crie duas funções: uma para verificar se o número é primo e outra para realizar a soma dos números primos.

#include <stdio.h>

int num, soma = 0;

int somar (int soma, int num)
{
  soma = soma + num;
  return soma;
}

int verificar (int num)
{
  if (num < 2) 
  {
    return 0; // não é primo
  }
  for (int j = 2; j < num; j++)
  {
    if (num % j == 0)
    {
      return 0; // não é primo
    }
  }
  return 1; // é primo!
}

int main ()
{
  int sequencia, cont = 1;
  
  printf ("\nDe quantos numeros e a sequencia que voce deseja calcular? ");
  scanf ("%d",&sequencia);
  
  printf ("\n");
  
  int vet[sequencia];
  
  for (int i = 0; i < sequencia; i++)
  {
    printf ("Digite o %d dessa sequencia: ",cont);
    scanf ("%d",&vet[i]);
    cont++;
    
    if (verificar(vet[i])) 
    {
      soma = somar(soma, vet[i]);
    }
  }
  
  printf ("\nResultado da soma dos numeros primos dessa sequencia: %d\n\n",soma);
  
return 0;
}
