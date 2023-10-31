# Biblioteca JMRL - Biblioteca de Funções para Uso Geral

A Biblioteca JMRL é um conjunto de funções em C e C++ desenvolvido por [José Minelli](https://github.com/joseminelli) e [Raissa Lauar](https://github.com/RaissaLauarNavarro) para oferecer funcionalidades gerais que podem ser úteis em diversos tipos de programas. Ela inclui funções para entrada e saída, manipulação de cadeias de caracteres, texto colorido, gerenciamento de memória e muito mais.

## Como Usar

### C

Para usar a Biblioteca JMRL em um programa C, siga estas etapas:

1. Inclua o cabeçalho da biblioteca em seu programa:

```c
#include "JMRL.h"
```

2. Use as funções fornecidas pela biblioteca conforme necessário em seu programa.

Aqui está um exemplo de uso simples:

```c
int main() {
    chars texto1 = "Esta é uma";
    chars texto2 = " cadeia de caracteres.";

    chars resultado = Concat(texto1, texto2);

    Println(resultado);

    free(resultado); // Lembre-se de liberar a memória alocada.

    return 0;
}
```

### C++

Se você estiver desenvolvendo um programa em C++, a biblioteca JMRL pode ser usada da seguinte forma:

1. Inclua o cabeçalho da biblioteca em seu programa:

```cpp
#include "JMRL.h"
```

2. Use as funções fornecidas pela biblioteca conforme necessário em seu programa.

Aqui está um exemplo de uso simples em C++:

```cpp
#include <iostream>
#include "JMRL.h"

int main() {
    std::string texto1 = "Esta é uma";
    std::string texto2 = " cadeia de caracteres.";

    std::string resultado = Concat(texto1, texto2);

    std::cout << resultado << std::endl;

    return 0;
}
```

Lembre-se de ajustar o código da biblioteca para atender às suas necessidades específicas.

## Funções Disponíveis

A Biblioteca JMRL oferece várias funções úteis, incluindo:


### Funções de Entrada e Saída

#### `Readint`
- Função  para facilitar a leitura de um valor inteiro do teclado.
- Retorna o valor lido.

#### `Readdouble`
- Função para facilitar a leitura de um valor real de precisão dupla do teclado.
- Retorna o valor lido.

#### `Readfloat`
- Função para facilitar a leitura de um valor real de precisão simples do teclado.
- Retorna o valor lido.

#### `Readbool`
- Função para ler um valor lógico do teclado.
- Retorna verdadeiro ou falso.

#### `Readchar`
- Função  para facilitar a leitura de um caractere do teclado.
- Retorna o caractere lido.

#### `ReadString`
- Função para ler uma cadeia de caracteres do teclado.
- Retorna a cadeia de caracteres lida

#### `Print`
- Função para imprimir texto na saída padrão.
- Não retorna nenhum valor.

#### `Println`
- Função para imprimir texto na saída padrão seguido por uma quebra de linha.
- Não retorna nenhum valor.

#### `Encerrar`
- Função para aguardar que o usuário pressione "Enter" para continuar.
- Pausa a execução do programa até que o usuário pressione "Enter".
- Útil para manter a saída visível por um período após a execução do programa.

#### `ColorText`
- Função para imprimir texto colorido na saída padrão.
- Aceita dois argumentos: o texto a ser exibido e o prefixo da cor( Sempre terá o COLOR_ ), como ```COLOR_CYAN```.
- 
#### `ClearCurrentLine`
- Função para limpar a linha atual.
- Útil para apagar linhas indesejadas ou temporárias

### Funções de Manipulação

#### `Concat`
- Função para juntar duas cadeias de caracteres.
- Retorna a junção das duas cadeias.

#### `Substring`
- Função para copiar parte de uma cadeia de caracteres.
- Retorna a parte da cadeia de caracteres especificada.

#### `Length`
- Função para obter o comprimento de uma cadeia de caracteres.
- Retorna o número de caracteres na cadeia.

#### `ehPrimo`
- Função para detectar se o número é primo ou não.
- Retorna caso seja primo.

#### `detectaMaiuscula`
- Função para detectar se o caractere é maiúsculo ou minúsculo.
- Retorna 1 se for um maiuscula, 2 se for minuscula, 3 se não for letra.

#### `detectarCaractere`
- Função para detectar qual o tipo do caractere.
- Retorna 1 se for um letra, 2 se for dígito, 3 se for espaço em branco e 4 se for outro símbolo

#### `NumeroAleatorio`
- Função para gerar um número de acordo com parâmetro de maximo e mínimo
- Retorna o número gerado.

### Funções para Gerenciamento de Memória

#### `New_ints`
- Função para reservar espaço para armazenar inteiros.
- Retorna a área reservada ou `NULL` em caso de falha.

#### `New_doubles`
- Função para reservar espaço para armazenar números reais.
- Retorna a área reservada ou `NULL` em caso de falha.

#### `New_bools`
- Função para reservar espaço para armazenar valores lógicos.
- Retorna a área reservada ou `NULL` em caso de falha.

Espero que essa breve descrição das funções facilite o entendimento de como usá-las em seus projetos.

## Contribuições

Se você deseja contribuir para a Biblioteca JMRL ou encontrou algum problema, sinta-se à vontade para abrir uma [issue](https://github.com/seu-usuario/seu-repositorio/issues) ou enviar um [pull request](https://github.com/seu-usuario/seu-repositorio/pulls).

## Licença

A Biblioteca JMRL é distribuída sob a licença MIT. Consulte o arquivo [LICENSE](https://github.com/seu-usuario/seu-repositorio/blob/master/LICENSE) para obter mais detalhes.

## Contato

Para entrar em contato com o autor da biblioteca, José Minelli, envie um e-mail para joseminelli@email.com.

Esperamos que a Biblioteca JMRL seja útil em seus projetos!
