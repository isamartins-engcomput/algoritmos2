/* 6)  Crie  uma  estrutura  representando  um  aluno  de  uma  disciplina.  Essa estrutura
deve conter o número de matrícula do aluno, seu nome e as notas de três provas.
Agora, escreva um  programa  que  leia  os  dados  de  cinco  alunos  e  os  armazene nessa
estrutura.  Em seguida, exiba o nome e as notas do aluno que possui a maior média geral
dentre os cinco. */

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Aluno
{
  int matricula;
  char nome[100];
  float nota1;
  float nota2;
  float nota3;
};

int main()
{
  setlocale(LC_ALL,"");

  struct Aluno alunos[5];

  int indice_maior_media = 0;
  float media, maior_media = 0;

  for (int i = 0; i < 5; i++)
  {
    printf("\nALUNO %d\n",i + 1);

    printf("Matrícula: ");
    scanf("%d",&alunos[i].matricula);
    getchar();

    printf("Nome: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

    printf("Nota 1: ");
    scanf("%f",&alunos[i].nota1);

    printf("Nota 2: ");
    scanf("%f",&alunos[i].nota2);

    printf("Nota 3: ");
    scanf("%f",&alunos[i].nota3);

    media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

    if(media > maior_media)
    {
      maior_media = media;
      indice_maior_media = i;
    }
  }

  printf("\n\nAluno com maior média geral\n");
  printf("Nome: %s\n",alunos[indice_maior_media].nome);
  printf("Nota 1: %.2f\n",alunos[indice_maior_media].nota1);
  printf("Nota 2: %.2f\n",alunos[indice_maior_media].nota2);
  printf("Nota 3: %.2f\n\n",alunos[indice_maior_media].nota3);
  printf("Nota 3: %.2f\n\n",maior_media);

return 0;
}