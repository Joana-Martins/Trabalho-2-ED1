#ifndef ARVORE_BINARIA_NB_H_
#define ARVORE_BINARIA_NB_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct info{
  char *palavra;
  int indice;
  int *posicoes;
}Info;

struct NO{
  int posicao;
  Info info;
  struct NO *esq;
  struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

int insere_ArvBin(ArvBin* raiz, int valor);

int consulta_ArvBin(ArvBin *raiz, char *procura);

//void preOrdem_ArvBin(ArvBin *raiz);

//void emOrdem_ArvBin(ArvBin *raiz);

//void posOrdem_ArvBin(ArvBin *raiz);

void libera_NO(struct NO* no);

void libera_ArvBin(ArvBin *raiz);

#endif //ARVORE_BINARIA_NB_H_
