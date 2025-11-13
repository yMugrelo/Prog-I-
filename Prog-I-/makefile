CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJS = main.o interface.o conversoes.o operacoes.o historico.o

all: calculadora

calculadora: $(OBJS)
	$(CC) $(CFLAGS) -o calculadora $(OBJS)

main.o: main.c interface.h conversoes.h operacoes.h historico.h
	$(CC) $(CFLAGS) -c main.c

interface.o: interface.c interface.h
	$(CC) $(CFLAGS) -c interface.c

conversoes.o: conversoes.c conversoes.h
	$(CC) $(CFLAGS) -c conversoes.c

operacoes.o: operacoes.c operacoes.h
	$(CC) $(CFLAGS) -c operacoes.c

historico.o: historico.c historico.h
	$(CC) $(CFLAGS) -c historico.c

clean:
	rm -f *.o calculadora historic*.bin
