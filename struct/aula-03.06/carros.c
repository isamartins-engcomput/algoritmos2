/* struct array[5] - carro
estrutura:
- marca
- modelo
- ano
- cor */

#include <stdio.h>
#include <string.h>

struct Carro
{
    char marca[100];
    char modelo[100];
    int ano;
    char cor[100];
};

int main()
{
    struct Carro carros[2];

    for (int i = 0; i < 2; i++)
    {
        printf("\nCarro %d:\n",i + 1);

        printf("Marca: ");
        scanf("%s",carros[i].marca);

        printf("Modelo: ");
        scanf("%s",carros[i].modelo);

        printf("Ano: ");
        scanf("%d",&carros[i].ano);

        printf("Cor: ");
        scanf("%s",carros[i].cor);
    }

    printf("\nLista de Carros:\n\n");
    
    for (int i = 0; i < 2; i++)
    {
        printf("Carro %d: %s %s, Ano: %d, Cor: %s\n", i + 1,
        carros[i].marca,carros[i].modelo,carros[i].ano,carros[i].cor);
    }
    printf("\n");

return 0;
}