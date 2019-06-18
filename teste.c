#include "lista_encadeada.h"
#include <stdlib.h>

void main(){
  TipoLista *lista;
  lista = FLVazia();
  char* p;
  p = malloc(10 *sizeof(char));
  Item *aux;
  int i = 0;
  while(i != 10){
    scanf("%s", p);
    aux = criaPalavra(p);
    Insere(aux, lista);
    i++;
  }
  Item *procura;
  procura = criaPalavra("oi");
  Procura(lista, procura);
  liberdade_lista(lista);
  free(p);
  free(procura -> palavra);
  free(procura);
}
