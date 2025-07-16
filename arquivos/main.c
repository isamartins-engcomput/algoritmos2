#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* AA -  */
#define MAX_NOME 50
#define MAX_SOBRENOME 50
#define ARQUIVO_CSV "dados.csv"
#define TAMANHO_LINHA 256

/* AA -  */
typedef struct {
    char nome[MAX_NOME];
    char sobrenome[MAX_SOBRENOME];
} Pessoa;

/* AA -  */
void criarArquivo(void);
void inserirDados(void);
void buscarDados(void);
void removerDados(void);
void listarRegistros(void);
void exibirMenu(void);
void limparBuffer(void);

/* AA -  */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* AA -  */
void criarArquivo(void) {
    FILE *arquivo = fopen(ARQUIVO_CSV, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    fprintf(arquivo, "nome,sobrenome\n");
    fclose(arquivo);
    printf("Arquivo criado com sucesso!\n");
}

/* AA -  */
void inserirDados(void) {
    FILE *arquivo = fopen(ARQUIVO_CSV, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Pessoa pessoa;
    printf("Digite o nome: ");
    scanf("%s", pessoa.nome);
    limparBuffer();
    
    printf("Digite o sobrenome: ");
    scanf("%s", pessoa.sobrenome);
    limparBuffer();

    fprintf(arquivo, "%s,%s\n", pessoa.nome, pessoa.sobrenome);
    fclose(arquivo);
    printf("Dados inseridos com sucesso!\n");
}

/* AA -  */
void buscarDados(void) {
    FILE *arquivo = fopen(ARQUIVO_CSV, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nomeBusca[MAX_NOME];
    printf("Digite o nome para buscar: ");
    scanf("%s", nomeBusca);
    limparBuffer();

    // Pula a primeira linha (cabeçalho)
    char cabecalho[TAMANHO_LINHA];
    fscanf(arquivo, "%[^\n]\n", cabecalho);

    int encontrado = 0;
    char nome[MAX_NOME], sobrenome[MAX_SOBRENOME];
    
    while (fscanf(arquivo, "%[^,],%[^\n]\n", nome, sobrenome) == 2) {
        if (strcmp(nome, nomeBusca) == 0) {
            printf("Encontrado: %s %s\n", nome, sobrenome);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nome não encontrado!\n");
    }

    fclose(arquivo);
}

/* AA -  */
void removerDados(void) {
    FILE *arquivo = fopen(ARQUIVO_CSV, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    char nomeRemover[MAX_NOME];
    printf("Digite o nome para remover: ");
    scanf("%s", nomeRemover);
    limparBuffer();

    // Copia o cabeçalho
    char cabecalho[TAMANHO_LINHA];
    fscanf(arquivo, "%[^\n]\n", cabecalho);
    fprintf(temp, "%s\n", cabecalho);

    int removido = 0;
    char nome[MAX_NOME], sobrenome[MAX_SOBRENOME];
    
    while (fscanf(arquivo, "%[^,],%[^\n]\n", nome, sobrenome) == 2) {
        if (strcmp(nome, nomeRemover) != 0) {
            fprintf(temp, "%s,%s\n", nome, sobrenome);
        } else {
            removido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO_CSV);
    rename("temp.csv", ARQUIVO_CSV);

    if (removido) {
        printf("Dados removidos com sucesso!\n");
    } else {
        printf("Nome não encontrado!\n");
    }
}

/* AA -  */
void listarRegistros(void) {
    FILE *arquivo = fopen(ARQUIVO_CSV, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int contador = 0;

    // Pula a primeira linha (cabeçalho)
    char cabecalho[TAMANHO_LINHA];
    fscanf(arquivo, "%[^\n]\n", cabecalho);

    printf("\n=== LISTA DE REGISTROS ===\n");
    printf("Nome\t\tSobrenome\n");
    printf("------------------------\n");

    char nome[MAX_NOME], sobrenome[MAX_SOBRENOME];
    while (fscanf(arquivo, "%[^,],%[^\n]\n", nome, sobrenome) == 2) {
        printf("%-15s %-15s\n", nome, sobrenome);
        contador++;
    }

    if (contador == 0) {
        printf("Nenhum registro encontrado!\n");
    } else {
        printf("\nTotal de registros: %d\n", contador);
    }

    fclose(arquivo);
}

/* AA -  */
void exibirMenu(void) {
    printf("\n=== MENU ===\n");
    printf("1. Criar arquivo\n");
    printf("2. Inserir dados\n");
    printf("3. Buscar dados\n");
    printf("4. Remover dados\n");
    printf("5. Listar todos os registros\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

/* AA -  */
int main(void) {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                criarArquivo();
                break;
            case 2:
                inserirDados();
                break;
            case 3:
                buscarDados();
                break;
            case 4:
                removerDados();
                break;
            case 5:
                listarRegistros();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
} 