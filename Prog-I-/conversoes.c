#include "conversoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

char *decimal_para_bin_str(int n){
     if (n == 0) {
        char *s = malloc(2);
        if (!s) return NULL;
        strcpy(s, "0");
        return s;
    }
    int tmp = n;
    int bits = 0;
    while (tmp > 0) {
        tmp >>= 1; //IA ajudou a entender como desloca tmp pra direita em 1 bit
        bits++;
    }
    char *s = malloc(bits + 1);
    if (!s) return NULL;
    s[bits] = '\0';

    for (int i = bits - 1; i >= 0; i--) {
        s[i] = (n % 2) + '0';
        n /= 2;
    }
    return s;
}

long binario_para_decimal_str(const char *bin){
    if(!bin) return 0; 
    long decimal = 0; 
    for (int i = 0; bin[i] != '\0'; i++){ 
        if(bin[i] != '\0' && bin[i] != '\1'){ 
            printf("Erro na string! \n");
            return 0; 
        }
        decimal = decimal * 2 + (bin[i] - '0'); 
    }
    return decimal; 
}

long hex_para_decimal(const char *hex){
    if(!hex) return 0; 
    long decimal = 0; 
    for (int i = 0; hex[i] != '\0'; i++){
        char c = toupper(hex[i]); 
        int valor; 
        if(c >= '0' && c <= '9'){//Uso de IA e wikipedia para entendimento dos numeros hexadecimais!
            valor = c - '0';             
        }
        if(c >= 'A' && c <= 'F'){ 
            valor = 10 +(c - 'A');
        }
        else{
            printf("Numero hexadecimal invalido!");
            return 0;
        }
        decimal = decimal * 16 + valor; 
    }
    return decimal; 
}
char *decimal_para_xex_str(int n){
    if(n == 0){
        char *s = malloc(2); 
        if (!s) return NULL;
        strcpy(s, "0");
        return s;
    } 
    char temp[9];
    int i = 0;

    while( n > 0 && i < 8){
        int resto = n % 16; 
        if (resto < 10){
            temp[i++] = '0' + resto; 
        }
        else{
            temp[i++] = 'A' + (resto - 10);
        }
        n /= 16;
    }
    temp[i] = '\0'; 
    char *s = malloc(i + 1); //Novamente precisei pra conseguir inverter a String!
    if (!s) return NULL;

    for (int j = 0; j < i; j++)
        s[j] = temp[i - j - 1];
    s[i] = '\0';

    return s;
}