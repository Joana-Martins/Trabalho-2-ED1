#include "Lista_Encadeada.h"

TipoLista* Inicializa_Lista(){
  TipoLista *Lista = (TipoLista*)malloc(sizeof(TipoLista));
  Lista -> Primeiro = NULL;
  Lista -> Ultimo = Lista -> Primeiro;
  return Lista;
}

int Lista_Vazia(TipoLista *Lista){
  return (Lista -> Ultimo == Lista -> Primeiro);
}

void Insere_Lista(char *Palavra, TipoLista *Lista, FILE *Arquivo){
  if(Lista -> Primeiro == NULL){
    Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> Item = (TipoItem*)malloc(sizeof(TipoItem));
    Lista -> Primeiro -> Item -> Palavra = (char*)malloc(strlen(Palavra)+1 * sizeof(char));
    strcpy(Lista -> Primeiro -> Item -> Palavra, Palavra);
    Lista -> Primeiro -> Item -> Posicao = ftell(Arquivo);
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Proximo = NULL;
    Lista -> Ultimo -> Proximo = Lista -> Primeiro -> Proximo;
  }
  else{
    Lista -> Ultimo -> Proximo = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Proximo;
    Lista -> Ultimo -> Item = (TipoItem*)malloc(sizeof(TipoItem));
    Lista -> Ultimo -> Item -> Palavra = (char*)malloc(strlen(Palavra)+1 * sizeof(char));
    strcpy(Lista -> Ultimo -> Item -> Palavra, Palavra);
    Lista -> Ultimo -> Item -> Posicao = ftell(Arquivo);
    Lista -> Ultimo -> Proximo = NULL;
  }
}

void Procura_Lista(char* Palavra, TipoLista *Lista){
  TipoApontador aux;
  int contador = 0;
  aux = Lista -> Primeiro;
  while(aux != NULL){
    if(strcmp(aux -> Item -> Palavra, Palavra) == 0){
      printf("%ld ", aux -> Item -> Posicao - strlen(Palavra) + 1);
      contador++;
    }
    aux = aux -> Proximo;
  }
  if(contador == 0) printf("PALAVRA NAO ENCONTRADA!\n");
}

void Desaloca_Lista(TipoLista *Lista){
  TipoApontador aux = Lista -> Primeiro;
  TipoApontador aux2;
  while(aux != NULL){
    aux2 = aux;
    aux = aux -> Proximo;
    free(aux2 -> Item -> Palavra);
    free(aux2 -> Item);
    free(aux2);
  }
  free(Lista);
}

void Busca_Lista(char **Arquivos, char *Procura, int qtdArquivos){
  TipoLista *Lista = Inicializa_Lista();
  char *aux=malloc(47*sizeof(char));
  char *Palavra;
  FILE *Arquivo;
  for(int i = 0; i < qtdArquivos; i++){
    Arquivo = fopen(Arquivos[i], "r");
    if(!Arquivo) printf("%s ARQUIVO INEXISTENTE\n", Arquivos[i]);
    else{
      while(fscanf(Arquivo, "%s", aux) != EOF){
        padroniza_Palavra(aux);
        Palavra=malloc(strlen(aux)+1);
        strcpy(Palavra,aux);
        Insere_Lista(Palavra, Lista, Arquivo);
        free(Palavra);
      }
      printf("%s ", Arquivos[i]);
      Procura_Lista(Procura, Lista);
      Desaloca_Lista(Lista);
      fclose(Arquivo);
      Lista = Inicializa_Lista();
    }
  }
  Desaloca_Lista(Lista);
  free(aux);
}