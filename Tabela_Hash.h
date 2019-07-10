#ifndef HASH_H_
#define HASH_H_

#include <sys/time.h>
#include "Lista_Encadeada.h"
#define TAM_MAX 70
#define N 200
#define TAMALFABETO 256

typedef unsigned TipoPesos[N][TAMALFABETO];

typedef TipoLista TipoDicionario[TAM_MAX];

void Gera_Pesos(TipoPesos Pesos);

int Funcao_Hash(char* Palavra, TipoPesos Pesos);

void FLVazia(TipoLista *Lista);

void Inicializa_Hash(TipoDicionario Hash);

void Insere_Hash(char* Palavra, TipoPesos Pesos, TipoDicionario Hash, FILE *Arquivo);

void Procura_Hash(char* Palavra, TipoPesos Pesos, TipoDicionario Hash);

void Desaloca_Hash(TipoDicionario Hash);

void Busca_Hash(char **Arquivos, char *Procura, int qtdArquivos);

#endif //HASH_H_