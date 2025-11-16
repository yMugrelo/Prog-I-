#include "historico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAP 4

void historico_init(Historico *h) {
    if (!h) return;
    h->itens = malloc(INITIAL_CAP * sizeof(Operacao));
    if (!h->itens) {
        h->tamanho = 0;
        h->capacidade = 0;
        return;
    }
    h->tamanho = 0;
    h->capacidade = INITIAL_CAP;
}

void historico_free(Historico *h) {
    if (!h) return;
    for (size_t i = 0; i < h->tamanho; i++) {
        free(h->itens[i].a_str);
        free(h->itens[i].b_str);
    }
    free(h->itens);
    h->itens = NULL;
    h->tamanho = 0;
    h->capacidade = 0;
}

int historico_add(Historico *h, int base, const char *a, const char *b, char op, int resultado) {
    if (!h || !a || !b) return 0;

    if (h->tamanho == h->capacidade) {
        size_t nova_cap = (h->capacidade == 0 ? INITIAL_CAP : h->capacidade * 2);
        Operacao *tmp = realloc(h->itens, nova_cap * sizeof(Operacao));
        if (!tmp) return 0;
        h->itens = tmp;
        h->capacidade = nova_cap;
    }

    Operacao *it = &h->itens[h->tamanho];

    it->base = base;
    it->op = op;
    it->resultado = resultado;

    it->a_str = malloc(strlen(a) + 1);
    it->b_str = malloc(strlen(b) + 1);

    if (!it->a_str || !it->b_str) {
        free(it->a_str);
        free(it->b_str);
        return 0;
    }

    strcpy(it->a_str, a);
    strcpy(it->b_str, b);

    h->tamanho++;
    return 1;
}

/* ================= SALVAR BINÁRIO ================= */

int historico_salvar_bin(const Historico *h, const char *filename) {
    if (!h) return 0;

    FILE *f = fopen(filename, "wb");
    if (!f) return 0;

    fwrite(&h->tamanho, sizeof(size_t), 1, f);

    for (size_t i = 0; i < h->tamanho; i++) {
        Operacao *it = &h->itens[i];

        size_t la = strlen(it->a_str);
        size_t lb = strlen(it->b_str);

        fwrite(&it->base, sizeof(int), 1, f);
        fwrite(&la, sizeof(size_t), 1, f);
        fwrite(it->a_str, 1, la, f);
        fwrite(&lb, sizeof(size_t), 1, f);
        fwrite(it->b_str, 1, lb, f);
        fwrite(&it->op, sizeof(char), 1, f);
        fwrite(&it->resultado, sizeof(int), 1, f);
    }

    fclose(f);
    return 1;
}

/* ================= CARREGAR BINÁRIO ================= */

int historico_carregar_bin(Historico *h, const char *filename) {
    if (!h) return 0;

    FILE *f = fopen(filename, "rb");
    if (!f) return 0;

    historico_free(h);
    historico_init(h);

    size_t qtd;
    if (fread(&qtd, sizeof(size_t), 1, f) != 1) {
        fclose(f);
        return 0;
    }

    for (size_t i = 0; i < qtd; i++) {
        int base;
        size_t la, lb;
        char op;
        int resultado;

        if (fread(&base, sizeof(int), 1, f) != 1) break;
        if (fread(&la, sizeof(size_t), 1, f) != 1) break;

        char *a = malloc(la + 1);
        if (!a) break;
        fread(a, 1, la, f);
        a[la] = '\0';

        if (fread(&lb, sizeof(size_t), 1, f) != 1) { free(a); break; }

        char *b = malloc(lb + 1);
        if (!b) { free(a); break; }
        fread(b, 1, lb, f);
        b[lb] = '\0';

        fread(&op, sizeof(char), 1, f);
        fread(&resultado, sizeof(int), 1, f);

        historico_add(h, base, a, b, op, resultado);

        free(a);
        free(b);
    }

    fclose(f);
    return 1;
}

/* ================= SALVAR TXT ================= */

int historico_salvar_txt(const Historico *h, const char *filename) {
    if (!h || !filename) return 0;

    FILE *f = fopen(filename, "w");
    if (!f) return 0;

    for (size_t i = 0; i < h->tamanho; i++) {
        const Operacao *it = &h->itens[i];
        fprintf(f, "[%zu] Base %d: %s %c %s => %d\n",
                i + 1, it->base, it->a_str, it->op, it->b_str, it->resultado);
    }

    fclose(f);
    return 1;
}

/* ================= PRINT ================= */

void historico_print(const Historico *h) {
    printf("=== Histórico (%zu operações) ===\n", h->tamanho);

    for (size_t i = 0; i < h->tamanho; i++) {
        Operacao *it = &h->itens[i];
        printf("[%zu] Base %d: %s %c %s => %d\n",
               i + 1, it->base, it->a_str, it->op, it->b_str, it->resultado);
    }
}

void historico_limpar(Historico *h) {
    if (!h) return;
    h->tamanho = 0;
}
