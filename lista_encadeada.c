#include "lista_encadeada.h"

TipoLista *FLVazia(){
  TipoLista *Lista;
  Lista = malloc(sizeof(TipoLista));
  Lista -> Primeiro = NULL;
  Lista -> Ultimo = NULL;
  return Lista;
}

int Vazia(TipoLista Lista){
  if (Lista.Primeiro == Lista.Ultimo) {
    return 0;
  }else{
      return 1;
    }
}

void Insere(Item *x, TipoLista *Lista){
  if(existe_lista(x, Lista) == 0){
    Lista -> qtd++;
    return;
  }
  if(Lista -> Primeiro == NULL){
    Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> item = x;
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Ultimo -> Prox = NULL;
  }
  Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> item = x;
  Lista -> Ultimo -> Prox = NULL;
  return;
}

void ImprimeLista(TipoLista *Lista, Item *x){
  TipoApontador aux;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    if(strcmp(aux -> item -> palavra, x -> palavra) == 0){
      printf("%s\n", aux -> item -> palavra);
      printf("%i\n", aux -> item -> qtd);
      return;
    }
    aux = aux -> Prox;
  }
}

Item* criaPalavra(int tamanho, char *palavra){
  Item* i;
  i = malloc(sizeof(Item));
  i -> palavra = malloc(tamanho+1 * sizeof(char));
  strcpy(i -> palavra, palavra);
  i -> qtd = 1;
  return i;
}

int existe_lista(Item *x, TipoLista *Lista){
  TipoApontador aux;
  aux = Lista -> Primeiro;
    while(aux != NULL){
      if(strcmp(aux -> item -> palavra, x -> palavra) == 0){
        return 0;
      }
      aux = aux -> Prox;
    }
      return 1;
}

void liberdade_lista(TipoLista *Lista, int tam){
  TipoApontador aux, aux2;
  int i;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    aux2 = aux;
    free(aux2 -> item -> palavra);
    free(aux2 -> item);
    free(aux2);
    aux = aux -> Prox;
  }
}
