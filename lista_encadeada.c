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
  TipoApontador aux;
  aux = Lista -> Primeiro;
    while(aux != NULL){
      if(strcmp(aux -> item -> palavra, x -> palavra) == 0){
        aux -> item -> qtd++;
        return;
      }
      aux = aux -> Prox;
    }

      if(Lista -> Primeiro == NULL){
        Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
        Lista -> Primeiro -> item = x;
        Lista -> Ultimo = Lista -> Primeiro;
        Lista -> Ultimo -> Prox = NULL;
        return;
      }
        Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
        Lista -> Ultimo = Lista -> Ultimo -> Prox;
        Lista -> Ultimo -> item = x;
        Lista -> Ultimo -> Prox = NULL;

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
  printf("ERRO! PALAVRA NAO ENCONTRADA\n");
}

Item* criaPalavra(int tamanho, char *palavra){
  Item* i;
  i = malloc(sizeof(Item));
  i -> palavra = malloc(tamanho+1 * sizeof(char));
  strcpy(i -> palavra, palavra);
  i -> qtd = 1;
  return i;
}

void liberdade_lista(TipoLista *Lista){
  TipoApontador aux;
  while(Lista->Primeiro != NULL){
    aux = Lista->Primeiro;
    Lista->Primeiro = Lista->Primeiro->Prox;
    free(aux->item->palavra);
    free(aux -> item);
    free(aux);
  }
  free(Lista);
}
