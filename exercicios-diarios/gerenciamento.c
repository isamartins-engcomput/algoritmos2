/* Sistema de Gerenciamento de Notas

Implemente um sistema em linguagem C para gerenciar as notas de alunos de uma disciplina. O
sistema deve permitir cadastrar, listar, buscar e remover alunos, usando funções, ponteiros e
arquivos em modo texto, com o código modularizado em bibliotecas.

Todas as informações dos alunos devem ser armazenadas em um arquivo texto chamado notas.txt.

Cada linha do arquivo representa um aluno com os seguintes dados:
<codigo> <nota1> <nota2> <nota3>
Exemplo:
1001 7.5 8.0 6.0
1002 5.0 4.5 6.5

Você deverá implementar as seguintes funcionalidades:
1. Cadastrar aluno
Recebe código e 3 notas do aluno e grava no arquivo notas.txt
2. Listar alunos
Lê o arquivo e mostra todos os alunos, suas médias e se estão Aprovados/Reprovados
3. Buscar por código
Busca e mostra os dados de um aluno específico usando seu código
4. Remover aluno
Remove um aluno do arquivo com base no código informado
Cada operação deve estar implementada como função separada no arquivo notas.c e declarada
em notas.h.
• O programa principal (main.c) deve conter o menu e chamar as funções do módulo.
• A média do aluno deve ser calculada com: float calcularMedia(float n1, float n2, float n3);

Um aluno é aprovado se a média for ≥ 6.0. */

#include <stdio.h>
#include <stdlib.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {
    int opcao;

    do {
        printf("\n=== Sistema de Gerenciamento de Notas ===\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno por codigo\n");
        printf("4 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            FILE *arquivo = fopen("notas.txt", "a");
            int codigo;
            float n1, n2, n3;

            printf("Digite o codigo do aluno: ");
            scanf("%d", &codigo);
            printf("Digite as 3 notas: ");
            scanf("%f %f %f", &n1, &n2, &n3);

            fprintf(arquivo, "%d %.1f %.1f %.1f\n", codigo, n1, n2, n3);
            fclose(arquivo);

        } else if (opcao == 2) {
            FILE *arquivo = fopen("notas.txt", "r");
            int codigo;
            float n1, n2, n3, media;

            if (arquivo == NULL) {
                printf("Arquivo nao encontrado.\n");
            } else {
                printf("\nLista de Alunos:\n");
                while (fscanf(arquivo, "%d %f %f %f", &codigo, &n1, &n2, &n3) == 4) {
                    media = calcularMedia(n1, n2, n3);
                    printf("Codigo: %d | Notas: %.1f %.1f %.1f | Media: %.1f | %s\n",
                        codigo, n1, n2, n3, media, media >= 6.0 ? "Aprovado" : "Reprovado");
                }
                fclose(arquivo);
            }

        } else if (opcao == 3) {
            FILE *arquivo = fopen("notas.txt", "r");
            int codigo, buscado;
            float n1, n2, n3, media;
            int achou = 0;

            if (arquivo == NULL) {
                printf("Arquivo nao encontrado.\n");
            } else {
                printf("Digite o codigo do aluno: ");
                scanf("%d", &buscado);

                while (fscanf(arquivo, "%d %f %f %f", &codigo, &n1, &n2, &n3) == 4) {
                    if (codigo == buscado) {
                        media = calcularMedia(n1, n2, n3);
                        printf("Codigo: %d | Notas: %.1f %.1f %.1f | Media: %.1f | %s\n",
                            codigo, n1, n2, n3, media, media >= 6.0 ? "Aprovado" : "Reprovado");
                        achou = 1;
                        break;
                    }
                }
                if (!achou) {
                    printf("Aluno nao encontrado.\n");
                }
                fclose(arquivo);
            }

        } else if (opcao == 4) {
            FILE *arquivo = fopen("notas.txt", "r");
            FILE *temp = fopen("temp.txt", "w");
            int codigo, remover;
            float n1, n2, n3;
            int achou = 0;

            if (arquivo == NULL || temp == NULL) {
                printf("Erro ao abrir os arquivos.\n");
            } else {
                printf("Digite o codigo do aluno que deseja remover: ");
                scanf("%d", &remover);

                while (fscanf(arquivo, "%d %f %f %f", &codigo, &n1, &n2, &n3) == 4) {
                    if (codigo != remover) {
                        fprintf(temp, "%d %.1f %.1f %.1f\n", codigo, n1, n2, n3);
                    } else {
                        achou = 1;
                    }
                }
                fclose(arquivo);
                fclose(temp);
                remove("notas.txt");
                rename("temp.txt", "notas.txt");

                if (achou) {
                    printf("Aluno removido com sucesso.\n");
                } else {
                    printf("Aluno nao encontrado.\n");
                }
            }

        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

return 0;
}