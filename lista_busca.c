#include "lista_busca.h"

void lista_de_busca(char **arquivos, Item *procurando){
  TipoLista *lista;
  lista = FLVazia();
  char *aux = malloc(47*sizeof(char));
  int i = 0;
  int tam = arquivos[0][0];
  FILE *l;
  Item *item = malloc(sizeof(Item));
  for(i = 1; i < tam; i++){
      l = fopen(arquivos[i], "r");
      while(fscanf(l, "%s", aux) != EOF){
          item = criaPalavra(aux);
          Insere(item, lista);
      }
      printf("%s ", arquivos[i]);
      Procura(lista, procurando);
      printf("\n");
  }


  liberdade_lista(lista);
}
