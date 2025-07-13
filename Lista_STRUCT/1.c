/* 1)  Implemente  um  programa  que  leia  o  nome,  a  idade  e  o  endereço  de  uma 
pessoa  e armazene  esses  dados  em  uma  estrutura.  Em  seguida,  imprima  na  tela
os  dados  da estrutura lida. */

#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Pessoa
{
  char nome[100];
  int idade;
  char endereco[100];
};

int main()
{
  setlocale(LC_ALL,"");

  struct Pessoa pessoa;

  printf("\nQual é o seu nome? ");
  fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
  pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

  printf("Idade? ");
  scanf("%d",&pessoa.idade);
  getchar();

  printf("E seu endereço? ");
  fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);
  pessoa.endereco[strcspn(pessoa.endereco,"\n")] = '\0';

  printf("\nDADOS INSERIDOS\n");
  printf("\nNome: %s",pessoa.nome);
  printf("\nIdade: %d",pessoa.idade);
  printf("\nEndereço: %s\n\n",pessoa.endereco);

return 0;
}