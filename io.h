/**
   IO - Console input/output library.
   @author  José Minelli
   @version 0.1 

 */
// ---------------------- lista de dependencias

#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdarg.h>  // para tratar argumentos
#include <stdbool.h> // para definicoes logicas
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters
#include <iso646.h>  // para and, or, xor, not alternatives

// ---------------------- redefinicoes para apontamentos

#ifndef __IO_REFS__
#define __IO_REFS__

#define nullptr NULL // para compatibilizar com C++
#define null NULL    // para generalizar

#define COLORS_H

#define addr(p) (&(p))  // para obter endereco
#define deref(p) (*(p)) // para obter conteudo de endereco
#define val(p) (*(p))   // para obter conteudo apontado

#define ref * // para passar parametro por referencia
              // (na assinatura)
#define var & // para passar parametro por referencia
              // (na chamada)

#endif

// ---------------------- redefinicoes uteis

#ifndef _IO_H_
#define _IO_H_
// alternativas mais seguras, se disponiveis
#define IO_printf printf   // melhor: printf_s
#define IO_scanf scanf     // melhor: scanf_s
#define IO_fprintf fprintf // melhor: fprintf_s
#define IO_fscanf fscanf   // melhor: fscanf_s

// ---------------------- definicoes de constantes

const bool FALSE = false; // definir constante
const bool TRUE = true;   // definir constante

const char EOS = '\0';    // definir fim de cadeia de caracteres
const char EOL = '\n';    // definir mudanca de linha
const char ENDL[] = "\n"; // definir mudanca de linha

const char STR_EMPTY[] = ""; // definir cadeia de caracteres vazia
const int STR_SIZE = 80;     // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char *chars;     // definir cadeia  de caracteres
typedef int *ints;       // definir arranjo de inteiros
typedef double *doubles; // definir arranjo de reais
typedef bool *bools;     // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int IO_error = 0;     // inicialmente sem erros
bool IO_trace = true; // inicialmente habilitado

// ---------------------- definicoes de funcoes e procedimentos

// ---------------------- para tratamento de erros#ifndef COLORS_H

// color.h
#ifndef COLOR_H
#define COLOR_H

#ifdef __cplusplus
#include <iostream>
extern "C"
{
#endif

// Define macros for ANSI color codes
#define COLOR_OFF "\x1b[0m"

#define COLOR_GRAY "\x1b[30m"
#define COLOR_GRAYBG "\x1b[30;7m"
#define COLOR_GRAYSUB "\x1b[30;4m"

#define COLOR_RED "\x1b[31m"
#define COLOR_REDBG "\x1b[31;7m"
#define COLOR_REDSUB "\x1b[31;4m"

#define COLOR_GREEN "\x1b[32m"
#define COLOR_GREENBG "\x1b[32;7m"
#define COLOR_GREENSUB "\x1b[32;4m"

#define COLOR_YELLOW "\x1b[33m"
#define COLOR_YELLOWBG "\x1b[33;7m"
#define COLOR_YELLOWSUB "\x1b[33;4m"

#define COLOR_BLUE "\x1b[34m"
#define COLOR_BLUEBG "\x1b[34;7m"
#define COLOR_BLUESUB "\x1b[34;4m"

#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_MAGENTABG "\x1b[35;7m"
#define COLOR_MAGENTASUB "\x1b[35;4m"

#define COLOR_CYAN "\x1b[36m"
#define COLOR_CYANBG "\x1b[36;7m"
#define COLOR_CYANSUB "\x1b[36;4m"

#define COLOR_WHITE "\x1b[37m"
#define COLOR_WHITEBG "\x1b[37;7m"
#define COLOR_WHITESUB "\x1b[37;4m"

#define COLOR_ORANGE "\x1b[33m"
#define COLOR_ORANGEBG "\x1b[33;7m"
#define COLOR_ORANGESUB "\x1b[33;4m"

#define COLOR_PINK "\x1b[35m"
#define COLOR_PINKBG "\x1b[35;7m"
#define COLOR_PINKBG "\x1b[35;4m"

    void ColorText(const char *text, const char *color_code)
    {
        printf("%s%s%s", color_code, text, "\e[m");
    }

#ifdef __cplusplus
}
#endif

#endif
//------------ para entradas e saidas

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush()
{
    //  fflush ( stdin );   // para Windows - OBS: NAO RECOMENDADO !
    // para Linux   - OBS: NAO FUNCIONA    !
    int x = 0; // compat�vel com o retorno de getchar()
    do
    {
        x = getchar();
    } while (x != EOF && x != '\n');
    clearerr(stdin); // reiniciar o estado de EOF
} // end IO_flush ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int Readint(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x);
} // end IO_readint ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double Readdouble(const char *const text)
{
    double x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%lf", &x);
    IO_flush();
    return (x);
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float Readfloat(const char *const text)
{
    float x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%f", &x);
    IO_flush();
    return (x);
} // end IO_readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar zero (0) para falso e
            diferente de zero para verdadeiro
 */
bool Readbool(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x != 0);
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char Readchar(const char *const text)
{
    char x = '0';
    if (IO_trace)
        IO_printf("%s", text);
    do
    {
        x = getchar();
    } while ('\n' == x);
    IO_flush();
    //  getchar ( );
    return (x);
} // end IO_readchar ( )

void Encerrar(void)
{
    printf("\nPressione ENTER para continuar...");
    char x = '0';
    do
    {
        x = getchar();
    } while ('\n' != x);
    getchar();
}
void LimparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars New_chars(int size)
{
    return ((chars)malloc((size + 1) * sizeof(char)));
} // fim New_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints New_ints(int size)
{
    return ((ints)malloc((size) * sizeof(int)));
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles New_doubles(int size)
{
    return ((doubles)malloc((size) * sizeof(double)));
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bool New_bools(int size)
{
    return ((bools)malloc((size) * sizeof(bool)));
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
chars Concat(const char *const text1, const char *const text2)
{ // reservar area
    chars buffer = New_chars(strlen(text1) + strlen(text2) + 1);
    strcpy(buffer, text1);
    strcat(buffer, text2);
    return (buffer);
} // fim IO_concat ( )

#ifdef __cplusplus
void Print(const std::string &text)
{
    std::cout << text;
}
void Println(const std::string &text)
{
    std::cout << text << std::endl;
    //  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )
#else
void Print(const char *const text)
{
    IO_printf("%s", text);
    //      puts ( text );
}
void Println(const char *const text)
{
    IO_printf("%s\n", text);
    //  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )
#endif


/**
    Metodo para gravar uma linha em arquivo texto.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void Fprint(FILE *filePtr, const char *const text)
{
    IO_fprintf(filePtr, "%s", text);
} // fim IO_fprint ( )

/**
    Metodo para gravar uma linha em arquivo texto
    e mudar de linha.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void Fprintln(FILE *filePtr, const char *const text)
{
    IO_fprintf(filePtr, "%s\n", text);
} // fim IO_fprintln ( )

/**
    Funcao para ler uma cadeia de caracteres de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
chars Fileread(FILE *filePtr)
{
    chars buffer = New_chars(STR_SIZE + 1);

    IO_fscanf(filePtr, "%s", buffer); // ler uma cadeia
    return (buffer);
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
chars Filereadln(FILE *filePtr)
{
    chars buffer = New_chars(STR_SIZE + 1);

    fgets(buffer, STR_SIZE, filePtr); // ler uma linha
    buffer[strlen(buffer) - 1] = EOS; // reposicionar o fim de linha
    return (buffer);
} // fim IO_freadln ( )

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text - mensagem a ser exibida antes da leitura
 */
chars Readstring(const char *const text)
{
    chars buffer = New_chars(STR_SIZE + 1);
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%80s", buffer); // ler cadeia de caracteres
                              // com limitacao de 80 posicoes
    IO_flush();
    return (buffer);
} // fim IO_readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text - mensagem a ser exibida antes da leitura
 */
chars Readln(const char *const text)
{
    if (IO_trace)
        IO_printf("%s", text);
    return (Filereadln(stdin));
} // fim IO_readln ( )

/**
    Funcao para converter valor logico para cadeia de caracteres.
    @return "true", se verdadeiro; "false", caso contrario
    @param  value - valor a ser convertido
 */
chars Boolalpha(bool value)
{
    if (value)
        return (strdup("true"));
    else
        return (strdup("false"));
} // fim IO_boolalpha ( )

/**
    Funcao para comparar conteudos em memoria.
    @return true, se iguais; false, caso contrario
    @param  p1   - endereco do primeiro valor
    @param  p2   - endereco do segundo  valor
    @param  size - tamanho em bytes a ser comparado
 */
bool IO_check(void *p1, void *p2, unsigned int size)
{
    return (p1 && p2 && (0 == memcmp(p1, p2, size)));
} // fim IO_check ( )

/**
    Funcao para retornar o tamanho de cadeia de caracteres.
    @return tamanho, se existir; 0, caso contrario
    @param  text  - cadeia de caracteres
 */
int Length(char *text)
{
    int x = 0;
    if (text)
    {
        x = strlen(text);
    }
    return (x);
} // fim IO_length ( )

/**
    Funcao para obter simbolo de certa posicao
    em cadeia de caracteres.
    @return simbolo, se existir; '\0', caso contrario
    @param  text  - cadeia de caracteres
    @param  index - posicao desejada
 */
char IO_charAt(char *text, unsigned int index)
{
    char x = '\0';
    if (text && index < strlen(text))
    {
        x = text[index];
    }
    return (x);
} // fim IO_charAt ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text  - cadeia de caracteres
    @param  start - onde comecar
    @param  size  - quantos caracteres copiar
 */
char *Substring(char *text, int start, unsigned int size)
{
    chars buffer = NULL;
    if (start >= 0 && (start + size) < (int)strlen(text))
    {
        buffer = New_chars(size + 1);
        memcpy(buffer, text + start, size);
        buffer[size] = '\0';
    }
    return (buffer);
} // fim IO_substring ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text   - cadeia de caracteres
    @param  symbol - caractere a ser acrescentado
 */
char *Strapp(char *text, char symbol)
{
    chars buffer = NULL;
    int size = 0;
    if (text)
    {
        size = strlen(text);
        buffer = New_chars(size + 1);
        memcpy(buffer, text, size);
        buffer[size] = symbol;
        buffer[size + 1] = '\0';
    }
    return (buffer);
} // fim IO_strapp ( )

#endif
