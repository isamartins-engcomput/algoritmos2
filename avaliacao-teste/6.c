// QUESTAO 6 - alistamento militar

#include <stdio.h>

int main ()
{
  char sexo;
  int idade;
  
  printf ("\nQual o seu sexo? (Digite F para feminino e M para masculino): ");
  scanf ("%c",&sexo);
  
  printf ("\nEm que ano voce nasceu? ");
  scanf ("%d",&idade);
  
  if ((sexo == 'M' || sexo == 'm') && idade <= 2007)
  {
    printf ("\n\nSeu alistamento militar e obrigatorio!\n\n");
  }
  else
  {
    printf ("\n\nSeu alistamento militar nao e obrigatorio.\n\n");
  }
  
return 0;
}


