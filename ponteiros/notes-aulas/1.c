/* 1 – Implemente um exemplo mostrando as diferenças dos três itens abaixo:
*pa++; , (*pa)++; e *(pa++); */

#include <stdio.h>

int main()
{
  int vetor[] = {10, 20, 30};
  int *pa;

  printf("\nValores iniciais: vetor[0] = %d, vetor[1] = %d, vetor[2] = %d\n", vetor[0], vetor[1], vetor[2]);

  // 1. Testando (*pa)++
  pa = vetor; // pa aponta para vetor[0]
  printf("\nAntes de (*pa)++:\n");
  printf("*pa = %d\n", *pa); // 10
  printf("pa = %p\n", (void*)pa);

  (*pa)++; // Incrementa o valor apontado (10 vira 11)

  printf("\nDepois de (*pa)++:\n");
  printf("*pa = %d\n", *pa); // 11
  printf("pa = %p (continua igual)\n", (void*)pa);
  printf("vetor[0] = %d\n", vetor[0]); // 11

  // 2. Testando *pa++
  pa = vetor; // resetando pa para vetor[0]
  printf("\n\nAntes de *pa++:\n");
  printf("*pa = %d\n", *pa); // 11 (foi alterado antes)
  printf("pa = %p\n", (void*)pa);

  int valor = *pa++; // acessa o valor (11), depois pa vai para o próximo

  printf("\nDepois de *pa++:\n");
  printf("valor armazenado = %d\n", valor); // 11
  printf("*pa = %d\n", *pa); // agora aponta para 20
  printf("pa = %p (mudou)\n", (void*)pa);

  // 3. Testando *(pa++)
  pa = vetor; // resetando pa para vetor[0]
  printf("\n\nAntes de *(pa++):\n");
  printf("*pa = %d\n", *pa); // 11
  printf("pa = %p\n", (void*)pa);

  *(pa++); // acessa o valor (11) mas não faz nada com ele, só move o ponteiro

  printf("\nDepois de *(pa++):\n");
  printf("*pa = %d\n", *pa); // agora aponta para 20
  printf("pa = %p (mudou)\n\n", (void*)pa);

return 0;
}