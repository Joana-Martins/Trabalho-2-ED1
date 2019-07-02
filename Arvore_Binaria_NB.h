#ifndef ARVORE_BINARIA_NB_H_
#define ARVORE_BINARIA_NB_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct info{
  char *palavra;
  int indice;
  long int *posicoes;
}Info;

struct NO{
  Info *info;
  int altura;
  struct NO *esq;
  struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

int insere_ArvBin(ArvBin* raiz, char *p, FILE *f);

void Procura_ArvBin(ArvBin *raiz, char *procura);

void libera_NO(struct NO* no);

void libera_ArvBin(ArvBin *raiz);

void consulta_ArvBin(char *procura, char **arquivos, int tamanho);

#endif //ARVORE_BINARIA_NB_H_
