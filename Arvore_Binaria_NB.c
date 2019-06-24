#include "Arvore_Binaria_NB.h"

ArvBin* cria_ArvBin(){
  ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
  (*raiz) -> posicao = 0;
  *raiz = NULL;

  return raiz;
}

int insere_ArvBin(ArvBin* raiz, Item i){
  if(*raiz == NULL){
    *raiz = malloc(sizeof(struct NO));
    (*raiz) -> dir = NULL;
    (*raiz) -> esq = NULL;
    (*raiz) -> posicao++;
    (*raiz) -> item -> palavra = (char*)malloc((strlen(i->palavra)+1)*sizeof(char));
    strcpy((*raiz) -> item -> palavra, i->palavra);
    (*raiz) -> item -> posicao = (*raiz) -> posicao;

  }
  if(valor < (*raiz) -> info){
    return insere_ArvBin(&((*raiz)-> esq), i);
  }
  if(valor > (*raiz) -> info){
    return insere_ArvBin(&((*raiz)-> dir), i);
  }
return 0;
}

int consulta_ArvBin(ArvBin *raiz, char *procura){

}

void libera_NO(struct NO* no){

}

void libera_ArvBin(ArvBin *raiz){

}
