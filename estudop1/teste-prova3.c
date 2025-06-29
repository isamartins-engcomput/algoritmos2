#include <stdio.h>
#include "teste-prova3.h"

int main ()
{
  int matriz[LINHAS][COLUNAS];

  gerar_matriz(matriz);
  printar_matriz(matriz);

  printf("\nMedia: %d\n",calcular_media(matriz));
  printf("Mediana: %d\n\n",calcular_mediana(matriz));

  gerar_csv(matriz);

return 0;
}