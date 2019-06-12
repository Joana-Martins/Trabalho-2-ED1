#include "lista_encadeada.h"

void main(){
  TipoLista *lista;
  lista = FLVazia();
  char* p;
  p = malloc(10 *sizeof(char));
  Item *aux;
  int i = 0;
  while(i != 10){
    scanf("%s", p);
    aux = criaPalavra(strlen(p), p);
    Insere(aux, lista);
    i++;
  }
  Item *procura;
  procura = criaPalavra(3, "oi");
  ImprimeLista(lista, procura);
  liberdade_lista(lista);
  free(p);
  free(procura);
  free(aux -> palavra);
  free(aux);
}
