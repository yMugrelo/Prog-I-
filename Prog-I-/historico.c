#include "historico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITAL_CAP 4

void historico_init(Historico *h)//Uso de ia pra entender a construcao de uma funcao função que inicializa uma estrutura Historico passada por ponteiro.
{
    h->itens = malloc(INITAL_CAP * sizeof(Operacao));
    h->tamanho = 0; 
    h->capacidade = h->itens ? INITAL_CAP : 0; //se malloc teve sucesso, capacidade = INITIAL_CAP; se falhou (itens == NULL) coloca 0 (indica vazio/sem memória).
}
void historico_free(Historico *h){
    if (!h) return; 
    for(size_t i = 0; i < h->tamanho; i++){
        free(h->itens[i].a_str); 
        free(h->itens[i].b_str); 
    }
    free(h->itens);
    h->itens = NULL; 
    h->tamanho = h->capacidade = 0;}

    
int historico_add(Historico *h, int base, const char *a, const char *b, char op, int resultado) {
    if (h->tamanho == h->capacidade) {
        size_t nova = (h->capacidade == 0) ? INITAL_CAP : h->capacidade * 2;
        Operacao *tmp = realloc(h->itens, nova * sizeof(Operacao));
        if (!tmp) return 0;
        h->itens = tmp;
        h->capacidade = nova;
    }
    // copia strings dinamicamente
    h->itens[h->tamanho].base = base;
    h->itens[h->tamanho].a_str = malloc(strlen(a) + 1);
    h->itens[h->tamanho].b_str = malloc(strlen(b) + 1);
    if (!h->itens[h->tamanho].a_str || !h->itens[h->tamanho].b_str) return 0;
    strcpy(h->itens[h->tamanho].a_str, a);
    strcpy(h->itens[h->tamanho].b_str, b);
    h->itens[h->tamanho].op = op;
    h->itens[h->tamanho].resultado = resultado;
    h->tamanho++;
    return 1;
}

// Formato simples de arquivo binário:
// primeiro gravamos um size_t com h->tamanho,
// para cada item gravamos: int base; size_t len_a; data a; size_t len_b; data b; char op; int resultado;

int historico_salvar_bin(Historico *h, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return 0;
    if (fwrite(&h->tamanho, sizeof(size_t), 1, f) != 1) { fclose(f); return 0; }
    for (size_t i = 0; i < h->tamanho; ++i) {
        Operacao *it = &h->itens[i];
        size_t la = strlen(it->a_str);
        size_t lb = strlen(it->b_str);
        if (fwrite(&it->base, sizeof(int), 1, f) != 1) { fclose(f); return 0; }
        if (fwrite(&la, sizeof(size_t), 1, f) != 1) { fclose(f); return 0; }
        if (fwrite(it->a_str, 1, la, f) != la) { fclose(f); return 0; }
        if (fwrite(&lb, sizeof(size_t), 1, f) != 1) { fclose(f); return 0; }
        if (fwrite(it->b_str, 1, lb, f) != lb) { fclose(f); return 0; }
        if (fwrite(&it->op, sizeof(char), 1, f) != 1) { fclose(f); return 0; }
        if (fwrite(&it->resultado, sizeof(int), 1, f) != 1) { fclose(f); return 0; }
    }
    fclose(f);
    return 1;
}

int historico_carregar_bin(Historico *h, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    historico_free(h);
    historico_init(h);
    size_t tam = 0;
    if (fread(&tam, sizeof(size_t), 1, f) != 1) { fclose(f); return 0; }
    for (size_t i = 0; i < tam; ++i) {
        int base;
        size_t la, lb;
        if (fread(&base, sizeof(int), 1, f) != 1) { fclose(f); return 0; }
        if (fread(&la, sizeof(size_t), 1, f) != 1) { fclose(f); return 0; }
        char *a = malloc(la + 1);
        if (!a) { fclose(f); return 0; }
        if (fread(a, 1, la, f) != la) { free(a); fclose(f); return 0; }
        a[la] = '\0';

        if (fread(&lb, sizeof(size_t), 1, f) != 1) { free(a); fclose(f); return 0; }
        char *b = malloc(lb + 1);
        if (!b) { free(a); fclose(f); return 0; }
        if (fread(b, 1, lb, f) != lb) { free(a); free(b); fclose(f); return 0; }
        b[lb] = '\0';

        char op;
        int resultado;
        if (fread(&op, sizeof(char), 1, f) != 1) { free(a); free(b); fclose(f); return 0; }
        if (fread(&resultado, sizeof(int), 1, f) != 1) { free(a); free(b); fclose(f); return 0; }

        if (!historico_add(h, base, a, b, op, resultado)) { free(a); free(b); fclose(f); return 0; }
        free(a); free(b); // historico_add já fez cópias
    }
    fclose(f);
    return 1;
}
#include <stdio.h>
#include "historico.h"

int historico_salvar_txt(const Historico *h, const char *filename) {
    if (!h || !filename) return 0;
    FILE *f = fopen(filename, "w");
    if (!f) return 0;

    for (size_t i = 0; i < h->tamanho; ++i) {
        const Operacao *it = &h->itens[i];
        // Exemplos de linha: [1] Base 10: 15 C 7 => 22
        // Mas salvamos de forma legível: índice, base, a_str, op, b_str, resultado
        fprintf(f, "[%zu] Base %d: %s %c %s => %d\n",
                i + 1,
                it->base,
                it->a_str ? it->a_str : "(null)",
                it->op,
                it->b_str ? it->b_str : "(null)",
                it->resultado);
    }

    fclose(f);
    return 1;
}

void historico_print(const Historico *h) {
    printf("=== Histórico (%zu) ===\n", h->tamanho);
    for (size_t i = 0; i < h->tamanho; ++i) {
        const Operacao *it = &h->itens[i];
        printf("[%zu] Base %d: %s %c %s => %d\n", i+1, it->base, it->a_str, it->op, it->b_str, it->resultado);
    }

}