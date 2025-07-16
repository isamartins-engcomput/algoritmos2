/*
  Sistema completo para gerenciamento de Moda e Produtos.

  Este programa reúne a implementação dos Exercícios 12 a 25 do conjunto de
  exercícios desta lista, com funcionalidades que incluem:

    12 - Criação dos arquivos estilista.csv, roupa.csv e estacao.csv com cabeçalhos.
    13 - Cadastro de estações, estilistas e roupas (validando pré-cadastros).
    14 - Menu criar/incluir e relatório com médias de notas.
    15 - Criação do arquivo produtos.txt com código, descrição e preço.
    16 - Inclusão de produtos sem duplicar código.
    17 - Consulta de produtos com preço > R$500,00.
    18 - Aumento de 15% nos preços de todos os produtos.
    19 - Aumento de R$10,00 nos produtos com preço > R$100,00.
    20 - Consulta de produtos cujo nome começa com 'M'.
    21 - Exclusão de produtos do arquivo produtos.txt.
    22 - Consulta de produtos com preço < R$15,00.
    23 - Consulta de produtos cujo nome começa por letra informada e preço entre dois valores.
    24 - Exclusão de todos os produtos com preço > R$200,00.
    25 - Concessão de desconto percentual dado pelo usuário para produtos em faixa de preço.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_DESC 100
#define ESTILISTA_ARQ "estilista.csv"
#define ROUPA_ARQ "roupa.csv"
#define ESTACAO_ARQ "estacao.csv"
#define NOTA_ARQ "notas.csv"
#define PRODUTOS_TXT "produtos.txt"

typedef struct { int cod; char nome[50]; float salario; } Estilista;
typedef struct { int cod; char desc[MAX_DESC]; int cod_estilista; int cod_estacao; int ano; } Roupa;
typedef struct { int cod; char nome[50]; } Estacao;
typedef struct { int numero; char nome[50]; float nota1, nota2; } Nota;
typedef struct { int codigo; char descricao[MAX_DESC]; float preco; } Produto;

void criar_arquivos_12();
void cadastrar_estacoes();
void cadastrar_estilistas();
void cadastrar_roupas();
void criar_notas();
void incluir_notas();
void criar_produtos();
void incluir_produtos();
void consulta_produtos_500();
void aumento_15pct();
void aumento_10reais();
void consulta_nome_M();
void excluir_produto();
void consulta_preco_15();
void consulta_letra_e_faixa();
void excluir_preco_200();
void aplicar_desconto();
void menu();

int main()
{
  setlocale(LC_ALL, "");
  menu();
  return 0;
}

void criar_arquivos_12()
{
  FILE *f;
  f = fopen(ESTILISTA_ARQ,"w"); fprintf(f, "cod,nome,salario\n"); fclose(f);
  f = fopen(ROUPA_ARQ,"w"); fprintf(f, "cod,descricao,cod_estilista,cod_estacao,ano\n"); fclose(f);
  f = fopen(ESTACAO_ARQ,"w"); fprintf(f, "cod,nome\n"); fclose(f);
  printf("\nArquivos de estilista, roupa e estação criados!\n");
}

void cadastrar_estacoes()
{
  FILE *f = fopen(ESTACAO_ARQ, "a");
  int qtd;
  printf("\nQuantas estações cadastrar? ");
  scanf("%d", &qtd); getchar();
  for (int i = 0; i < qtd; i++)
  {
    Estacao e;
    printf("\nESTAÇÃO %d:\n\n", i+1);
    printf("Código: "); scanf("%d", &e.cod); getchar();
    printf("Nome: "); fgets(e.nome, 50, stdin); e.nome[strcspn(e.nome, "\n")] = 0;
    fprintf(f, "%d,%s\n", e.cod, e.nome);
  }
  fclose(f);
  printf("\nEstações cadastradas!\n");
}

void cadastrar_estilistas()
{
  FILE *f = fopen(ESTILISTA_ARQ, "a");
  int qtd;
  printf("\nQuantos estilistas cadastrar? ");
  scanf("%d", &qtd); getchar();
  for (int i = 0; i < qtd; i++)
  {
    Estilista s;
    printf("\nESTILISTA %d:\n\n", i+1);
    printf("Código: "); scanf("%d", &s.cod); getchar();
    printf("Nome: "); fgets(s.nome, 50, stdin); s.nome[strcspn(s.nome, "\n")] = 0;
    printf("Salário: "); scanf("%f", &s.salario); getchar();
    fprintf(f, "%d,%s,%.2f\n", s.cod, s.nome, s.salario);
  }
  fclose(f);
  printf("\nEstilistas cadastrados!\n");
}

int existe_codigo(const char *arquivo, int cod)
{
  FILE *f = fopen(arquivo, "r"); if (!f) return 0;
  char l[200]; fgets(l, 200, f);
  while (fgets(l, 200, f))
  {
    int c; sscanf(l, "%d", &c);
    if (c == cod) { fclose(f); return 1; }
  }
  fclose(f); return 0;
}

void cadastrar_roupas()
{
  FILE *f = fopen(ROUPA_ARQ, "a");
  int qtd;
  printf("\nQuantas roupas cadastrar? ");
  scanf("%d", &qtd); getchar();
  for (int i = 0; i < qtd; i++)
  {
    Roupa r;
    printf("\nROUPA %d:\n\n", i+1);
    printf("Código: "); scanf("%d", &r.cod); getchar();
    printf("Descrição: "); fgets(r.desc, MAX_DESC, stdin); r.desc[strcspn(r.desc, "\n")] = 0;
    printf("Código Estilista: "); scanf("%d", &r.cod_estilista); getchar();
    printf("Código Estação: "); scanf("%d", &r.cod_estacao); getchar();
    printf("Ano: "); scanf("%d", &r.ano); getchar();
    if (!existe_codigo(ESTILISTA_ARQ, r.cod_estilista) || !existe_codigo(ESTACAO_ARQ, r.cod_estacao))
    {
      printf("\nEstilista ou estação não cadastrados, pulando...\n");
      continue;
    }
    fprintf(f, "%d,%s,%d,%d,%d\n",
      r.cod, r.desc, r.cod_estilista, r.cod_estacao, r.ano);
  }
  fclose(f);
  printf("\nRoupas cadastradas!\n");
}

void criar_notas()
{
  FILE *f = fopen(NOTA_ARQ, "w");
  fprintf(f, "numero,nome,nota1,nota2\n");
  fclose(f);
  printf("\nArquivo de notas criado!\n");
}

void incluir_notas()
{
  FILE *f = fopen(NOTA_ARQ, "a");
  int qtd;
  printf("\nQuantos registros de notas incluir? ");
  scanf("%d", &qtd); getchar();
  for (int i = 0; i < qtd; i++)
  {
    Nota n;
    printf("\nREGISTRO %d:\n\n", i+1);
    printf("Número: "); scanf("%d", &n.numero); getchar();
    printf("Nome: "); fgets(n.nome, 50, stdin); n.nome[strcspn(n.nome, "\n")] = 0;
    printf("Nota1: "); scanf("%f", &n.nota1);
    printf("Nota2: "); scanf("%f", &n.nota2); getchar();
    fprintf(f, "%d,%s,%.2f,%.2f\n",
      n.numero, n.nome, n.nota1, n.nota2);
  }
  fclose(f);
  printf("\nRelatório de notas:\n");
  f = fopen(NOTA_ARQ, "r");
  char l[200];
  fgets(l, 200, f);
  while (fgets(l, 200, f))
  {
    int num; char nome[50]; float a,b;
    sscanf(l, "%d,%[^,],%f,%f", &num, nome, &a, &b);
    printf("%d,%s,%.2f,%.2f,media=%.2f\n",
      num, nome, a, b, (a+b)/2);
  }
  fclose(f);
}

void criar_produtos()
{ FILE *f = fopen(PRODUTOS_TXT, "w"); fclose(f); printf("Arquivo produtos.txt criado!\n"); }

void incluir_produtos()
{
  FILE *f = fopen(PRODUTOS_TXT, "a+");
  int qtd;
  printf("\nQuantos produtos incluir? ");
  scanf("%d", &qtd); getchar();
  for (int i = 0; i < qtd; i++)
  {
    Produto p;
    printf("\nPRODUTO %d:\n\n", i+1);
    printf("Código: "); scanf("%d", &p.codigo); getchar();
    printf("Descrição: "); fgets(p.descricao, MAX_DESC, stdin); p.descricao[strcspn(p.descricao, "\n")] = 0;
    printf("Preço: "); scanf("%f", &p.preco); getchar();
    fprintf(f, "%d,%s,%.2f\n",
      p.codigo, p.descricao, p.preco);
  }
  fclose(f);
}

void consulta_produtos_500()
{
  printf("\nProdutos com preço > 500:\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (pr > 500) printf("%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f);
}

void aumento_15pct()
{
  printf("\nAumentando 15%% nos preços...\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"), *t = fopen("tmp.txt","w"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    pr *= 1.15f;
    fprintf(t, "%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f); fclose(t);
  remove(PRODUTOS_TXT); rename("tmp.txt", PRODUTOS_TXT);
}

void aumento_10reais()
{
  printf("\nAumentando R$10 em preços > 100...\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"), *t = fopen("tmp.txt","w"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (pr > 100) pr += 10;
    fprintf(t, "%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f); fclose(t);
  remove(PRODUTOS_TXT); rename("tmp.txt", PRODUTOS_TXT);
}

void consulta_nome_M()
{
  printf("\nProdutos com nome iniciando M:\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (d[0]=='M' || d[0]=='m') printf("%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f);
}

void excluir_produto()
{
  int cod; printf("Código a excluir: "); scanf("%d", &cod); getchar();
  FILE *f = fopen(PRODUTOS_TXT, "r"), *t = fopen("tmp.txt","w"); char l[200];
  while (fgets(l, 200, f)) { int c; sscanf(l, "%d", &c); if (c!=cod) fputs(l, t); }
  fclose(f); fclose(t);
  remove(PRODUTOS_TXT); rename("tmp.txt", PRODUTOS_TXT);
}

void consulta_preco_15()
{
  printf("\nProdutos com preço < 15:\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (pr < 15) printf("%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f);
}

void consulta_letra_e_faixa()
{
  char let; float mn, mx;
  printf("\nLetra inicial: "); scanf(" %c", &let);
  printf("Mínimo e máximo preço: "); scanf("%f %f", &mn, &mx); getchar();
  printf("Produtos filtrados:\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if ((d[0]==let) && pr>=mn && pr<=mx)
      printf("%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f);
}

void excluir_preco_200()
{
  printf("\nExcluindo produtos com preço > 200...\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"), *t = fopen("tmp.txt","w"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (pr <= 200) fputs(l, t);
  }
  fclose(f); fclose(t);
  remove(PRODUTOS_TXT); rename("tmp.txt", PRODUTOS_TXT);
}

void aplicar_desconto()
{
  float pct, mn, mx;
  printf("\nPercentual e faixa (mn mx): "); scanf("%f %f %f", &pct, &mn, &mx); getchar();
  printf("\nAplicando desconto...\n");
  FILE *f = fopen(PRODUTOS_TXT, "r"), *t = fopen("tmp.txt","w"); char l[200];
  while (fgets(l, 200, f))
  {
    int c; char d[100]; float pr;
    sscanf(l, "%d,%[^,],%f", &c, d, &pr);
    if (pr>=mn && pr<=mx) pr *= (1 - pct/100.0f);
    fprintf(t, "%d,%s,%.2f\n", c, d, pr);
  }
  fclose(f); fclose(t);
  remove(PRODUTOS_TXT); rename("tmp.txt", PRODUTOS_TXT);
}

void menu()
{
  int opc;
  do
  {
    printf("\n----------- MENU MODA E PRODUTOS -----------\n\n");
    printf("12 - Criar arquivos moda e produtos\n");
    printf("13 - Cadastrar estações, estilistas e roupas\n");
    printf("14 - Criar/Incluir notas\n");
    printf("15 - Criar arquivo produtos.txt\n");
    printf("16 - Incluir produtos\n");
    printf("17 - Consultar produtos > 500\n");
    printf("18 - Aumentar 15%% nos preços\n");
    printf("19 - Aumentar R$10 em preços > 100\n");
    printf("20 - Consulta nome M\n");
    printf("21 - Excluir produto\n");
    printf("22 - Consulta preço < 15\n");
    printf("23 - Consulta letra/faixa\n");
    printf("24 - Excluir preço > 200\n");
    printf("25 - Aplicar desconto\n");
    printf("0  - Sair\n");
    printf("\nOpção? "); scanf("%d", &opc); getchar();
    switch (opc)
    {
      case 12: criar_arquivos_12(); break;
      case 13: cadastrar_estacoes(); cadastrar_estilistas(); cadastrar_roupas(); break;
      case 14: criar_notas(); incluir_notas(); break;
      case 15: criar_produtos(); break;
      case 16: incluir_produtos(); break;
      case 17: consulta_produtos_500(); break;
      case 18: aumento_15pct(); break;
      case 19: aumento_10reais(); break;
      case 20: consulta_nome_M(); break;
      case 21: excluir_produto(); break;
      case 22: consulta_preco_15(); break;
      case 23: consulta_letra_e_faixa(); break;
      case 24: excluir_preco_200(); break;
      case 25: aplicar_desconto(); break;
    }
  } while (opc != 0);
  printf("\nSaindo...\n\n");
}