// QUESTÃO 2 - verificacao de data de nascimento

#include <stdio.h>

int main ()
{
  int dia, mes, ano;
  
  printf ("\nQual o dia em que voce nasceu? ");
  scanf ("%d",&dia);
  
  printf ("\nDe qual mes? ");
  scanf ("%d",&mes);
  
  printf ("\nDe qual ano? ");
  scanf ("%d",&ano);
  
  if (dia <= 31 && mes <= 12 && ano < 2025)
  {
    printf ("\n\nParabens! Data de nascimento valida!\n\n");
  }
  else
  {
    printf ("\n\nErro: Data de nascimento invalida!\n\n");
  }
  
return 0;
}
