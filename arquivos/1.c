/*1 - Faça um programa para criar os arquivos a seguir:
Clientes: Cod_Cli, Nome, Endereco, Fone;
Recebimentos: Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli.*/

#include <stdio.h>

int main ()
{
  FILE *clientes;
  FILE *recebimentos;

  int escolha_usuario;

  printf("\nQual arquivo voce deseja criar? (Digite 1 para cadastro dos clientes e 2 para recebimentos): ");
  scanf("%d",&escolha_usuario);

  if (escolha_usuario < 1 || escolha_usuario > 2)
  {
    printf("\nPor favor digite uma opcao valida!\n\n");
    return 1;
  }

  switch (escolha_usuario)
  {
    case 1:
    {
      int num_clientes = 0;
      int i = 0;

      clientes = fopen("clientes.csv","a+");

      if (clientes == NULL)
      {  
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
      }

      printf("\nQuantos clientes voce deseja cadastrar? ");
      scanf("%d",&num_clientes);

      fprintf(clientes,"\nCod_Cli,Nome,Endereco,Fone\n");

      while (i < num_clientes)
      {
        int Cod_Cli = 0;
        long int Fone = 0;
        char Nome[50], Endereco[100];

        printf("\nDigite o cadastro do cliente no formato: Codigo_Cliente Nome Endereco Fone\n");
        printf("*Separe os nomes e o endereco com underline (_)\n\n");
        scanf("%d %s %s %ld",&Cod_Cli,Nome,Endereco,&Fone);
        fprintf(clientes,"\n%d %s %s %ld",Cod_Cli,Nome,Endereco,Fone);
        i++;
      }
  
      printf("\n");

      fclose(clientes); 
      break;
    }

    case 2:
    {
      int num_recebimentos = 0;
      int i = 0;

      recebimentos = fopen("recebimentos.csv","a+");

      if (recebimentos == NULL)
      {  
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
      }

      printf("\nQuantos recebimentos voce deseja cadastrar? ");
      scanf("%d",&num_recebimentos);

      fprintf(recebimentos,"\nNum_doc,Valor_doc,Data_Emissao,Data_Vencimento,Cod_Cli\n");

      while (i < num_recebimentos)
      {
        int Num_doc = 0,Valor_doc = 0,Data_Emissao = 0,Data_Vencimento = 0,Cod_Cli = 0;

        printf("\nDigite o dados do recebimento no formato: Numero_Documento Valor_Documento Data_Emissao Data_Vencimento Cod_Cliente\n\n");
        printf("*Separe as datas com underline (_)\n\n");
        scanf("%d %d %d %d %d",&Num_doc,&Valor_doc,&Data_Emissao,&Data_Vencimento,&Cod_Cli);
        fprintf(recebimentos,"\n%d %d %d %d %d",Num_doc,Valor_doc,Data_Emissao,Data_Vencimento,Cod_Cli);
        i++;
      }

      printf("\n");

      fclose(recebimentos);
      break;
    }
  }

return 0;
}