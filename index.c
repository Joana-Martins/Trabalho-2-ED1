#include "Lista_Encadeada.h"
#include "Biblioteca_Leitura_Arquivos.h"

int main(int argc, char* argv[]){
  //int qtdBusca = atoi(argv[1]);
  int tam=argc-2;
  char **arquivos=matriz_arquivos(argc, argv);
  char *procurar = malloc(47 * sizeof(char));
  Item *i;
  printf("\nDigite a palavra a ser buscada: ");
  scanf(" %s", procurar);
  i = criaPalavra(procurar);
  lista_de_busca(arquivos, i, tam);
  free(procurar);
  free(i->palavra);
  free(i);
  for(int i=0;i<tam;i++) free(arquivos[i]);
  free(arquivos);
  return 0;
}
