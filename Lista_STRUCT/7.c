/* 7) Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos hora,
minuto e segundo. Agora, escreva um programa que leia um vetor de cinco posições dessa
estrutura e imprima a maior hora. */

#include <stdio.h>
#include <locale.h>

struct Hora
{
  int hora;
  int minuto;
  int segundo;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Hora horas[5];

  int indice_maior_hora = 0;

  for (int i = 0; i < 5; i++)
  {
    printf("\nHORA %d\n",i + 1);

    printf("Hora: ");
    scanf("%d",&horas[i].hora);

    printf("Minuto: ");
    scanf("%d",&horas[i].minuto);

    printf("Segundo: ");
    scanf("%d",&horas[i].segundo);
  }

  for (int i = 1; i < 5; i++)
  {
    if (horas[i].hora > horas[indice_maior_hora].hora)
    {
      indice_maior_hora = i;
    }
    else if (horas[i].hora == horas[indice_maior_hora].hora)
    {
      if (horas[i].minuto > horas[indice_maior_hora].minuto)
      {
        indice_maior_hora = i;
      }
      else if (horas[i].minuto == horas[indice_maior_hora].minuto)
      {
        if (horas[i].segundo > horas[indice_maior_hora].segundo)
        {
          indice_maior_hora = i;
        }
      }
    }
  }

  printf("\nMAIOR HORA = %02d:%02d:%02d\n\n",horas[indice_maior_hora].hora,horas[indice_maior_hora].minuto,horas[indice_maior_hora].segundo);

return 0;
}