#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Padroniza_Palavra.h"

typedef struct{
  char *Palavra;
  long int Posicao;
}TipoItem;

typedef struct TipoCelula* TipoApontador;
typedef struct TipoCelula{
  TipoItem *Item;
  TipoApontador Proximo;
}TipoCelula;

typedef struct{
  TipoApontador Primeiro, Ultimo;
}TipoLista;

TipoLista* Inicializa_Lista();

int Lista_Vazia(TipoLista *Lista);

void Insere_Lista(char *Palavra, TipoLista *Lista, FILE *Arquivo);

void Procura_Lista(char* Palavra, TipoLista *Lista);

void Desaloca_Lista(TipoLista *Lista);

void Busca_Lista(char **Arquivos, char *Procura, int qtdArquivos);

#endif //LISTA_ENCADEADA_H_