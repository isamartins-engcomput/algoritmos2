#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "minhabiblioteca.h"

int main ()
{
  setlocale(LC_ALL, "");

  int exercicio;

  printf ("\n////////// MENU DOS CÓDIGOS DA LISTA DE FUNÇÕES - ALGORITMOS II //////////");
  printf ("\n///// Estudante: Isadora Martins - 2° semestre - Eng. de Computação /////\n\n");

  do
  {
    printf ("Digite o número do exercício da lista ao qual você deseja executar (ou zero para sair): ");
    scanf ("%d",&exercicio);

    switch (exercicio)
    {
      case 1:
      {
        printf ("\n1 - Faça uma função que não receba parâmetros e escreva na tela (print) o texto “OI”.");
      
        printar1(); 

        break;
      }
      case 2:
      {
        printf ("\n2 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print).");
      
        char texto2 [100];

        printf ("\n\nDigite alguma coisa qualquer: ");
        scanf ("%s",texto2);
  
        printar2(texto2);

        break;
      }
      case 3:
      {
        printf ("\n3 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print), em seguida retorne “Ok”.");
      
        char texto3 [100];

        printf ("\n\nDigite alguma coisa qualquer: ");
        scanf ("%s",texto3);
  
        printar3(texto3);

        break;
      }
      case 4:
      {
        printf ("\n4 - Faça um procedimento que recebe por parâmetro os valores necessário para o cálculo da fórmula de báskara e imprima as suas raízes, caso seja possível calcular.\n");

        float a, b, c;

        printf ("\n///// CALCULO DA FORMULA DE BÁSKARA /////\n");
        printf("\nDigite os coeficientes a, b e c respectivamente: ");
        scanf("%f %f %f", &a, &b, &c);
      
        baskara(a, b, c);

        break;
      }
      case 5:
      {
        printf ("\n5 - Faça um procedimento que recebe por parâmetro o tempo de duração de uma fábrica expressa em segundos e imprima esse tempo em horas, minutos e segundos.");

        int segundos5;

        printf ("\n\nDigite o tempo de duração da fábrica em segundos: ");
        scanf ("%d",&segundos5);
  
        temporizar5(segundos5);

        break;
      }
      case 6:
      {
        printf ("\n6 - Faça uma função que recebe a idade de uma pessoa em anos, meses e dias e retorna essa idade expressa em dias.");

        int dia_atual, mes_atual, ano_atual;
        int dia, mes, ano;

        printf ("\n\nEm qual dia você nasceu? ");
        scanf ("%d",&dia);
        printf ("De qual mês? ");
        scanf ("%d",&mes);
        printf ("Em que ano? ");
        scanf ("%d",&ano);
  
        printf ("\nAgora me diga: Em qual dia estamos? ");
        scanf ("%d",&dia_atual);
        printf ("De qual mês? ");
        scanf ("%d",&mes_atual);
        printf ("E qual ano? ");
        scanf ("%d",&ano_atual);
        
        int total_dias = temporizar6(dia,mes,ano,dia_atual,mes_atual,ano_atual);
        
        printf("\nDesde %d/%d/%d ate %d/%d/%d já se passaram %d dias que foram vividos por você.\nEntão... Aproveite a vida! :)\n\n",dia,mes,ano,dia_atual,mes_atual,ano_atual,total_dias);

        break;
      }
      case 7:
      {
        printf ("\n7 - Faça uma função que verifique se um valor é perfeito ou não. Um valor é dito perfeito quando ele é igual a soma dos seus divisores exceto ele próprio. (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função deve retornar o valor inteiro 1 para verdadeiro e 0 caso contrário.");

        int valor;

        printf ("\n\nDigite um valor qualquer: ");
        scanf ("%d",&valor);

        if (verificar7 (valor))
        {
          printf("\n%d É UM número perfeito!\n\n",valor);
        }
        else
        {
          printf("\n%d NÃO É um número perfeito.\n\n",valor);
        }

        break;
      }
      case 8:
      {
        printf ("\n8 - Faça um procedimento que recebe a idade de um nadador por parâmetro e retorna, também por parâmetro, a categoria desse nadador de acordo com a tabela.");

        int idade;
  
        printf ("\n\nQual sua idade? ");
        scanf ("%d",&idade);
  
        categorizar(idade);

        break;
      }
      case 9:
      {
        int valor;
  
        printf ("\n9 - Faça uma função que recebe um valor inteiro e verifica se o valor e positivo ou negativo. A funcao deve retornar um valor inteiro.\n"); 
        printf ("\nFunção para verificar valores: se retorno = 1 -> positivo, se retorno = 0 -> negativo\n"); 
        
        printf ("\nDigite um valor qualquer: ");;
        scanf ("%d",&valor );
        
        int retorno = verificar9(valor);
        printf ("\nRetorno = %d\n\n",retorno);

        break;
      }
      case 10:
      {
        int valor;
  
        printf ("\n10 - Faça uma função que recebe um valor inteiro e verifica se o valor é par ou ímpar. A função deve retornar um valor inteiro.\n"); 
        printf ("\nFunção para verificar valores: se retorno = 1 -> par, se retorno = 0 -> ímpar\n"); 
        
        printf ("\nDigite um valor qualquer: ");;
        scanf ("%d",&valor );
        
        int retorno = verificar10(valor);
        printf ("\nRetorno = %d\n\n",retorno);

        break;
      }
      case 11:
      {
        printf ("\n11 - Faça uma função que recebe a média final de um aluno por parâmetro e retorna o seu conceito conforme a tabela.\n"); 
        
        float media;
  
        printf ("\nQual sua média final? ");
        scanf ("%f",&media);
        
        conceituar(media);

        break;
      }
      case 12:
      {  
        printf ("\n12 - Faça um procedimento que recebe 3 valores inteiros por parâmetro e imprima-os ordenados em ordem crescente.\n"); 
        
        int a, b, c;
  
        printf ("\nDigite um valor a: ");
        scanf ("%d",&a);
        printf ("Digite um valor b: ");
        scanf ("%d",&b);
        printf ("Digite um valor c: ");
        scanf ("%d",&c);
        
        ordenar(a,b,c);

        break;
      }
      case 13:
      {  
        printf ("\n13 - Escreva um procedimento que recebes 3 valores reais X, Y e Z e que verifique se esses valores podem ser os comprimentos dos lados de um triângulo e, neste caso, retornar qual o tipo de triângulo formado. Para que X, Y e Z formem um triângulo é necessário que a seguinte propriedade seja satisfeita: o comprimento de cada lado de um triângulo é menor do que a soma do comprimento dos outros dois lados. O procedimento deve identificar o tipo de triângulo formado lembrando das definições.\n"); 
        
        int lado1, lado2, lado3;

        printf ("\n///// VERIFICAÇÃO TRIÂNGULOS /////\n");
        printf ("\nInsira um valor para o lado 1 deste triângulo: ");
        scanf ("%d",&lado1);
        printf ("Insira um valor para o lado 2 deste triângulo: ");
        scanf ("%d",&lado2);
        printf ("Insira um valor para o lado 3 deste triângulo: ");
        scanf ("%d",&lado3);
      
        verificar13(lado1,lado2,lado3);

        break;
      }
      case 14:
      {  
        printf ("\n14 - Faça uma função que leia um número não determinado de valores positivos e retorna a média aritmética dos mesmos.\n"); 
        
        int valor;

        printf ("\n///// MÉDIA ARITMÉTICA /////\n");
        float media = calcular_media(valor);
        printf("\nMédia dos valores digitados: %.2f\n\n",media);

        break;
      }
      case 15:
      {  
        printf ("\n15 - Escreva uma função que recebe, por parâmetro, dois valores X e Z e calcula e retorna Xz. (sem utilizar funções ou operadores de potência prontos).\n"); 
        
        int x, y;
        int resultado =1;

        printf ("\n///// CÁLCULO DE POTÊNCIA /////\n");
        printf ("\nDigite um valor x: ");
        scanf ("%d",&x);
        printf ("Digite um valor y: ");
        scanf ("%d",&y);
      
        resultado = elevar (x,y);
        printf ("\nResultado de %d elevado a %d = %d\n\n",x,y,resultado);

        break;
      }
      default:
      {
        printf("\nNúmero inválido!!! Digite apenas números de 1 a 15.\n\n");
      }
    }
  } while (exercicio != 0);

return 0;
}