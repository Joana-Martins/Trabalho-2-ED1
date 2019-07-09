#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Padroniza_Palavra.h"

typedef struct item{
  char *palavra;
  long int posicao;
}Item;

typedef struct Celula* TipoApontador;

typedef struct Celula{
  Item *item;
  TipoApontador Prox;
}TipoCelula;

typedef struct{
  TipoApontador Primeiro, Ultimo;
}TipoLista;

TipoLista *FLVazia();

int Vazia(TipoLista *Lista);

void Insere(char *x, TipoLista *Lista, FILE *f);

void Procura(TipoLista *Lista, char *x);

void liberdade_lista(TipoLista *Lista);

void lista_de_busca(char **arquivos, char *procurando, int tam);

#endif //LISTA_ENCADEADA_H_