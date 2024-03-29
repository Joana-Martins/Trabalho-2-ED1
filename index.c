#include "Biblioteca_Leitura_Arquivos.h"
#include "Arvore_Binaria_NB.h"
#include "Tabela_Hash.h"
//#include "Arvore_AVL.h"
#include <time.h>

int main(int argc, char* argv[]){
  int tam=argc-1;
  char **arquivos = matriz_arquivos(argc, argv);
  char *procurar = malloc(47 * sizeof(char));
  clock_t Ticks[2];
  Ticks[0] = clock();
  printf("\nDigite a palavra a ser buscada: ");
  scanf(" %s", procurar);
  padroniza_Palavra(procurar);
  printf("Lista encadeada: \n");
  Busca_Lista(arquivos, procurar, tam);
  printf("Arvore Binária:\n");
  consulta_ArvBin(procurar, arquivos, tam);
  //printf("Arvore Balanceada:\n");
  //consulta_ArvAVL(procurar, arquivos, tam);
  printf("Tabela Hash:\n");
  Busca_Hash(arquivos,procurar,tam);
  free(procurar);
  for(int i=0;i<tam;i++)free(arquivos[i]);
  free(arquivos);
  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo gasto: %g ms.", Tempo);
  printf("\n");
  return 0;
}
