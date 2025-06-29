/* O processo de normalização de matrizes possui aplicação em várias áreas. Uma delas é no
processamento de imagens digitais, onde a normalização permite remapear os valores de intensidade
dos pixels de imagem do tipo inteiro (0 a 255) para o tipo real, reduzindo a faixa de variação dos
valores ao intervalo fechado entre zero e um. O valor original zero deve ser remapeado para zero na
saída. O valor original 255 deve ser remapeado para um, e os demais valores originais devem estar
entre zero e um.

Diante disso, escreva um algoritmo que leia uma matriz de inteiros com 8 linhas e 8 colunas.
Esta matriz deve ser fixa no código, preenchida com valores entre 0 e 255. Os valores devem ser
inseridos na matriz em ordem crescente, e o intervalo entre os valores deve ser 4.
Exemplo: m[0][0] = 0; m[0][1] = 4; m[0][2] = 8; e etc.

O algoritmo deve normalizar os valores da matriz para o intervalo fechado entre zero e um, do tipo
real. Como saída deve ser exibido em uma única linha do terminal. Para exibir o resultado deve-se
percorrer a matriz iniciando no canto superior esquerdo, lendo linha a linha sequencialmente. Os
valores de saída devem ser exibidos com duas casas decimais (%.2f). Os valores da saída devem ser
separados por um espaço em branco. */

#include <stdio.h>

#define LINHAS 8
#define COLUNAS 8

int main()
{
    float matriz[LINHAS][COLUNAS];
    int soma = 0;
    float vetor[LINHAS*COLUNAS];
    int k = 0;

    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++)
        {
            matriz[i][j] = soma;
            soma = soma + 4;
        }
    }

    for(int i = 0; i < LINHAS; i++)
    {
        for(int j = 0; j < COLUNAS; j++)
        {
            vetor[k] = (matriz[i][j] / 255);
            printf("%.2f",vetor[k]);
            k++;

            if(i < 7 || j < 7)
            {
                printf(" ");
            }
        }
    }

return 0; 
}