# Calculadora Multibase em C  
Conversor e Calculadora em Decimal, Binário e Hexadecimal

Autores: Murilo Aba e Murilo Rosa de Paula  
Professores: Maurício M. Arimoto e Felipe H. Manfio  
Disciplina: Programação I – 2025

---

## Sobre o Projeto

Este projeto implementa uma calculadora multibase desenvolvida em linguagem C, capaz de:

- Converter números entre decimal ⇄ binário
- Converter números entre decimal ⇄ hexadecimal
- Realizar operações matemáticas (+, –, *, /) em binário ou hexadecimal
- Registrar automaticamente todas as operações em um histórico dinâmico
- Salvar e carregar o histórico em arquivos texto ou binários

O foco do trabalho é demonstrar domínio sobre:

- Funções e modularização  
- Structs  
- Ponteiros  
- Alocação dinâmica (malloc / realloc)  
- Manipulação de arquivos texto/binário  
- Organização e boas práticas  
- Uso ético e crítico de IA durante o desenvolvimento  

---

## Funcionalidades

### Conversões
- Decimal → Binário  
- Decimal → Hexadecimal  
- Binário → Decimal  
- Hexadecimal → Decimal  

### Operações matemáticas
Aceita entrada em base 2 e base 16. O sistema converte tudo para decimal, realiza a operação e exibe o resultado em:

- Decimal  
- Binário  
- Hexadecimal  

Operações disponíveis:
- Soma  
- Subtração  
- Multiplicação  
- Divisão (com tratamento de erro para divisão por zero)

### Histórico de operações
- Armazenamento dinâmico usando realloc  
- Exibição completa do histórico  
- Salvamento em arquivo binário (.bin)  
- Salvamento em arquivo texto (.txt)  
- Carregamento automático ao iniciar o programa  

---

## Estrutura do Código

O projeto é modularizado da seguinte forma:

```
main.c
interface.c / interface.h
utils.c / utils.h
conversoes.c / conversoes.h
operacoes.c / operacoes.h
historico.c / historico.h
```

### Resumo das responsabilidades

| Arquivo | Função |
|--------|--------|
| main.c | Loop principal e menu |
| interface.c | Interface textual e exibição |
| utils.c | Funções auxiliares (limpar tela, pausar etc.) |
| conversoes.c | Conversões entre bases |
| operacoes.c | Implementação das operações matemáticas |
| historico.c | Registro dinâmico + salvar/carregar histórico |

---

## Como Compilar

No Linux:

```
gcc *.c -Wall -Wextra -o calculadora
```

---

## Como Executar

```
./calculadora
```

O menu interativo será exibido automaticamente, permitindo escolher:

1. Converter Decimal → Binário  
2. Converter Decimal → Hexadecimal  
3. Converter Binário → Decimal  
4. Converter Hexadecimal → Decimal  
5. Operações matemáticas  
6. Mostrar histórico  
7. Salvar histórico (.bin)  
8. Salvar histórico (.txt)  
0. Sair  

---

## Arquivos Gerados pelo Programa

- `historico.bin` → histórico salvo em formato binário  
- `historico.txt` → histórico salvo em texto legível  

---

## Uso de IA no Projeto (para o relatório)

Durante o desenvolvimento utilizamos IA generativa para:

- Explicações conceituais (ex.: malloc, ponteiros, modularização)
- Identificação de erros de compilação
- Sugestões de organização
- Reescrita de trechos já compreendidos
- Revisão de código

Todo o código final foi revisado linha a linha pela dupla para garantir:

- autoria  
- compreensão  
- coerência  
- preparo para a apresentação  

---

## Testes Incluídos

O repositório contém:

- Exemplos de entrada  
- Exemplos de saída  
- Arquivo de histórico para verificação  

---

## Apresentação do Trabalho

Durante a apresentação (7–10 minutos), demonstraremos:

1. Funcionamento completo da calculadora  
2. Justificativa técnica da implementação  
3. Papel da IA  
4. Explicação de módulos específicos  
5. Domínio total do código e das decisões tomadas  

---

## Prazos

- Entrega do código + formulário: **24/11/2025**  
- Apresentação oral: **26/11/2025**

---

## Autores

- Murilo Aba  
- Murilo Rosa de Paula
