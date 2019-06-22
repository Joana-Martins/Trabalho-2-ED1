CC=gcc
CFLAGS=-I. -Wall  -lm -g
DEPS = Lista_Encadeada.h Biblioteca_Leitura_Arquivos.h
OBJ = Lista_Encadeada.o Biblioteca_Leitura_Arquivos.o index.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

index: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o