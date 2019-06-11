#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

  FILE *teste;
  char d, *c, *arquivo, *opcao;
  char **arquivos;
  int i = 0, j=0, w = 0;
  c = malloc(1000 * sizeof(char));
  arquivo = malloc(1000 * sizeof(char));
  opcao = malloc(1000 * sizeof(char));
  arquivos = (char**)malloc(1000* sizeof(char*));
  for(w = 0; w <1000; w++){
    arquivos[w]= malloc(1000 * sizeof(char));
  }
  do{
  printf("Digite 'sair' para terminar\n");
  printf("Digite 'proximo' para adicionar mais arquivos\n");
  printf("Digite o nome do arquivo: ");
  scanf("%s", arquivo);
  scanf("%s", opcao);
  strcpy(arquivos[j],arquivo);
  j++;
}while(strcmp("sair",opcao) != 0);

for(w = 0; w < j; w++){
    teste = fopen(arquivos[w], "r");
    while(fscanf(teste, "%c", &d) != EOF){
      c[i] = d;
      i++;
    }
    fclose(teste);
    printf("%s\n", c);
    i = 0;
  }
}
