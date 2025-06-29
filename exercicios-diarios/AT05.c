/* Simulador de Caixa de Supermercado

Problema: Implemente um programa em linguagem C que simule o atendimento de vários clientes em um caixa de supermercado.

O programa deve funcionar da seguinte forma:
1. A primeira entrada é um número inteiro `quantidade_clientes`, representando quantos clientes serão atendidos.
2. Para cada um dos `quantidade_clientes`:
- Ler um número inteiro `quantidade_produtos`, representando quantos produtos o cliente irá comprar.
- Em seguida, ler `quantidade_produtos` valores reais, representando o `preco_produto` de cada item.
- Calcular o `total_compra`.
- Ler um valor real `valor_pago`, representando o valor que o cliente pagou.
- Se `valor_pago` for menor que `total_compra`, o programa deve continuar solicitando novo valor até que ele seja suficiente.

Ao final, imprimir duas informações:
- O `total_compra`, com duas casas decimais.
- O `troco` (diferença entre `valor_pago` e `total_compra`), também com duas casas decimais.

Observações importantes:
- Não devem ser exibidas mensagens na tela solicitando entradas.
- Apenas as informações finais devem ser impressas, em uma única linha, e cada valor separado por um espaço em branco: Ex.: total_da_compra troco. */

#include <stdio.h>

int main()
{
  int quantidade_clientes = 0;
  int quantidade_produtos = 0;

  scanf("%d",&quantidade_clientes);

  for(int i = 0; i < quantidade_clientes; i++)
  {
    float valor_pago = 0;
    float total_compra = 0;
    float preco_produto = 0;
    float troco = 0;

    scanf("%d",&quantidade_produtos);

    for(int j = 0; j < quantidade_produtos; j++)
    {
      scanf("%f",&preco_produto);
      total_compra = total_compra + preco_produto;
    }

    scanf("%f",&valor_pago);

    if(valor_pago < total_compra)
    {
      while(valor_pago < total_compra)
      {
        scanf("%f",&valor_pago);
        if(valor_pago >= total_compra)
        {
          troco = valor_pago - total_compra;
          printf("%.2f %.2f ",total_compra,troco);
          break;
        }
      }
    }
    else
    {
      troco = valor_pago - total_compra;
      printf("%.2f %.2f ",total_compra,troco);
    }
  }

return 0;
}