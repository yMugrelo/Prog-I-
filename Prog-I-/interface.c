#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

// Limpa a tela no Windows ou Linux
void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Mostra o cabeçalho da calculadora
void mostrar_cabecalho() {
    printf(GREEN "=============================\n");
    printf("   CALCULADORA DE BASES\n");
    printf("=============================\n" RESET);
}
