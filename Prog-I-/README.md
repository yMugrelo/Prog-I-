📘 Calculadora Multibase em C
Conversor e Calculadora em Decimal, Binário e Hexadecimal

Autores: Murilo Aba e Murilo Rosa de Paula
Professores: Maurício M. Arimoto e Felipe H. Manfio
Disciplina: Programação I – 2025

📌 Sobre o Projeto

Este projeto implementa uma calculadora multibase desenvolvida em linguagem C, capaz de:

Converter números entre decimal ⇄ binário

Converter números entre decimal ⇄ hexadecimal

Realizar operações matemáticas (+, –, *, /) em binário ou hexadecimal

Registrar automaticamente todas as operações em um histórico dinâmico

Salvar e carregar o histórico em arquivos texto ou binários

O foco do trabalho é demonstrar domínio sobre:

Funções e modularização

Structs

Ponteiros

Alocação dinâmica (malloc / realloc)

Manipulação de arquivos texto/binário

Organização e boas práticas

Uso ético e crítico de IA durante o desenvolvimento

⚙️ Funcionalidades
✔ Conversões

Decimal → Binário

Decimal → Hexadecimal

Binário → Decimal

Hexadecimal → Decimal

✔ Operações matemáticas em múltiplas bases

Aceita entrada em base 2 ou base 16, convertendo corretamente para decimal para operar:

Soma

Subtração

Multiplicação

Divisão (com tratamento de erro para divisão por zero)

Após o cálculo, o resultado é mostrado em:

Decimal

Binário

Hexadecimal

✔ Histórico inteligente

Cada operação realizada é armazenada em um vetor dinâmico, permitindo:

Adicionar novas operações com realocação automática

Exibir todo o histórico

Salvar o histórico como arquivo .bin

Salvar o histórico como arquivo .txt

Carregar automaticamente o histórico ao iniciar o programa

🧱 Estrutura do Código

O projeto é modularizado em vários arquivos, cada um responsável por uma parte clara do sistema:

main.c
interface.c / interface.h
utils.c / utils.h
conversoes.c / conversoes.h
operacoes.c / operacoes.h
historico.c / historico.h

🗂️ Resumo das responsabilidades
Arquivo	Função
main.c	Loop principal do programa e menu
interface.c	Cabeçalho, formatação e interação visual
utils.c	Funções auxiliares (limpar tela, pausar, etc.)
conversoes.c	Funções de conversão entre bases
operacoes.c	Soma, subtração, multiplicação e divisão entre bases
historico.c	Registro dinâmico das operações + salvar e carregar arquivos
.h	Define structs, funções e contratos de cada módulo


🚀 Como Compilar

No Linux: gcc *.c -Wall -Wextra -o calculadora

▶️ Como Executar
./calculadora

O menu será exibido automaticamente. Basta escolher as opções numéricas:
1. Converter Decimal → Binário
2. Converter Decimal → Hexadecimal
3. Converter Binário → Decimal
4. Converter Hexadecimal → Decimal
5. Operações matemáticas
6. Mostrar histórico
7. Salvar histórico (.bin)
8. Salvar histórico (.txt)
0. Sair


📂 Arquivos Gerados pelo Programa

historico.bin → salva o histórico em binário (carregado automaticamente ao iniciar)

historico.txt → salva o histórico em formato legível

🧠 Uso de IA no Projeto (Contexto para o relatório)

Durante o desenvolvimento utilizamos IA generativa de forma ética e crítica, principalmente para:

Explicações conceituais (ex.: diferença entre malloc e realloc)

Identificação de erros de compilação e linking

Reestruturação de módulos

Geração de exemplos e melhorias de estilo

Reescrita de partes do código já compreendidas

O código final foi revisado linha a linha pela dupla para garantir:

autoria

compreensão

coerência com o conteúdo da disciplina

pleno domínio para apresentação e arguição

🧪 Testes

O repositório inclui:

Exemplos de entrada

Exemplos de saída

Arquivo de histórico para validação

🎤 Apresentação do Trabalho

Durante a apresentação (7–10 min), vamos demonstrar:

1️⃣ Funcionamento do programa

Com exemplos reais de conversões e cálculos.

2️⃣ Justificativa das decisões técnicas

Por que usamos:

Structs

Vetor dinâmico

Arquivos binários

Modularização

Ponteiros

3️⃣ Papel da IA

Exemplos claros do que foi criado com IA com supervisão humana vs. implementações próprias.

4️⃣ Domínio do código

Explicando trechos específicos e respondendo perguntas dos professores.

📅 Prazos

Entrega do código + formulário: até 24/11/2025

Apresentação oral: 26/11/2025

👥 Autores

Murilo Aba
Murilo Rosa de Paula
