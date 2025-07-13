**O que é um ponteiro?** 

Ponteiro é uma variável especial que guarda um endereço de memória - ou seja, ele aponta para um local onde alguma coisa está guardada.


Explicação bem simples:

> Você tem uma cópia de um papel com seu nome.
> Agora pensa: se você der uma cópia pra alguém e essa pessoa riscar o nome, o original continua igual, certo? -> variável
>
> Mas se você deixar a pessoa mexer no papel original, aí sim ela pode alterar seu nome de verdade. -> ponteiro

Uma variável reserva apenas um bloquinho na memória para armazenar certo valores, mas você não tem acesso ao bloquinho diretamente (endereço de memória), somente ao valor que está dentro dele. Quando você declara, por exemplo, int idade = 20;, o compilador reserva um pedacinho da memória pra guardar esse 20.

&nbsp;

Enquanto isso, os ponteiros são úteis para ter acesso tanto ao endereço da memória quanto também ao valor, por isso são mais flexíveis. Com ponteiros é possível:

- Saber onde o valor está guardado (endereço de memória);
- Modificar o valor diretamente dentro desse endereço;
- Criar uma função que altere o valor de uma variável dentro delas mesmo, ou seja passar dados para funções de forma mais eficiente (sem cópia dos parâmetros) passando apenas o endereço com ponteiros;
- Alocar espaço de memória em tempo real (`int *numeros = malloc(n * sizeof(int));`);
- Criar estruturas dinâmicas como listas, árvores, etc.&nbsp;


| Expressão  | O que faz                                         | `pa` muda? | Conteúdo muda? |
| ----------- | ------------------------------------------------- | ------------ | --------------- |
| `*pa++`   | Acessa o valor atual e depois avança `pa`      | Sim          | Não            |
| `(*pa)++` | Incrementa o valor apontado por `pa`            | Não         | Sim             |
| `*(pa++)` | Acessa (sem usar) o valor e depois avança `pa` | Sim          | Não            |
