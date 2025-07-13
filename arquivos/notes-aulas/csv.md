# 📚 .csv

O nome significa **Comma-Separated Values** (em português: "Valores Separados por Vírgula").

> É um ***arquivo de texto*** que guarda dados em **formato de tabela**, onde **cada linha** é um registro (uma linha da tabela) e **cada valor** dentro da linha é separado **por vírgula**.

Exemplo:

`Nome,Idade,Cidade`

`Ana,20,São Paulo`
`João,25,Rio de Janeiro`
`Maria,30,Belo Horizonte`

- Primeira linha (`Nome,Idade,Cidade`) → é o **cabeçalho** (opcional, mas comum), que diz o que cada coluna representa.
- Depois vem os **dados**.
- Cada dado é separado por uma **vírgula**.

Então o `.csv` é uma forma **simples e leve** de armazenar dados organizados como se fossem **linhas e colunas** de uma planilha!

&nbsp;

# Características importantes

| Característica                            | Explicação                                                                                     |
| ------------------------------------------ | ------------------------------------------------------------------------------------------------ |
| É**texto puro**                     | Você pode abrir com qualquer editor de texto (Bloco de Notas, VS Code, etc.).                   |
| Serve para**organizar dados**        | Como uma tabela, fácil de importar/exportar para bancos de dados e Excel.                       |
| Separador principal é a**vírgula** | Mas às vezes usam ponto e vírgula (`;`) em países que usam vírgula como separador decimal. |
| Fácil de ler em programas                 | Porque é só separar as palavras onde tem vírgula.                                             |
| Muito usado em programação               | Para salvar listas de produtos, cadastros, tabelas, etc.                                         |

&nbsp;

# Exemplo visual

Tabela normal:

|  Nome  | Nota |
| :-----: | :--: |
| Carlos | 9.5 |
| Beatriz | 8.0 |
| Marcos | 7.5 |

Arquivo .csv:

`Nome,Nota`
`Carlos,9.5`
`Beatriz,8.0`
`Marcos,7.5`

&nbsp;

# Importante!

- Se o texto de uma coluna **contiver mais de uma palavra** dentro dele, precisa colocar **aspas** para evitar erro.

Exemplo:  "Ana Paula",20,"São Paulo, SP"

&nbsp;

# 📄 Arquivo `.csv` em C

Vamos supor que a gente tenha um arquivo `dados.csv` com este conteúdo:

`Nome,Idade,Cidade`
`Ana,20,São Paulo`
`João,25,Rio de Janeiro`
`Maria,30,Belo Horizonte`

Nosso objetivo vai ser:

- Abrir esse arquivo
- Ler linha por linha
- Separar os campos (nome, idade, cidade)
- Mostrar cada pessoa na tela

&nbsp;

## 📜 Código completo com explicação linha a linha

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para usar strtok()

int main()
{
    FILE *arquivo;
    char linha[100];
    char *coluna;

    // Abre o arquivo para leitura
    arquivo = fopen("dados.csv", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Lê linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        
	// Remove o '\n' do final, se existir
        linha[strcspn(linha, "\n")] = 0;

        // Separa a linha em pedaços usando a vírgula como separador
        coluna = strtok(linha, ",");

        // Mostra as colunas separadamente
        while (coluna != NULL) {
            printf("%s ", coluna);
            coluna = strtok(NULL, ",");
        }

        printf("\n"); // muda de linha para o próximo registro
    }

    fclose(arquivo);

return 0;
}
```

&nbsp;

## Resultado final na tela

Rodando o programa acima com o exemplo de `dados.csv`, a saída vai ser:

`Nome Idade Cidade`
`Ana 20 São Paulo`
`João 25 Rio de Janeiro`
`Maria 30 Belo Horizonte`

|                          Linha                          | Explicação                                                                |
| :------------------------------------------------------: | --------------------------------------------------------------------------- |
|                  `#include <stdio.h>`                  | Para entrada/saída padrão e funções de arquivo.                         |
|                 `#include <stdlib.h>`                 | Para usar `exit()` no erro de abertura.                                   |
|                 `#include <string.h>`                 | Para usar `strtok()`, que separa a linha nas vírgulas.                   |
|                    `FILE *arquivo;`                    | Ponteiro para o arquivo que vamos abrir.                                    |
|                   `char linha[100];`                   | Vetor para guardar cada linha lida do arquivo.                              |
|                    `char *coluna;`                    | Ponteiro para guardar cada pedaço da linha (cada coluna).                  |
|          `arquivo = fopen("dados.csv", "r");`          | Abre o arquivo para leitura.                                                |
|                 `if (arquivo == NULL)`                 | Verifica se abriu corretamente.                                             |
| `while (fgets(linha, sizeof(linha), arquivo) != NULL)` | Lê uma linha do arquivo até chegar no final.                              |
|           `linha[strcspn(linha, "\n")] = 0;`           | Remove o `\n` no final da linha. (segurança para strtok funcionar certo) |
|             `coluna = strtok(linha, ",");`             | Separa a linha no primeiro campo até a vírgula.                           |
|                `while (coluna != NULL)`                | Percorre todos os campos separados.                                         |
|                `printf("%s ", coluna);`                | Mostra cada campo.                                                          |
|             `coluna = strtok(NULL, ",");`             | Continua pegando os próximos campos.                                       |
|                    `printf("\n");`                    | Depois de cada linha, pula para outra linha.                                |
|                   `fclose(arquivo);`                   | Fecha o arquivo.                                                            |

&nbsp;

# 🧠 O que é `strtok()`?

- O `strtok` ("string tokenizer") **corta** uma string em **pedaços** usando o caractere separador que você escolher (neste caso, a vírgula `,`).

Primeira chamada: `coluna = strtok(linha, ",");`

Diz: "me dá a primeira palavra até a vírgula".


Depois: `coluna = strtok(NULL, ",");`

Diz: "me dá a próxima palavra até a vírgula".

Vai repetindo até não achar mais vírgula.
