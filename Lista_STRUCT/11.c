/* 11)  Escreva  um  programa  que  contenha  uma  estrutura  representando  uma  data
válida. Essa  estrutura  deve  conter  os  campos  dia,  mês  e  ano.  Em  seguida,  leia
duas  datas  e armazene nessa estrutura. Calcule e exiba o número de dias que decorreram
entre as duas datas. */

#include <stdio.h>
#include <locale.h>
#include <time.h>

struct Data
{
  int dia;
  int mes;
  int ano;
};

int ano_bissexto (int ano)
{
  return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

int data_valida (struct Data x)
{
  if (x.ano < 1 || x.mes < 1 || x.mes > 12 || x.dia < 1)
    return 0;

  int dias_no_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (x.mes == 2 && ano_bissexto(x.ano))
    dias_no_mes[1] = 29;

  return x.dia <= dias_no_mes[x.mes - 1];
}

struct tm converter_para_tm(struct Data x)
{
  struct tm data_tm = {0};

  data_tm.tm_mday = x.dia;
  data_tm.tm_mon  = x.mes - 1;
  data_tm.tm_year = x.ano - 1900;

  return data_tm;
}

int main()
{
  setlocale(LC_ALL,"");

  struct Data data1, data2;

  printf("\nDigite a primeira data (DD MM AAAA): ");
  scanf("%d %d %d",&data1.dia,&data1.mes,&data1.ano);
  while (!data_valida(data1))
  {
    printf("Data inválida! Digite novamente (DD MM AAAA): ");
    scanf("%d %d %d",&data1.dia,&data1.mes,&data1.ano);
  }

  printf("Digite a segunda data (DD MM AAAA): ");
  scanf("%d %d %d",&data2.dia,&data2.mes,&data2.ano);
  while (!data_valida(data2))
  {
    printf("Data inválida! Digite novamente (DD MM AAAA): ");
    scanf("%d %d %d",&data2.dia,&data2.mes,&data2.ano);
  }

  struct tm tm1 = converter_para_tm(data1);
  struct tm tm2 = converter_para_tm(data2);

  time_t t1 = mktime(&tm1);
  time_t t2 = mktime(&tm2);

  double diferenca = difftime(t2, t1) / (60 * 60 * 24);

  if (diferenca < 0)
  {
    diferenca *= -1;
  }

  printf("\nDiferença de dias entre as duas datas: %.0f dias\n\n",diferenca);

return 0;
}