/* 2)  Escreva um programa que contenha duas variáveis  inteiras. Leia  essas variáveis 
do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço. */

#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"");
  
  int a;
  int b;

  int *pa;
  int *pb;

  printf("\nDigite um valor para a: ");
  scanf("%d",&a);

  printf("Digite um valor para b: ");
  scanf("%d",&b);

  pa = &a;
  pb = &b;

  printf("\nEndereço de a: %p",pa);
  printf("\nEndereço de b: %p",pb);

  if (pa > pb)
  {
    printf("\n\nMaior endereço: %p => Valor armazenado (a): %d\n\n",pa,*pa);
  }
  else
  {
    printf("\n\nMaior endereço: %p => Valor armazenado (b): %d\n\n",pb,*pb);
  }

return 0;
}