#include <stdio.h>
#include "teste-prova1.h"

int main()
{
  int matriz[LINHAS][COLUNAS];

  gerar_matriz(matriz);
  printar_matriz(matriz);

  printf("\nMedia: %.2f",calcular_media(matriz));
  printf("\nMediana: %d\n\n",calcular_mediana(matriz));

  gerar_csv(matriz);

return 0;
}