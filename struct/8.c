/* 8) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa.
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes da
pessoa mais nova e da mais velha. */

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Data
{
  int dia;
  int mes;
  int ano;
};

struct Pessoa
{
  char nome[100];
  struct Data nascimento;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Pessoa pessoas[6];
  
  int indice_mais_velha = 0;
  int indice_mais_nova = 0;

  for (int i = 0; i < 6; i++)
  {
    printf("\nPESSOA %d\n",i + 1);

    printf("Nome: ");
    fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
    pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d",&pessoas[i].nascimento.dia,&pessoas[i].nascimento.mes,&pessoas[i].nascimento.ano);
    
    getchar();
  }

  for (int i = 1; i < 6; i++)
  {
    if(pessoas[i].nascimento.ano < pessoas[indice_mais_velha].nascimento.ano ||
    (pessoas[i].nascimento.ano == pessoas[indice_mais_velha].nascimento.ano &&
    pessoas[i].nascimento.mes < pessoas[indice_mais_velha].nascimento.mes) ||
    (pessoas[i].nascimento.ano == pessoas[indice_mais_velha].nascimento.ano &&
    pessoas[i].nascimento.mes == pessoas[indice_mais_velha].nascimento.mes &&
    pessoas[i].nascimento.dia < pessoas[indice_mais_velha].nascimento.dia))
    {
      indice_mais_velha = i;
    }

    if(pessoas[i].nascimento.ano > pessoas[indice_mais_nova].nascimento.ano ||
    (pessoas[i].nascimento.ano == pessoas[indice_mais_nova].nascimento.ano &&
    pessoas[i].nascimento.mes > pessoas[indice_mais_nova].nascimento.mes) ||
    (pessoas[i].nascimento.ano == pessoas[indice_mais_nova].nascimento.ano &&
    pessoas[i].nascimento.mes == pessoas[indice_mais_nova].nascimento.mes &&
    pessoas[i].nascimento.dia > pessoas[indice_mais_nova].nascimento.dia))
    {
      indice_mais_nova = i;
    }
  }

  printf("\n\nPessoa mais velha: %s\n",pessoas[indice_mais_velha].nome);
  printf("Data de nascimento: %02d/%02d/%04d\n",pessoas[indice_mais_velha].nascimento.dia,pessoas[indice_mais_velha].nascimento.mes,pessoas[indice_mais_velha].nascimento.ano);

  printf("\nPessoa mais nova: %s\n", pessoas[indice_mais_nova].nome);
  printf("Data de nascimento: %02d/%02d/%04d\n\n",pessoas[indice_mais_nova].nascimento.dia,pessoas[indice_mais_nova].nascimento.mes,pessoas[indice_mais_nova].nascimento.ano);

return 0;
}