#include "Lista_Encadeada.h"

TipoLista *FLVazia(){
  TipoLista *Lista = malloc(sizeof(TipoLista));
  Lista -> Primeiro = NULL;
  Lista -> Ultimo = Lista -> Primeiro;
  return Lista;
}

int Vazia(TipoLista *Lista){
  return (Lista->Primeiro == Lista->Ultimo); //se vazia, retorna 1.
}

void Insere(char *x, TipoLista *Lista, FILE *f){
if(Lista -> Primeiro == NULL){
  Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Primeiro -> item = (Item*)malloc(sizeof(Item));
  Lista -> Primeiro -> item -> palavra = (char*)malloc(strlen(x)+1 * sizeof(char));
  strcpy(Lista -> Primeiro -> item -> palavra, x);
  Lista -> Primeiro -> item -> posicao = ftell(f);
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  Lista -> Ultimo -> Prox = Lista -> Primeiro -> Prox;
  return;
  }

  Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> item = (Item*)malloc(sizeof(Item));
  Lista -> Ultimo -> item -> palavra = (char*)malloc(strlen(x)+1 * sizeof(char));
  strcpy(Lista -> Ultimo -> item -> palavra, x);
  Lista -> Ultimo -> item -> posicao = ftell(f);
  Lista -> Ultimo -> Prox = NULL;
}

void Procura(TipoLista *Lista, char *x){
  TipoApontador aux;
  int contador = 0;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    if(strcmp(aux -> item -> palavra, x) == 0){
      printf("%ld ", aux -> item -> posicao - strlen(x) + 1);
      contador++;
    }
    aux = aux -> Prox;
  }
  if(contador == 0) printf("PALAVRA NAO ENCONTRADA!\n");
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

void lista_de_busca(char **arquivos, char *procurando, int tam){
  TipoLista *lista;
  lista = FLVazia();
  char *aux=malloc(47*sizeof(char));
  char *palavra;
  int i;
  FILE *l;
  for(i = 0; i < tam; i++){
    l = fopen(arquivos[i], "r");
    if(!l) printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
    else{
      while(fscanf(l, "%s", aux) != EOF){
        padroniza_Palavra(aux);
        palavra=malloc(strlen(aux)+1);
        strcpy(palavra,aux);
        Insere(palavra, lista, l);
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