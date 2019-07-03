#include "Biblioteca_Leitura_Arquivos.h"

char** matriz_arquivos(int argc, char *argv[]){
  int tam=argc-1;
  char **arquivos=malloc(tam*sizeof(char*));
  for(int i=0;i<tam;i++){
    arquivos[i]=malloc(strlen(argv[i+1])+1);
    strcpy(arquivos[i],argv[i+1]);
  } 
  return arquivos;
}