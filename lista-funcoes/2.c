// 2 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print).

#include <stdio.h>

int texto;

void printar (char texto [100])
{
  printf ("\n%s\n\n",texto);
}

int main ()
{ 
  char texto [100];

  printf ("\nDigite alguma coisa qualquer: ");
  scanf ("%s",texto);
  
  printar(texto);
  
return 0;
}
