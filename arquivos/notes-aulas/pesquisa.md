# Introdução

Em C, **arquivos** (files) são usados para **armazenar dados permanentemente**. Diferente das variáveis normais (que vivem apenas enquanto o programa está rodando na memória RAM), **dados gravados em arquivos permanecem mesmo após o programa encerrar**.

**Exemplo de arquivos:** `.txt`, `.dat`, `.csv`, etc.

A linguagem C fornece uma biblioteca padrão (`stdio.h`) que nos permite:

- Criar um arquivo
- Abrir um arquivo
- Ler dados de um arquivo
- Escrever dados em um arquivo
- Fechar um arquivo

&nbsp;

# Conceitos principais

&nbsp;

## Ponteiro para arquivo (`FILE *`)

- Para manipular arquivos, a C usa um tipo especial de ponteiro chamado `FILE`.

`FILE *arquivo;`

\*Esse ponteiro vai **apontar** para uma estrutura interna que guarda informações sobre o arquivo (como nome, localização, status, etc.).

&nbsp;

## Abrir um arquivo (`fopen`)

Antes de usar um arquivo, precisamos **abrir** ele com a função `fopen`.

`arquivo = fopen("dados.txt", "modo");`

- `"dados.txt"` é o nome do arquivo.
- `"modo"` é o modo de abertura, como:

  - `"r"` → read → abre para **leitura** (o arquivo deve já existir).
  - `"w"` → write → abre para **escrita** (se existir, apaga o conteúdo; se não existir, cria).
  - `"a"` → append → abre para **adicionar** no final do arquivo.
  - `"r+"` → leitura e escrita.
  - `"w+"` → sobrescrever ou criar arquivo para leitura e escrita.
  - `"a+"` → ler e adicionar no final.

⚠️ Importante: `fopen` retorna `NULL` se falhar (ex: arquivo não encontrado no modo leitura).

&nbsp;

# Operações básicas

&nbsp;

## Escrever em um arquivo

`fprintf(arquivo, "Texto que quero gravar\n");`

- Semelhante ao `printf`, mas escreve no arquivo!

&nbsp;

## Ler de um arquivo

`fscanf(arquivo, "%d", &numero);`

- Semelhante ao `scanf`, mas lê do arquivo!

Outra opção: `fgets` para ler linha por linha.

`fgets(string, tamanho, arquivo);`

&nbsp;

## Fechar o arquivo (`fclose`)

Depois de terminar, **sempre** feche o arquivo para garantir que os dados sejam salvos corretamente.

`fclose(arquivo);`

&nbsp;

# Resumo visual

```
#include <stdio.h>

int main()

{
    FILE *arquivo;

    arquivo = fopen("dados.txt", "w");



    if (arquivo == NULL)

    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }



    fprintf(arquivo, "Hello, world!\n");

    fclose(arquivo);



    return 0;
}
```

1. Cria um ponteiro para arquivo: `FILE *arquivo`.
2. Abre/cria um arquivo chamado `dados.txt` no modo de **escrita** `"w"`.
3. Verifica se abriu corretamente (se `arquivo == NULL`, deu erro).
4. Escreve `"Hello, world!\n"` no arquivo.
5. Fecha o arquivo.

\*Se você abrir o arquivo dados.txt, verá: "Hello, world!".

&nbsp;

# Dicas importantes

- **Sempre verifique** se o `fopen` funcionou (testar se o ponteiro não é `NULL`).
- **Sempre feche** o arquivo com `fclose` para evitar problemas de gravação.
- Você pode abrir o mesmo arquivo várias vezes em modos diferentes.
- Para arquivos binários (não texto), use modos `"rb"`, `"wb"`, `"ab"` etc.
- Existem funções específicas para arquivos binários: `fread`, `fwrite`.&nbsp;
