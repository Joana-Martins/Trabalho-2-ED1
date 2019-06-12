#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
  char *palavra;
  int qtd;
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

int Vazia(TipoLista Lista);

void Insere(Item *x, TipoLista *Lista);

//void Retira(TipoLista *Lista, Produto *Item);

void ImprimeLista(TipoLista *Lista, Item *x);

//int Quantidade(TipoLista Lista);

Item* criaPalavra(int tamanho, char *palavra);

void liberdade_lista(TipoLista *Lista);

#endif //LISTA_ENCADEADA_H_
