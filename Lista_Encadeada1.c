#include "Lista_Encadeada.h"

TipoLista *FLVazia(){
  TipoLista *Lista = malloc(sizeof(TipoLista));
  Lista -> Primeiro = NULL;
  Lista -> Ultimo = NULL;
  return Lista;
}

int Vazia(TipoLista *Lista){
  return (Lista->Primeiro == Lista->Ultimo); //se vazia, retorna 0.
}

TipoCelula * Percorre_Lista(TipoLista *Lista, char *c){
  if(Lista == NULL){
    printf("Lista nao iniciada\n");
    exit(0);
  }
  TipoApontador aux, aux2;
  aux = Lista -> Primeiro;
    while(aux != NULL){
      aux2 = aux;
      aux = aux->Prox;
      if(strcasecmp(aux2->item->palavra, c) == 0){
        return aux2;
      }
    }
    return NULL;
}

void Insere(char *x, TipoLista *Lista, FILE *f){
if(Lista -> Primeiro == NULL){
  Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista -> Primeiro -> item = criaPalavra(x);
  Lista -> Primeiro -> item -> posicao[Lista -> Primeiro -> item -> indice] = ftell(f);
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  Lista -> Ultimo -> Prox = Lista -> Primeiro -> Prox;
  return;
  }

  TipoApontador aux;
  aux = Percorre_Lista(Lista, x);
  if(aux == NULL){
    Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> item = criaPalavra(x);
    Lista -> Ultimo -> Prox = NULL;
  }else{
    aux -> item -> indice++;
    aux -> item -> posicao[Lista -> Ultimo -> item -> indice] = ftell(f);
  }
}

void Procura(TipoLista *Lista, char *x){
  TipoApontador aux;
  int contador = 0, i;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    if(strcasecmp(aux -> item -> palavra, x) == 0){
      for(i = 0; i < aux -> item -> indice+1; i++){
        printf("%ld ", aux -> item -> posicao[i] - strlen(x)+1);
        contador++;
      }
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
  i -> posicao = (long int*) malloc(1000* sizeof(long int));
  i -> indice = 0;
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

void lista_de_busca(char **arquivos, char *procurando, int tam){
  TipoLista *lista;
  lista = FLVazia();
  char *aux=malloc(47*sizeof(char));
  int i;
  FILE *l;
  for(i = 0; i < tam; i++){
    l = fopen(arquivos[i], "r");
    if(!l) printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
    else{
      while(fscanf(l, "%s", aux) != EOF){
        Insere(aux, lista, l);
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
