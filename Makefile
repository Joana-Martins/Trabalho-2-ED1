CC=gcc
CFLAGS=-I. -Wall  -lm -g
DEPS = Lista_Encadeada.h Arvore_Binaria_NB.h Arvore_AVL.h Tabela_Hash.h Biblioteca_Leitura_Arquivos.h
OBJ = Lista_Encadeada.o Arvore_Binaria_NB.o Arvore_AVL.o Tabela_Hash.o Biblioteca_Leitura_Arquivos.o index.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

index: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
