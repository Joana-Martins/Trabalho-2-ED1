#include "lista_busca.h"

void lista_de_busca(char **arquivos, Item *procurando){
  TipoLista *lista;
  lista = FLVazia();
  char *aux =(char*) malloc(47*sizeof(char));
  int i = 0;
  int tam = arquivos[0][0];
  FILE *l;
  Item *item; 
  for(i = 1; i < tam; i++){
      l = fopen(arquivos[i], "r");
      if(l == NULL){
        printf("Arquivo %s e invalido\n", arquivos[i]);
      }else{
        while(fscanf(l, "%s", aux) != EOF){
            item = criaPalavra(aux);
            Insere(item, lista);
        }
        printf("%s ", arquivos[i]);
        Procura(lista, procurando);
        printf("\n");
        liberdade_lista(lista);
        fclose(l);
        lista = FLVazia();
      }
  }
  free(aux);
  liberdade_lista(lista);
}
