// QUESTAO 7 - eleicao

#include <stdio.h>

int main ()
{
  int voto;
  int contB = 0, contK = 0, contZ = 0, cont_nulos = 0, cont_brancos = 0;
  
  for (int i = 1; i <= 20; i++)
  {
    printf ("\n\n///// ELEICAO 2025 /////\n");
    printf ("\nDígito 1 => Candidato B");
    printf ("\nDígito 2 => Candidato K");
    printf ("\nDígito 3 => Candidato Z");
    printf ("\n*Digite 123 para votar NULO");
    printf ("\n*Digite 0 para votar em BRANCO\n");
    
    printf ("\nTurno %d",i);
    
    printf ("\n\nDigite seu candidato: ");
    scanf ("%d",&voto);
    
    if (voto == 1)
    {
      printf ("\nSeu voto foi para o candidato B.");
      contB = contB + 1;
    }
    if (voto == 2)
    {
      printf ("\nSeu voto foi para o candidato K.");
      contK = contK + 1;
    }
    if (voto == 3)
    {
      printf ("\nSeu voto foi para o candidato Z.");
      contZ = contZ + 1;
    }
    if (voto == 123)
    {
      printf ("\nVoce votou nulo!");
      cont_nulos = cont_nulos + 1;
    }
    if (voto == 0)
    {
      printf ("\nVoce votou em branco!");
      cont_brancos = cont_brancos + 1;
    }
  }
  
  printf ("\n\n\n///// FIM DA ELEICAO 2025 /////\n");
  printf ("\nQuantidade de votos para o candidato B: %d",contB);
  printf ("\nQuantidade de votos para o candidato K: %d",contK);
  printf ("\nQuantidade de votos para o candidato Z: %d",contZ);
  printf ("\nQuantidade de votos nulos: %d",cont_nulos);
  printf ("\nQuantidade de votos em branco: %d\n\n",cont_brancos);
  
return 0;
}
