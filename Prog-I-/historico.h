#ifndef HISTORICO_H
#define HISTORICO_H
#include <stddef.h>
//A biblioteca <stddef.h> em C é uma das mais básicas e fundamentais do padrão.
//Ela fornece definições de tipos e macros padrão que são usadas em muitas partes da linguagem 
//— especialmente em programação de baixo nível, estruturas, ponteiros e tamanhos de dados.

typedef struct {
    int base; 
    char *a_str; 
    char *b_str; 
    char op; 
    int resultado; 
}Operacao; 
typedef struct{
    Operacao *itens; 
    size_t tamanho;
    size_t capacidade; 
}Historico;     

void historico_init(Historico *h); //Ajuda da IA na criacao das funcoes para trabalhar com arquivos
void historico_free(Historico *h);
int historico_add(Historico *h, int base, const char *a, const char *b, char op, int resultado);

int historico_salvar_bin(Historico *h, const char *filename);
int historico_carregar_bin(Historico *h, const char *filename); 
int historico_salvar_txt(const Historico *h, const char *filename);
void historico_print(const Historico *h);
#endif