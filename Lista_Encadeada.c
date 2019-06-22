#include "Lista_Encadeada.h"

TipoLista *FLVazia(){
  TipoLista *Lista = malloc(sizeof(TipoLista));
  Lista -> posicao = 0;
  Lista -> Primeiro = NULL;
  Lista -> Ultimo = NULL;
  return Lista;
}

int Vazia(TipoLista *Lista){
  return (Lista->Primeiro == Lista->Ultimo); //se vazia, retorna 0.
}

void Insere(Item *x, TipoLista *Lista){
if(Lista -> Primeiro == NULL){
  Lista -> posicao++;
  Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Primeiro -> item = x;
  Lista -> Primeiro -> item -> posicao = Lista -> posicao;
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  Lista -> Ultimo -> Prox = Lista -> Primeiro -> Prox;
  return;
  }

  Lista -> posicao++;
  Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> item = x;
  Lista -> Ultimo -> item -> posicao = Lista -> posicao;
  Lista -> Ultimo -> Prox = NULL;
}

void Procura(TipoLista *Lista, Item *x){
  TipoApontador aux;
  int contador = 0;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    if(strcmp(aux -> item -> palavra, x -> palavra) == 0){
      printf("%i ", aux -> item -> posicao);
      contador++;
    }
    aux = aux -> Prox;
  }
  if(contador == 0) printf("PALAVRA NAO ENCONTRADA!\n");
  else return;
}

Item* criaPalavra(char *palavra){
  Item* i;
  i = (Item*)malloc(sizeof(Item));
  i -> palavra = (char*)malloc((strlen(palavra)+1) * sizeof(char));
  strcpy(i -> palavra, palavra);
  return i;
}

void liberdade_lista(TipoLista *Lista){
  TipoApontador aux = Lista->Primeiro;
  TipoApontador aux2;
  while(aux != NULL){
    aux2 = aux;
    aux = aux->Prox;
    free(aux2->item->palavra);
    free(aux2 -> item);
    free(aux2);
  }
  free(Lista);
}

void lista_de_busca(char **arquivos, Item *procurando, int tam){
  TipoLista *lista;
  lista = FLVazia();
  char *aux=malloc(47*sizeof(char));
  char *palavra;
  int i;
  FILE *l;
  Item *item;
  for(i = 0; i < tam; i++){
    l = fopen(arquivos[i], "r");
    if(!l) printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
    else{
      while(fscanf(l, "%s", aux) != EOF){
        palavra=malloc(strlen(aux)+1);
        strcpy(palavra,aux);
        item = criaPalavra(aux);
        Insere(item, lista);
        free(palavra);   
      }
      printf("%s ", arquivos[i]);
      Procura(lista, procurando);
      printf("\n");
      liberdade_lista(lista);
      fclose(l);
      lista = FLVazia();
    }
  }
  liberdade_lista(lista);
  free(aux);
}
