#include "operacoes.h"
#include "conversoes.h"
#include <stdlib.h>
#include <stdio.h>

int executar_operacao(const char *a_str, const char *b_str, int base, char op, int *erro){
    *erro = 0; 

    long a = 0, b = 0; 

    switch(base){
        case 2:
            a = binario_para_decimal_str(a_str); 
            b = binario_para_decimal_str(b_str);
            break; 
        case 10:
            a = atoi(a_str);
            b = atoi(b_str);
            break;
        case 16:
            a = hex_para_decimal(a_str); 
            b = hex_para_decimal(b_str); 
            break;
        default:
            printf("Base invalida!"); 
            *erro = 3;
            return 0; 
    }
    long res = 0; 
    switch(op){
        case '+':  res = a + b;break; 
        
        case '-': res = a - b; break;
        
        case '*': res = a * b; break;
        case '/':
            if (b == 0) {
                *erro = 1; 
                return 0;
            }
            res = a / b;
            break;
        
        default:
            *erro = 2; 
            return 0;
    }
    return (int)res;
}