# PONTIFICIA UNIVERSIDAD JAVERIANA
# Autor: J. Vargas
# Materia: Sistemas Operativos
# Clase: 2154
# Descripción: Makefile para compilar Servidor y Cliente

CC = gcc
CFLAGS = -Wall -g
TARGETS = servidor cliente

all: $(TARGETS)

servidor: servidor.o servidor_utils.o
	$(CC) $(CFLAGS) -o servidor servidor.o servidor_utils.o

servidor.o: servidor.c servidor_utils.h
	$(CC) $(CFLAGS) -c servidor.c

servidor_utils.o: servidor_utils.c servidor_utils.h
	$(CC) $(CFLAGS) -c servidor_utils.c

cliente: cliente.o
	$(CC) $(CFLAGS) -o cliente cliente.o

cliente.o: cliente.c
	$(CC) $(CFLAGS) -c cliente.c

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean
