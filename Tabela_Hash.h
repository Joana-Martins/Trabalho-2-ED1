/*#ifndef HASH_H_
#define HASH_H_
#include<stdlib.h>
#include<string.h>
struct aluno{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};
struct hash{
  int qtd, TABLE_SIZE;
  struct aluno** itens;
};
typedef struct hash Hash;
Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int valorString(char* str);
int insereHash_SemColisao(Hash* ha, struct aluno al);
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al);
int insereHash_EnderAberto(Hash* ha, struct aluno al);
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al);
#endif*/

#ifndef HASH_H_
#define HASH_H_


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "Lista_Encadeada.h"
#define M 7
#define N 20
#define TAMALFABETO 256

typedef char TipoChave[N];
typedef unsigned TipoPesos[N][TAMALFABETO];
typedef unsigned int TipoIndice;

typedef TipoLista TipoDicionario[M];

void FLVazia_Hash(TipoLista *Lista);

void Ins(char* x, TipoLista *Lista, FILE *f);

//void Ret(TipoApontador p, TipoLista *Lista, TipoItem *Item);

void GeraPesos(TipoPesos p);

TipoIndice h(char* Chave, TipoPesos p);

void Inicializa(TipoDicionario T);

TipoApontador Pesquisa(char* Ch, TipoPesos p, TipoDicionario T);

void Insere_Hash(char* x, TipoPesos p, TipoDicionario T, FILE *f);

void Retira_Hash(Item x, TipoPesos p, TipoDicionario T);

void Imp(TipoLista* Lista);

void Imprime(TipoDicionario Tabela);

void busca_Hash(char **arquivos, char *procurando, int tam);

#endif