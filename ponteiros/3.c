// 3 – É possível criar um vetor de ponteiros? Há diferença na forma de utilizar? ex: int *v[10];

/* Sim, é possível criar um vetor de ponteiros em C. Quando você declara algo como: int *v[10];
Você está criando um vetor com 10 posições, onde cada posição armazena um ponteiro para int.
Ou seja, em vez de armazenar diretamente números inteiros (como em int v[10];),
esse vetor armazena endereços de variáveis do tipo int. */

#include <stdio.h>

int main()
{
  int a = 10, b = 20, c = 30;
  int *v[3]; // vetor de 3 ponteiros para int

  v[0] = &a; // cada posição aponta para uma variável
  v[1] = &b;
  v[2] = &c;

  printf("\n");
  
  // imprimindo os valores apontados
  for (int i = 0; i < 3; i++)
  {
    printf("v[%d] aponta para valor = %d\n", i, *v[i]);
  }
  printf("\n");

return 0;
}