CC=gcc
CFLAGS=-I. -Wall  -lm -g
DEPS = Lista_Encadeada.h Arvore_Binaria_NB.h Tabela_Hash.h Biblioteca_Leitura_Arquivos.h Padroniza_Palavra.h
OBJ = Lista_Encadeada.o Arvore_Binaria_NB.o Tabela_Hash.o Biblioteca_Leitura_Arquivos.o Padroniza_Palavra.o index.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

index: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
