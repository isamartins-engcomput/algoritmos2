/* Algoritmo: Conversor de Texto para Código Morse
Entrada: Uma string de texto lida como uma sequência de caracteres, os quais devem ser inseridos individualmente.
Saída: A representação em código Morse da string de texto

Funcionamento:
1. Leia a string de texto do usuário.
2. Para cada caractere da string:
- Use um switch case para determinar a representação em código Morse do caractere.
- Adicione a representação em código Morse do caractere à saída.
3. Imprima a saída.

Obs.: para indicar o final da sequência de caracteres deve-se usar um caractere '*'.
Exemplo: Entrada: "HELLO*" Saída: ".... . .-.. .-.. ---"

Tabela de Conversão:
Caractere=Código Morse
A=.- | B=-... | C=-.-. | D=-.. | E=. | F=..-. | G=--. | H=.... | I=.. | J=.--- | K=-.- | L=.-.. | M=-- |
N=-. | O=--- | P=.--. | Q=--.- | R=.-. | S=... | T=- | U=..- | V=...- | W=.-- | X=-..- | Y=-.-- | Z=--.. | */

#include <stdio.h>

int main()
{
    char caractere;
    char entrada[500];
    int i = 0;

    printf("/// CONVERSOR DE TEXTO PARA CÓDIGO MORSE ///");
    printf("Digite os caracteres um por vez (use * para finalizar): ");

    while (1)
    {
        scanf(" %c",&caractere);

        if (caractere == '*') break;       

        entrada[i] = caractere;
        i++;
    }

    printf("\nSaída em código Morse:\n");

    for (int j = 0; j < i; j++)
    {
        switch (entrada[j])
        {
            case 'A': printf(".- "); break;
            case 'B': printf("-... "); break;
            case 'C': printf("-.-. "); break;
            case 'D': printf("-.. "); break;
            case 'E': printf(". "); break;
            case 'F': printf("..-. "); break;
            case 'G': printf("--. "); break;
            case 'H': printf(".... "); break;
            case 'I': printf(".. "); break;
            case 'J': printf(".--- "); break;
            case 'K': printf("-.- "); break;
            case 'L': printf(".-.. "); break;
            case 'M': printf("-- "); break;
            case 'N': printf("-. "); break;
            case 'O': printf("--- "); break;
            case 'P': printf(".--. "); break;
            case 'Q': printf("--.- "); break;
            case 'R': printf(".-. "); break;
            case 'S': printf("... "); break;
            case 'T': printf("- "); break;
            case 'U': printf("..- "); break;
            case 'V': printf("...- "); break;
            case 'W': printf(".-- "); break;
            case 'X': printf("-..- "); break;
            case 'Y': printf("-.-- "); break;
            case 'Z': printf("--.. "); break;
            default: break;
        }
    }

    printf("\n");
return 0;
}