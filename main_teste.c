#include "lista_busca.h"
#include "lista_encadeada.h"
#include "lendo_arquivos.h"

void main(){
  char **arquivos;
  char *procurar = malloc(47 * sizeof(char));
  Item *i;
  arquivos = matriz_arquivos();
  printf("Digite a palavra a ser buscada: ");
  scanf("%s", procurar);
  i = criaPalavra(procurar);
  lista_de_busca(arquivos, i);
  free(procurar);
}