/* 7) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de  ponteiros para  acessar os caracteres
das strings. */

#include <stdio.h>
#include <locale.h>
#include <string.h>

int verificar_ocorrencia(char *str1, char *str2)
{
  while (*str1 != '\0')
  {
    char *inicio = str1;
    char *s2 = str2;

    while (*str1 == *s2 && *s2 != '\0')
    {
      str1++;
      s2++;
    }

    if (*s2 == '\0')
    {
      return 1;
    }

    str1 = inicio + 1;
  }

return 0;
}

int main()
{
  setlocale(LC_ALL,"");

  char string1[100];
  char string2[100];

  printf("\nDigite a primeira string: ");
  fgets(string1, sizeof(string1), stdin);
  string1[strcspn(string1, "\n")] = '\0';

  printf("Digite a segunda string: ");
  fgets(string2, sizeof(string2), stdin);
  string2[strcspn(string2, "\n")] = '\0';

  if (verificar_ocorrencia(string1,string2))
  {
    printf("\nA segunda string ocorre dentro da primeira.\n\n");
  }
  else
  {
    printf("\nA segunda string NÃO ocorre dentro da primeira.\n\n");
  }

return 0;
}