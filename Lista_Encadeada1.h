#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
  char *palavra;
  int indice;
  long int *posicao;
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

//void Retira(TipoLista *Lista, Produto *Item);

void Procura(TipoLista *Lista, char *x);

//int Quantidade(TipoLista Lista);

Item* criaPalavra(char *palavra);

void liberdade_lista(TipoLista *Lista);

void lista_de_busca(char **arquivos, char *procurando, int tam);

#endif //LISTA_ENCADEADA_H_