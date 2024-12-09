TARGET = program

CC = gcc
CFLAGS = -Wall -Wextra -I./modulos/gerais -I./modulos/produtos -I./modulos/clientes -I./modulos/vendas -I./modulos/entregas -I./modulos/validacoes/endereco -I./modulos/validacoes/clientes

SRCDIR = .
SOURCES = main.c \
          modulos/gerais/gerais.c \
          modulos/produtos/produtos.c \
          modulos/clientes/clientes.c \
          modulos/vendas/vendas.c \
          modulos/entregas/entregas.c \
   

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean