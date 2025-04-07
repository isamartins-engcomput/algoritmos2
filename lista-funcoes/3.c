// 3 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print), em seguida retorne “Ok”.

#include <stdio.h>

char string[5] = "OK";

char* printar (char texto [100])
{
  printf ("\n%s\n",texto);
  return "Ok";
}

int main ()
{ 
  char texto [100];
  char* retorno;

  printf ("\nDigite alguma coisa qualquer: ");
  scanf ("%s",texto);
  
  retorno = printar(texto);
  
  printf("\nRetorno da funcao: %s\n\n", retorno);
  
return 0;
}
