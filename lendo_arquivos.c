#include "lendo_arquivos.h"

char** matriz_arquivos(){
  char *arquivo, *opcao;
  char **arquivos;
  int i = 0, j=1, w = 0;
  arquivo = malloc(70 * sizeof(char));
  opcao = malloc (5 * sizeof(char));
  arquivos = malloc(100 * sizeof(char));
    for(w = 0; w < 100; w++){
      arquivos[w]= malloc(70 * sizeof(char));
    }
    do{
      printf("Digite 'sair' para terminar\n");
      printf("Digite 'prox' para adicionar mais arquivos\n");
      printf("Digite o nome do arquivo: ");
      scanf("%s", arquivo);
      scanf("%s", opcao);
      if((strcmp(opcao, "prox") != 0) && (strcmp(opcao, "sair") != 0)){
        printf("Entrada inválida. Por favor digite novamente!\n");
        scanf("%s", opcao);
        }
        system("clear");
        strcpy(arquivos[j],arquivo);
        j++;
    }while(strcmp("sair",opcao) != 0);
    arquivos[0][0] = j;
    return arquivos;
}



/*for(w = 0; w < j; w++){
    ler = fopen(arquivos[w], "r");
    while(){
      strcpy(c, );
    }
    fclose(teste);
    printf("%s\n", c);
    i = 0;
  }
}
*/
