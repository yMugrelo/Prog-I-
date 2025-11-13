#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

void limpar_tela(void){
    system("cls || clear");
}

void pausar(void){
    int c; 
    printf("\n Pressione ENTER para continuar..."); 
    while((c = getchar() != '\n' && c != EOF)){} //Uso de IA
    getchar();
}

void mostrar_cabecalho(void){
    printf(BLUE "===========================================\n" RESET);
    printf(BLUE "     CALCULADORA BINÁRIA & HEXADECIMAL\n" RESET);
    printf(BLUE "===========================================\n" RESET);
}