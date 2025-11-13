#ifndef INTERFACE_H
#define INTERFACE_H



#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void limpar_tela(void); 
void pausar(void);
void mostrar_cabecalho(void);

#endif