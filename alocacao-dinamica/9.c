/* 9) Crie uma função que receba uma string e retorne o ponteiro para essa string invertida. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char* inverter_string(char *original)
{
  int tamanho = strlen(original);
  char *invertida = malloc((tamanho + 1) * sizeof(char));

  if (invertida == NULL)
  {
    printf("\nErro ao alocar memória.\n\n");
    return NULL;
  }

  for (int i = 0; i < tamanho; i++)
  {
    invertida[i] = original[tamanho - 1 - i];
  }

  invertida[tamanho] = '\0';

  return invertida;
}

int main()
{
  setlocale(LC_ALL,"");

  char texto[100];

  printf("\nDigite uma string: ");
  fgets(texto, sizeof(texto), stdin);
  texto[strcspn(texto, "\n")] = '\0';

  char *resultado = inverter_string(texto);

  if (resultado != NULL)
  {
    printf("\nString original: %s",texto);
    printf("\nString invertida: %s\n\n",resultado);

    free(resultado);
  }

return 0;
}