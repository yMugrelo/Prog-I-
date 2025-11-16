// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "conversoes.h"
#include "operacoes.h"
#include "historico.h"
#include "utils.h"




void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ---- PAUSA REAL OFICIAL (LIMPA BUFFER + ESPERA ENTER) ----
void pausar() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // limpa buffer
    printf("\nPressione ENTER para continuar...");
    getchar();
}
// -----------------------------------------------------------

int main(void) {
    Historico hist;
    historico_init(&hist);

    // tenta carregar histórico (se existir)
    historico_carregar_bin(&hist, "historico.bin");

    int opcao = -1;
    while (1) {
        limpar_tela();
        mostrar_cabecalho();
        printf(YELLOW "1. Converter Decimal → Binário\n");
        printf("2. Converter Decimal → Hexadecimal\n");
        printf("3. Converter Binário → Decimal\n");
        printf("4. Converter Hexadecimal → Decimal\n");
        printf("5. Calcular (+, -, *, /) entre dois números (base 2 ou 16)\n");
        printf("6. Mostrar histórico\n");
        printf("7. Salvar histórico em arquivo\n");
        printf("8. Salvar txt\n");
        printf("0. Sair\n" RESET);
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) { 
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            opcao = -1;
            continue;
        }

        limpar_tela();

        if (opcao == 0) {
            printf(GREEN "Encerrando o programa...\n" RESET);

            if (historico_salvar_bin(&hist, "historico.bin"))
                printf(GREEN "Histórico salvo em 'historico.bin'\n" RESET);
            else
                printf(RED "Falha ao salvar histórico\n" RESET);

            pausar();
            break;
        }
        else if (opcao == 1) {
            int num;
            printf("Digite o número decimal: ");
            scanf("%d", &num);
            char *s = decimal_para_bin_str(num);
            printf("Binário: %s\n", s);
            historico_add(&hist, 10, s, "decimal->bin", 'C', num);
            free(s);
        }
        else if (opcao == 2) {
            int num;
            printf("Digite o número decimal: ");
            scanf("%d", &num);
            char *h = decimal_para_hex_str(num);
            printf("Hexadecimal: %s\n", h);
            historico_add(&hist, 10, h, "decimal->hex", 'C', num);
            free(h);
        }
        else if (opcao == 3) {
            char bin[129];
            printf("Digite o número binário: ");
            scanf("%128s", bin);
            long d = binario_para_decimal(bin);
            printf("Decimal: %ld\n", d);
            historico_add(&hist, 2, bin, "->dec", 'C', (int)d);
        }
        else if (opcao == 4) {
            char hex[129];
            printf("Digite o número hexadecimal: ");
            scanf("%128s", hex);
            long d = hex_para_decimal(hex);
            printf("Decimal: %ld\n", d);
            historico_add(&hist, 16, hex, "->dec", 'C', (int)d);
        }
        else if (opcao == 5) {
            int base;
            char a[129], b[129];
            char op;
            printf("Escolha a base (2 = binário | 16 = hexadecimal): ");
            scanf("%d", &base);
            if (base != 2 && base != 16) {
                printf(RED "Base inválida (use 2 ou 16)\n" RESET);
                pausar();
                continue;
            }
            printf("Digite o primeiro número: ");
            scanf("%128s", a);
            printf("Digite o segundo número: ");
            scanf("%128s", b);
            printf("Escolha a operação (+, -, *, /): ");
            scanf(" %c", &op);

            int erro = 0;
            int res = executar_operacao(a, b, base, op, &erro);
            if (erro == 1) {
                printf(RED "Erro: divisão por zero!\n" RESET);
            } else if (erro == 2) {
                printf(RED "Erro: operação inválida!\n" RESET);
            } else {
                printf(GREEN "\n--- RESULTADOS ---\n" RESET);
                printf("Decimal: %d\n", res);
                char *bin = decimal_para_bin_str(res);
                char *hex = decimal_para_hex_str(res);
                printf("Binário: %s\n", bin);
                printf("Hexadecimal: %s\n", hex);
                historico_add(&hist, base, a, b, op, res);
                free(bin);
                free(hex);
            }
        }
        else if (opcao == 6) {
            historico_print(&hist); 
            pausar();  // <-- AQUI resolve o problema do histórico sumir
            continue;
        }
        else if (opcao == 7) {
            if (historico_salvar_bin(&hist, "historico.bin"))
                printf(GREEN "Histórico salvo com sucesso em 'historico.bin'\n" RESET);
            else
                printf(RED "Falha ao salvar histórico\n" RESET);
        }
        else if (opcao == 8) {
            if (historico_salvar_txt(&hist, "historico.txt"))
                printf(GREEN "Histórico salvo como texto em 'historico.txt'\n" RESET);
            else
                printf(RED "Falha ao salvar histórico em texto\n" RESET);
        }
        else {
            printf(RED "Opção inválida!\n" RESET);
        }

        pausar();
    }

    historico_free(&hist);
    return 0;
}