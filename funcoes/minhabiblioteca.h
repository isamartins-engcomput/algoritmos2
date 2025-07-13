// BIBLIOTECA DE FUNÇÕES DA LISTA DE ALGORITMOS II

// EXERCICIO 1
void printar1 ()
{
  printf ("\n\nOI\n\n");
}

// EXERCICIO 2
void printar2 (char texto2 [100])
{
  printf ("\n%s\n\n",texto2);
}

// EXERCICIO 3
char string[5] = "OK";

char printar3 (char texto3 [100])
{
  printf ("\n%s\n",texto3);
  return printf ("\nOk\n\n");
}

// EXERCICIO 4
void baskara (float a, float b, float c)
{
  float delta, raiz1, raiz2;

  delta = (b * b) - (4 * a * c);

  if (delta < 0)
  {
    printf("\nNão existem raízes reais.\n\n");
  }
  else if (delta == 0)
  {
    raiz1 = -b / (2 * a);
    printf("\nExiste apenas uma raiz real: %.2f\n\n", raiz1);
  }
  else
  {
    raiz1 = (-b + sqrt(delta)) / (2 * a);
    raiz2 = (-b - sqrt(delta)) / (2 * a);
    printf("\nExistem duas raízes reais: %.2f e %.2f\n\n", raiz1, raiz2);
  }
}

// EXERCICIO 5
int temporizar5 (int segundos)
{ 
  int horas, minutos, resto;
  
  horas = segundos / 3600; 
  resto = segundos % 3600;
  minutos = resto / 60;
  segundos = resto % 60;
  
  return printf("\nTempo equivalente: %d horas, %d minutos e %d segundos.\n\n", horas, minutos, segundos);
}

// EXERCICIO 6
int temporizar6 (int dia, int mes, int ano, int dia_atual, int mes_atual, int ano_atual)
{ 
  return ((ano_atual - ano) * 365) + ((mes_atual - mes) * 30) + (dia_atual - dia);
}

// EXERCICIO 7
int verificar7 (int valor)
{
  int soma = 0;

  for (int i = 1; i < valor; i++)
  {
    if (valor % i == 0)
    {
      soma = soma + i;
    }
  }

  if (soma == valor)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// EXERCICIO 8
void categorizar (int idade)
{
  if (idade >= 5 && idade <= 7)
  {
    printf ("\nVocê faz parte da categoria de base INFANTIL A!\n\n");
  }
  else if (idade >= 8 && idade <= 10)
  {
    printf ("\nVocê faz parte da categoria de base INFANTIL B!\n\n");
  }
  else if (idade >= 11 && idade <= 13)
  {
    printf ("\nVocê faz parte da categoria de base JUVENIL A!\n\n");
  }
  else if (idade >= 14 && idade <= 17)
  {
    printf ("\nVocê faz parte da categoria de base JUVENIL B!\n\n");
  }
  else if (idade >= 18)
  {
    printf ("\nVocê faz parte da categoria ADULTO!\n\n");
  }
  else
  {
    printf ("\nVocê não faz parte das categorias de base.\n\n");
  }
}

// EXERCICIO 9
int verificar9 (int valor)
{
  if (valor > 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


// EXERCICIO 10
int verificar10 (int valor)
{
  if (valor % 2 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// EXERCICIO 11
void conceituar (int media)
{
  if (media >= 0 && media < 5)
  {
    printf ("\nSua nota é CONCEITO D!\n\n");
  }
  else if (media >= 5 && media < 7)
  {
    printf ("\nSua nota é CONCEITO C!\n\n");
  }
  else if (media >= 7 && media < 9)
  {
    printf ("\nSua nota é CONCEITO B!\n\n");
  }
  else
  {
    printf ("\nSua nota é CONCEITO A!\n\n");
  }
}

// EXERCICIO 12
void ordenar (int a, int b, int c)
{
  int troca;

  if (a > b)
  {
    troca = a;
    a = b;
    b = troca;
  }
  if (a > c)
  {
    troca = a;
    a = c;
    c = troca;
  }
  if (b > c)
  {
    troca = b;
    b = c;
    c = troca;
  }

  printf ("\nValores em ordem crescente: %d %d %d\n\n",a,b,c);
}

// EXERCICIO 13
void verificar13 (int lado1, int lado2, int lado3)
{
  if ((((abs (lado2 - lado3) < lado1) && (lado2 + lado3 > lado1)) && ((abs (lado1 - lado3) < lado2) && (lado1 + lado3 > lado2))) && (((abs (lado1 - lado2) < lado3) && (lado1 + lado2 > lado3))))
  {
    if ((lado1 == lado2) && (lado1 == lado3))
    {
    printf ("\nEste triângulo é EQUILÁTERO!\n\n");
    }
    if ((((lado1 == lado2) && (lado1 != lado3)) || (((lado2 != lado1) && (lado2 == lado3))) || ((lado3 == lado1) && (lado3 != lado2))))
    {
    printf ("\nEste triângulo é ISÓSCELES!\n\n");
    }
    if (((lado1 != lado2) && (lado1 != lado3)) && ((lado2 != lado3)))
    {
    printf ("\nEste triângulo é ESCALENO!\n\n");
    }
  }
  else
  {
  printf ("\nERRO! Os valores inseridos não satisfazem a condição de existência de um triângulo.\n\n");
  }
}

// EXERCICIO 14
float calcular_media (int valor)
{
  int soma = 0, quantidade = 0;

  printf("\nDigite valores positivos (negativo para sair):");

  do
  {
    scanf("%d",&valor);

    if (valor >= 0)
    {
      soma = soma + valor;
      quantidade++;
    }

  } while (valor >= 0);

  return soma / quantidade;
}

// EXERCICIO 15
int elevar (int base, int expoente)
{ 
  int resultado = 1;

  for (int i = 0; i < expoente; i++)
  {
    resultado = resultado * base;
  }
  return resultado;
}