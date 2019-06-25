#include "Arvore_Binaria_NB.h"

ArvBin* cria_ArvBin(){
  ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
  (*raiz) -> posicao = 0;
  *raiz = NULL;

  return raiz;
}

int insere_ArvBin(ArvBin* raiz, Info i){
  if(*raiz == NULL){
    *raiz = malloc(sizeof(struct NO));
    (*raiz) -> dir = NULL;
    (*raiz) -> esq = NULL;
    (*raiz) -> posicao++;
    (*raiz) -> info -> palavra = (char*)malloc((strlen(i->palavra)+1)*sizeof(char));
    strcpy((*raiz) -> info -> palavra, i->palavra);
    (*raiz) -> info -> indices = 0;


  }
  if(strcmp(i -> palavra, (*raiz) -> info) < 0){
    return insere_ArvBin(&((*raiz)-> esq), i);
  }
  if(strcmp(i -> palavra, (*raiz) -> info) > 0){
    return insere_ArvBin(&((*raiz)-> dir), i);
  }
  if(strcmp(i -> palavra, (*raiz) -> info) == 0){
    (*raiz) -> info -> posicoes[(*raiz) -> info -> indice] = (*raiz) -> posicao;
    (*raiz) -> info -> indice++;
  }
return 0;
}

int consulta_ArvBin(ArvBin *raiz, char *procura){


}

void libera_NO(struct NO* no){

}

void libera_ArvBin(ArvBin *raiz){

}
