/* 2)  Crie  uma  estrutura  representando  um  aluno  de  uma  disciplina. Essa estrutura
deve conter o número de matrícula do aluno, seu nome e as notas de três provas. Escreva um
programa que mostre o tamanho em byte dessa estrutura. */

#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Aluno
{
  char nome[100];
  int num_matricula;
  float nota1;
  float nota2;
  float nota3;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Aluno aluno;

  printf("\nDigite o nome do aluno: ");
  fgets(aluno.nome, sizeof(aluno.nome), stdin);
  aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

  printf("Digite o número de matrícula do aluno: ");
  scanf("%d",&aluno.num_matricula);
  
  printf("Digite a nota 1 do aluno: ");
  scanf("%f",&aluno.nota1);

  printf("Digite a nota 2 do aluno: ");
  scanf("%f",&aluno.nota2);

  printf("Digite a nota 3 do aluno: ");
  scanf("%f",&aluno.nota3);

  printf("\nTamanho do nome: %zu bytes",sizeof(aluno.nome));
  printf("\nTamanho do número de matrícula: %zu bytes",sizeof(aluno.num_matricula));
  printf("\nTamanho da nota 1: %zu bytes",sizeof(aluno.nota1));
  printf("\nTamanho da nota 2: %zu bytes",sizeof(aluno.nota2));
  printf("\nTamanho da nota 3: %zu bytes\n",sizeof(aluno.nota3));

  printf("\nTamanho total da estrutura aluno: %zu bytes\n\n", sizeof(struct Aluno));

return 0;
}