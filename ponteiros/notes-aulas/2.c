/* 2 – Considerando que string é uma sequência de caracteres na memória, sua
implementação é similar a de um vetor, dessa forma implemente um exemplo utilizando
ponteiros para percorrer uma string. */

#include <stdio.h>

int main()
{
  char texto[] = "Hello, world!";
  char *p = texto; // ponteiro para o início da string

  printf("\nPercorrendo a string \"Hello, world!\" com ponteiros:\n\n");

  while (*p != '\0') // enquanto não chegar no fim da string
  {
    printf("Caractere: %c Endereco: %p\n", *p, (void*)p); // imprime o caractere atual
    p++; // vai para o próximo caractere
  }
  printf("\n");

return 0;
}