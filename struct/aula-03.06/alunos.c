#include <stdio.h>
#include <string.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Aluno
{
    char nome[100];
    int matricula;
    float media_geral;
    struct Data data_nascimento;
};

int main()
{
    struct Data data_nascimento;
    struct Aluno aluno1;

    strcpy(aluno1.nome,"Isadora Martins");
    aluno1.matricula = 1234123;
    aluno1.media_geral = 7.5;
    aluno1.data_nascimento.dia = 19;
    aluno1.data_nascimento.mes = 6;
    aluno1.data_nascimento.ano = 2006;

    printf("\nNome: %s",aluno1.nome);
    printf("\nMatrícula: %d",aluno1.matricula);
    printf("\nData de nascimento: %d/%d/%d\n\n",
    aluno1.data_nascimento.dia,
    aluno1.data_nascimento.mes,
    aluno1.data_nascimento.ano);

return 0;
}