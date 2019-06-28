#ifndef ARVORE_AVL_H_
#define ARVORE_AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Arvore_Binaria_NB.h"

int altura_NO(struct NO* no);

int fatorBalanceamento_NO(struct NO* no);

int maior(int x, int y);

int estaVazia_ArvAVL(ArvBin *raiz);

int totalNO_ArvAVL(ArvBin *raiz);

int altura_ArvAVL(ArvBin *raiz);

void RotacaoLL(ArvBin *A);

void RotacaoRR(ArvBin *A);

void RotacaoLR(ArvBin *A);

void RotacaoRL(ArvBin *A);

int insere_ArvAVL(ArvBin *raiz, char* valor, FILE *l);

void consulta_ArvAVL(char *procura, char **arquivos, int tam);

#endif //ARVORE_AVL_H_
