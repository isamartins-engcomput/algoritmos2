// 5 - Faça um procedimento que recebe por parâmetro o tempo de duração de uma fábrica expressa em segundos e imprima esse tempo em horas, minutos e segundos.

#include <stdio.h>

void temporizar (int segundos)
{ 
  int horas, minutos, resto;
  
  horas = segundos / 3600; 
  resto = segundos % 3600;
  minutos = resto / 60;
  segundos = resto % 60;
  
  printf("\nTempo equivalente: %d horas, %d minutos e %d segundos\n\n", horas, minutos, segundos);
}

int main ()
{ 
  int segs;

  printf ("\nDigite o tempo de duracao da fabrica em segundos: ");
  scanf ("%d",&segs);
  
  temporizar(segs);
  
return 0;
}
