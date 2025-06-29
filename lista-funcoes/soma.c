// 2. Faça uma função que receba dois números positivos por parâmetro e retorne a soma dos N números inteiros existentes entre eles.

#include <stdio.h>

// Funcao que recebe dois numeros positivos e retorna a soma dos numeros inteiros entre eles
int somar (int numero1, int numero2)
{
  int soma = 0;
      
  // Garantir que numero1 seja o menor e numero2 o maior
  if (numero1 > numero2)
  {
    int temp = numero1;
    numero1 = numero2;
    numero2 = temp;
  }
  
  // Soma os numeros inteiros entre numero1 e numero2
  for (int i = numero1 + 1; i < numero2; i++)
  {
    soma = soma + i;
  }
  
  return soma;
}

int main ()
{ 
  int num1, num2;

  printf ("\nDigite um numero: ");
  scanf ("%d",&num1);
  
  printf ("Digite outro numero: ");
  scanf ("%d",&num2);
  
  int resultado = somar(num1, num2);
  printf ("\nA soma dos numeros entre %d e %d e: %d\n\n", num1, num2, resultado);
  
return 0;
}
