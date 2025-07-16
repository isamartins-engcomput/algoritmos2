/*
  Sistema completo para gerenciamento de Clientes e Recebimentos.

  Este programa reúne a implementação dos Exercícios 1 a 11 do conjunto de
  exercícios desta lista, com funcionalidades que incluem:

    1 - Criação dos arquivos clientes.csv e recebimentos.csv com cabeçalhos.
    2 - Cadastro de clientes, evitando duplicatas.
    3 - Inclusão de recebimentos com verificação prévia do cliente.
    4 - Exclusão de clientes e seus recebimentos relacionados.
    5 - Alteração de cadastro de clientes.
    6 - Alteração de dados de recebimentos.
    7 - Consulta de recebimentos dentro de um período, com cálculo de atraso.
    8 - Listagem de recebimentos por cliente.
    9 - Listagem de recebimentos com valor acima de um limite.
   10 - Listagem de recebimentos com valor abaixo de um limite.
   11 - Listagem de recebimentos com valor entre dois limites.

  O programa é modularizado, com funções separadas para cada funcionalidade,
  e utiliza arquivos CSV para armazenamento persistente dos dados.

  A interação é feita via menu, permitindo fácil navegação entre as opções.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_NOME 100
#define MAX_END 100
#define MAX_DATA 20
#define CLIENTES_ARQ "clientes.csv"
#define RECEBIMENTOS_ARQ "recebimentos.csv"

typedef struct {
    int cod_cli;
    char nome[MAX_NOME];
    char endereco[MAX_END];
    long int fone;
} Cliente;

typedef struct {
    int num_doc;
    int valor_doc;
    char data_emissao[MAX_DATA];
    char data_venc[MAX_DATA];
    int cod_cli;
} Recebimento;

void criar_arquivo_clientes();
void criar_arquivo_recebimentos();
void tira_enter(char *str);
int cliente_existe(int cod_cli);
int buscar_cliente(int cod_cli, Cliente *cliente);
void cadastrar_clientes();
void cadastrar_recebimentos();
void excluir_cliente();
void alterar_cliente();
void alterar_recebimento();
time_t converter_data(const char *data);
void mostrar_recebimentos_periodo();
void mostrar_recebimentos_cliente();
void mostrar_recebimentos_acima();
void mostrar_recebimentos_abaixo();
void mostrar_recebimentos_entre();
void menu();

void criar_arquivo_clientes()
{
    FILE *f = fopen(CLIENTES_ARQ, "r");
    if (!f)
    {
        f = fopen(CLIENTES_ARQ, "w");
        if (!f)
        {
            printf("\nErro ao criar arquivo %s\n", CLIENTES_ARQ);
            exit(1);
        }
        fprintf(f, "Cod_Cli,Nome,Endereco,Fone\n");
        fclose(f);
    }
    else fclose(f);
}

void criar_arquivo_recebimentos()
{
    FILE *f = fopen(RECEBIMENTOS_ARQ, "r");
    if (!f)
    {
        f = fopen(RECEBIMENTOS_ARQ, "w");
        if (!f)
        {
            printf("\nErro ao criar arquivo %s\n", RECEBIMENTOS_ARQ);
            exit(1);
        }
        fprintf(f, "Num_doc,Valor_doc,Data_Emissao,Data_Vencimento,Cod_Cli\n");
        fclose(f);
    }
    else fclose(f);
}

void tira_enter(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

int cliente_existe(int cod_cli)
{
    FILE *f = fopen(CLIENTES_ARQ, "r");
    if (!f) return 0;
    char linha[256];
    fgets(linha, sizeof(linha), f); // pular cabecalho

    while (fgets(linha, sizeof(linha), f))
    {
        int codigo;
        sscanf(linha, "%d,", &codigo);
        if (codigo == cod_cli)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int buscar_cliente(int cod_cli, Cliente *cliente)
{
    FILE *f = fopen(CLIENTES_ARQ, "r");
    if (!f) return 0;
    char linha[256];
    fgets(linha, sizeof(linha), f); // pula cabecalho

    while (fgets(linha, sizeof(linha), f))
    {
        Cliente c;
        char *token = strtok(linha, ",");
        c.cod_cli = atoi(token);

        if (c.cod_cli == cod_cli)
        {
            token = strtok(NULL, ",");
            strcpy(c.nome, token);

            token = strtok(NULL, ",");
            strcpy(c.endereco, token);

            token = strtok(NULL, ",");
            c.fone = atol(token);

            *cliente = c;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void cadastrar_clientes()
{
    FILE *f = fopen(CLIENTES_ARQ, "a");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de clientes.\n");
        return;
    }

    int qtd;
    printf("\nQuantos clientes deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar();

    for (int i = 0; i < qtd; i++)
    {
        Cliente c;

        printf("\nCLIENTE %d\n\n", i + 1);
        printf("Código do cliente: ");
        scanf("%d", &c.cod_cli);
        getchar();

        if (cliente_existe(c.cod_cli))
        {
            printf("\nCliente com código %d já cadastrado! Pulando...\n", c.cod_cli);
            i--;
            continue;
        }

        printf("Nome: ");
        fgets(c.nome, MAX_NOME, stdin);
        tira_enter(c.nome);

        printf("Endereço: ");
        fgets(c.endereco, MAX_END, stdin);
        tira_enter(c.endereco);

        printf("Telefone: ");
        scanf("%ld", &c.fone);
        getchar();

        fprintf(f, "%d,%s,%s,%ld\n", c.cod_cli, c.nome, c.endereco, c.fone);
        printf("\nCliente cadastrado com sucesso!\n");
    }

    fclose(f);
}

void cadastrar_recebimentos()
{
    FILE *f = fopen(RECEBIMENTOS_ARQ, "a");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de recebimentos.\n");
        return;
    }

    int qtd;
    printf("\nQuantos recebimentos deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar();

    for (int i = 0; i < qtd; i++)
    {
        Recebimento r;

        printf("\nRECEBIMENTO %d\n\n", i + 1);

        printf("Número do documento: ");
        scanf("%d", &r.num_doc);
        getchar();

        printf("Valor do documento: ");
        scanf("%d", &r.valor_doc);
        getchar();

        printf("Data de emissão (DD/MM/AAAA): ");
        fgets(r.data_emissao, MAX_DATA, stdin);
        tira_enter(r.data_emissao);

        printf("Data de vencimento (DD/MM/AAAA): ");
        fgets(r.data_venc, MAX_DATA, stdin);
        tira_enter(r.data_venc);

        printf("Código do cliente: ");
        scanf("%d", &r.cod_cli);
        getchar();

        if (!cliente_existe(r.cod_cli))
        {
            printf("\nCliente com código %d não existe! Recebimento não cadastrado.\n", r.cod_cli);
            i--;
            continue;
        }

        fprintf(f, "%d,%d,%s,%s,%d\n", r.num_doc, r.valor_doc, r.data_emissao, r.data_venc, r.cod_cli);
        printf("\nRecebimento cadastrado com sucesso!\n");
    }

    fclose(f);
}

void excluir_cliente()
{
    int cod_cli;
    printf("\nInforme o código do cliente a ser excluído: ");
    scanf("%d", &cod_cli);
    getchar();

    if (!cliente_existe(cod_cli))
    {
        printf("\nCliente não encontrado.\n");
        return;
    }

    FILE *f_in = fopen(CLIENTES_ARQ, "r");
    FILE *f_out = fopen("temp_clientes.csv", "w");
    if (!f_in || !f_out)
    {
        printf("\nErro ao abrir arquivos para exclusão.\n");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f_in);
    fprintf(f_out, "%s", linha);

    while (fgets(linha, sizeof(linha), f_in))
    {
        int codigo;
        sscanf(linha, "%d,", &codigo);
        if (codigo != cod_cli)
            fputs(linha, f_out);
    }
    fclose(f_in);
    fclose(f_out);

    remove(CLIENTES_ARQ);
    rename("temp_clientes.csv", CLIENTES_ARQ);

    f_in = fopen(RECEBIMENTOS_ARQ, "r");
    f_out = fopen("temp_recebimentos.csv", "w");
    if (!f_in || !f_out)
    {
        printf("\nErro ao abrir arquivos para exclusão de recebimentos.\n");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    fgets(linha, sizeof(linha), f_in);
    fprintf(f_out, "%s", linha);

    while (fgets(linha, sizeof(linha), f_in))
    {
        int codigo;
        char *p = strrchr(linha, ',');
        if (p) codigo = atoi(p + 1);
        else codigo = -1;

        if (codigo != cod_cli)
            fputs(linha, f_out);
    }
    fclose(f_in);
    fclose(f_out);

    remove(RECEBIMENTOS_ARQ);
    rename("temp_recebimentos.csv", RECEBIMENTOS_ARQ);

    printf("\nCliente e seus recebimentos excluídos com sucesso!\n");
}

void alterar_cliente()
{
    int cod_cli;
    printf("\nInforme o código do cliente a alterar: ");
    scanf("%d", &cod_cli);
    getchar();

    if (!cliente_existe(cod_cli))
    {
        printf("\nCliente não encontrado.\n");
        return;
    }

    FILE *f_in = fopen(CLIENTES_ARQ, "r");
    FILE *f_out = fopen("temp_clientes.csv", "w");
    if (!f_in || !f_out)
    {
        printf("\nErro ao abrir arquivos para alteração.\n");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f_in);
    fprintf(f_out, "%s", linha);

    while (fgets(linha, sizeof(linha), f_in))
    {
        int codigo;
        sscanf(linha, "%d,", &codigo);
        if (codigo == cod_cli)
        {
            Cliente c;
            c.cod_cli = cod_cli;

            printf("\nNovo nome: ");
            fgets(c.nome, MAX_NOME, stdin);
            tira_enter(c.nome);

            printf("Novo endereço: ");
            fgets(c.endereco, MAX_END, stdin);
            tira_enter(c.endereco);

            printf("Novo telefone: ");
            scanf("%ld", &c.fone);
            getchar();

            fprintf(f_out, "%d,%s,%s,%ld\n", c.cod_cli, c.nome, c.endereco, c.fone);
        }
        else
        {
            fputs(linha, f_out);
        }
    }

    fclose(f_in);
    fclose(f_out);

    remove(CLIENTES_ARQ);
    rename("temp_clientes.csv", CLIENTES_ARQ);

    printf("\nCliente alterado com sucesso!\n");
}

void alterar_recebimento()
{
    int num_doc, cod_cli;
    printf("\nInforme o número do documento a alterar: ");
    scanf("%d", &num_doc);
    getchar();

    printf("\nInforme o código do cliente do recebimento: ");
    scanf("%d", &cod_cli);
    getchar();

    FILE *f_in = fopen(RECEBIMENTOS_ARQ, "r");
    FILE *f_out = fopen("temp_recebimentos.csv", "w");
    if (!f_in || !f_out)
    {
        printf("\nErro ao abrir arquivos para alteração.\n");
        if (f_in) fclose(f_in);
        if (f_out) fclose(f_out);
        return;
    }

    char linha[256];
    int encontrou = 0;

    fgets(linha, sizeof(linha), f_in);
    fprintf(f_out, "%s", linha);

    while (fgets(linha, sizeof(linha), f_in))
    {
        int nd, vc, cc;
        char de[MAX_DATA], dv[MAX_DATA];
        sscanf(linha, "%d,%d,%[^,],%[^,],%d", &nd, &vc, de, dv, &cc);

        if (nd == num_doc && cc == cod_cli)
        {
            Recebimento r;
            r.num_doc = nd;
            r.cod_cli = cc;

            printf("\nNovo valor do documento: ");
            scanf("%d", &r.valor_doc);
            getchar();

            printf("Nova data de emissão (DD/MM/AAAA): ");
            fgets(r.data_emissao, MAX_DATA, stdin);
            tira_enter(r.data_emissao);

            printf("Nova data de vencimento (DD/MM/AAAA): ");
            fgets(r.data_venc, MAX_DATA, stdin);
            tira_enter(r.data_venc);

            fprintf(f_out, "%d,%d,%s,%s,%d\n", r.num_doc, r.valor_doc, r.data_emissao, r.data_venc, r.cod_cli);
            encontrou = 1;
        }
        else
        {
            fputs(linha, f_out);
        }
    }

    fclose(f_in);
    fclose(f_out);

    if (!encontrou)
    {
        printf("\nRecebimento não encontrado.\n");
        remove("temp_recebimentos.csv");
        return;
    }

    remove(RECEBIMENTOS_ARQ);
    rename("temp_recebimentos.csv", RECEBIMENTOS_ARQ);

    printf("\nRecebimento alterado com sucesso!\n");
}

time_t converter_data(const char *data)
{
    struct tm tm_data = {0};
    sscanf(data, "%2d/%2d/%4d", &tm_data.tm_mday, &tm_data.tm_mon, &tm_data.tm_year);
    tm_data.tm_mon -= 1;
    tm_data.tm_year -= 1900;
    tm_data.tm_hour = 0;
    tm_data.tm_min = 0;
    tm_data.tm_sec = 0;
    return mktime(&tm_data);
}

void mostrar_recebimentos_periodo()
{
    char inicio[MAX_DATA], fim[MAX_DATA];
    printf("\nInforme a data inicial (DD/MM/AAAA): ");
    fgets(inicio, MAX_DATA, stdin);
    tira_enter(inicio);
    printf("Informe a data final (DD/MM/AAAA): ");
    fgets(fim, MAX_DATA, stdin);
    tira_enter(fim);

    time_t t_inicio = converter_data(inicio);
    time_t t_fim = converter_data(fim);

    FILE *f_rec = fopen(RECEBIMENTOS_ARQ, "r");
    FILE *f_cli = fopen(CLIENTES_ARQ, "r");
    if (!f_rec || !f_cli)
    {
        printf("\nErro ao abrir arquivos.\n");
        if (f_rec) fclose(f_rec);
        if (f_cli) fclose(f_cli);
        return;
    }

    char linha_rec[256];
    char linha_cli[256];

    fgets(linha_rec, sizeof(linha_rec), f_rec);
    fgets(linha_cli, sizeof(linha_cli), f_cli);

    printf("\nRecebimentos no período %s a %s:\n\n", inicio, fim);
    printf("Num_doc | Valor | Data Vencimento | Cod_Cli | Nome Cliente | Dias em atraso\n");
    printf("-------------------------------------------------------------------------------\n");

    time_t hoje = time(NULL);

    while (fgets(linha_rec, sizeof(linha_rec), f_rec))
    {
        Recebimento r;
        sscanf(linha_rec, "%d,%d,%[^,],%[^,],%d", &r.num_doc, &r.valor_doc, r.data_emissao, r.data_venc, &r.cod_cli);

        time_t venc = converter_data(r.data_venc);

        if (venc >= t_inicio && venc <= t_fim)
        {
            Cliente c;
            if (buscar_cliente(r.cod_cli, &c))
            {
                double diff = difftime(hoje, venc);
                int dias_atraso = diff > 0 ? (int)(diff / (60*60*24)) : 0;

                printf("%7d | %5d | %14s | %7d | %-12s | %13d\n",
                       r.num_doc, r.valor_doc, r.data_venc, r.cod_cli, c.nome, dias_atraso);
            }
        }
    }

    fclose(f_rec);
    fclose(f_cli);
}

void mostrar_recebimentos_cliente()
{
    int cod_cli;
    printf("\nInforme o código do cliente: ");
    scanf("%d", &cod_cli);
    getchar();

    if (!cliente_existe(cod_cli))
    {
        printf("\nCliente não encontrado.\n");
        return;
    }

    FILE *f = fopen(RECEBIMENTOS_ARQ, "r");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de recebimentos.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f);

    printf("\nRecebimentos do cliente %d:\n", cod_cli);
    printf("\nNum_doc | Valor | Data Emissão | Data Vencimento\n");
    printf("----------------------------------------------\n");

    while (fgets(linha, sizeof(linha), f))
    {
        int nd, val, cc;
        char de[MAX_DATA], dv[MAX_DATA];
        sscanf(linha, "%d,%d,%[^,],%[^,],%d", &nd, &val, de, dv, &cc);

        if (cc == cod_cli)
        {
            printf("%7d | %5d | %12s | %14s\n", nd, val, de, dv);
        }
    }
    fclose(f);
}

void mostrar_recebimentos_acima()
{
    int limite;
    printf("\nInforme o valor mínimo: ");
    scanf("%d", &limite);
    getchar();

    FILE *f = fopen(RECEBIMENTOS_ARQ, "r");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de recebimentos.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f);

    printf("\nRecebimentos com valor acima de %d:\n", limite);
    printf("\nNum_doc | Valor | Data Emissão | Data Vencimento | Cod_Cli\n");
    printf("--------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), f))
    {
        int nd, val, cc;
        char de[MAX_DATA], dv[MAX_DATA];
        sscanf(linha, "%d,%d,%[^,],%[^,],%d", &nd, &val, de, dv, &cc);

        if (val > limite)
        {
            printf("%7d | %5d | %12s | %14s | %7d\n", nd, val, de, dv, cc);
        }
    }

    fclose(f);
}

void mostrar_recebimentos_abaixo()
{
    int limite;
    printf("\nInforme o valor máximo: ");
    scanf("%d", &limite);
    getchar();

    FILE *f = fopen(RECEBIMENTOS_ARQ, "r");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de recebimentos.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f);

    printf("\nRecebimentos com valor abaixo de %d:\n", limite);
    printf("\nNum_doc | Valor | Data Emissão | Data Vencimento | Cod_Cli\n");
    printf("--------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), f))
    {
        int nd, val, cc;
        char de[MAX_DATA], dv[MAX_DATA];
        sscanf(linha, "%d,%d,%[^,],%[^,],%d", &nd, &val, de, dv, &cc);

        if (val < limite)
        {
            printf("%7d | %5d | %12s | %14s | %7d\n", nd, val, de, dv, cc);
        }
    }

    fclose(f);
}

void mostrar_recebimentos_entre()
{
    int min, max;
    printf("\nInforme o valor mínimo: ");
    scanf("%d", &min);
    getchar();

    printf("\nInforme o valor máximo: ");
    scanf("%d", &max);
    getchar();

    if (min > max)
    {
        int tmp = min;
        min = max;
        max = tmp;
    }

    FILE *f = fopen(RECEBIMENTOS_ARQ, "r");
    if (!f)
    {
        printf("\nErro ao abrir arquivo de recebimentos.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), f);

    printf("\nRecebimentos com valor entre %d e %d:\n", min, max);
    printf("\nNum_doc | Valor | Data Emissão | Data Vencimento | Cod_Cli\n");
    printf("--------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), f))
    {
        int nd, val, cc;
        char de[MAX_DATA], dv[MAX_DATA];
        sscanf(linha, "%d,%d,%[^,],%[^,],%d", &nd, &val, de, dv, &cc);

        if (val >= min && val <= max)
        {
            printf("%7d | %5d | %12s | %14s | %7d\n", nd, val, de, dv, cc);
        }
    }

    fclose(f);
}

void menu()
{
    int opcao;
    do
    {
        printf("\n----------- SISTEMA CLIENTES E RECEBIMENTOS -----------\n\n");
        printf("1 - Criar arquivos (clientes e recebimentos)\n");
        printf("2 - Cadastrar clientes\n");
        printf("3 - Cadastrar recebimentos (verificando cliente)\n");
        printf("4 - Excluir cliente e seus recebimentos\n");
        printf("5 - Alterar cadastro do cliente\n");
        printf("6 - Alterar recebimento\n");
        printf("7 - Mostrar recebimentos dentro de um período\n");
        printf("8 - Mostrar recebimentos de um cliente\n");
        printf("9 - Mostrar recebimentos com valor acima de um limite\n");
        printf("10 - Mostrar recebimentos com valor abaixo de um limite\n");
        printf("11 - Mostrar recebimentos com valor entre dois valores\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                criar_arquivo_clientes();
                criar_arquivo_recebimentos();
                printf("\nArquivos criados ou já existentes verificados!\n");
                break;
            case 2:
                cadastrar_clientes();
                break;
            case 3:
                cadastrar_recebimentos();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                alterar_cliente();
                break;
            case 6:
                alterar_recebimento();
                break;
            case 7:
                mostrar_recebimentos_periodo();
                break;
            case 8:
                mostrar_recebimentos_cliente();
                break;
            case 9:
                mostrar_recebimentos_acima();
                break;
            case 10:
                mostrar_recebimentos_abaixo();
                break;
            case 11:
                mostrar_recebimentos_entre();
                break;
            case 0:
                printf("\nSaindo...\n\n");
                break;
            default:
                printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);
}

int main()
{
    setlocale(LC_ALL, "");
    criar_arquivo_clientes();
    criar_arquivo_recebimentos();
    menu();

return 0;
}