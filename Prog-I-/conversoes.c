#include "conversoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *decimal_para_bin_str(int n) {
    if (n == 0) {
        char *s = malloc(2);
        strcpy(s, "0");
        return s;
    }
    char tmp[64];
    int i = 0;
    while (n > 0) {
        tmp[i++] = (n % 2) + '0';
        n /= 2;
    }
    tmp[i] = '\0';

    char *res = malloc(i + 1);
    for (int j = 0; j < i; j++)
        res[j] = tmp[i - j - 1];
    res[i] = '\0';
    return res;
}

char *decimal_para_hex_str(int n) {
    char *s = malloc(20);
    sprintf(s, "%X", n);  // ajuda da IA para converter pra hexadecimal
    return s;
}

long binario_para_decimal_str(const char *bin) {
    long dec = 0;
    for (int i = 0; bin[i] != '\0'; i++) {
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}

long binario_para_decimal(const char *bin_str) {
    return binario_para_decimal_str(bin_str);
}

long hex_para_decimal(const char *hex_str) {
    long val = 0;
    sscanf(hex_str, "%lx", &val);
    return val;
}
