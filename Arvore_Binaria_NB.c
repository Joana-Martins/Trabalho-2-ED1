#include "Arvore_Binaria_NB.h"

ArvBin* cria_ArvBin(){
  ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
  // ArvBin aux = malloc(sizeof(struct NO*));
  //*raiz = aux;
  //(*raiz) = malloc(sizeof(struct NO));
  //(*raiz) -> posicao = 0;
  *raiz = NULL;
  return raiz;
}

int insere_ArvBin(ArvBin* raiz, char *p){
  if(*raiz == NULL){
    *raiz = malloc(sizeof(struct NO));
    (*raiz) -> dir = NULL;
    (*raiz) -> esq = NULL;
    (*raiz) -> posicao++;
    (*raiz) -> info = (Info*) malloc (sizeof(Info));
    (*raiz) -> info -> palavra = (char*)malloc((strlen(p)+1)*sizeof(char));
    strcpy((*raiz) -> info -> palavra, p);
    (*raiz) -> info -> indice = 0;


  }
  if(strcmp(p, (*raiz) -> info -> palavra) < 0){
    return insere_ArvBin(&((*raiz)-> esq), p);
  }
  if(strcmp(p, (*raiz) -> info -> palavra) > 0){
    return insere_ArvBin(&((*raiz)-> dir), p);
  }
  if(strcmp(p, (*raiz) -> info -> palavra) == 0){
    (*raiz) -> info -> posicoes[(*raiz) -> info -> indice] = (*raiz) -> posicao;
    (*raiz) -> posicao++;
    (*raiz) -> info -> indice++;
  }
return 0;
}

void libera_NO(struct NO* no){
  if(no == NULL){
    return;
  }
  libera_NO(no ->esq);
  libera_NO(no->dir);
  free(no -> info -> palavra);
  free(no -> info -> posicoes);
  free(no-> info);
  free(no);
  no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
  if(*raiz == NULL){
    return;
  }
  libera_NO(*raiz);
  free(raiz);
}

int Procura_ArvBin(ArvBin *raiz, char *procura){
  int i;
  if(strcmp(((*raiz) -> info -> palavra), procura) == 0){
    for(i = 0; i < ((*raiz) -> info -> indice); i++){
      printf("%i ", (*raiz) -> info -> posicoes[i]);
      return 0;
    }
  }
  if(strcmp(procura, (*raiz) -> info -> palavra) < 0){
    return Procura_ArvBin(&((*raiz)-> esq), procura);
  }
  if(strcmp(procura, (*raiz) -> info -> palavra) > 0){
    return Procura_ArvBin(&((*raiz)-> dir), procura);
  }
  return 0;
}

void consulta_ArvBin(char *procura, char **arquivos, int tam){
    ArvBin *raiz = cria_ArvBin();
    FILE *l;
    char *aux=malloc(47*sizeof(char));
    int i;
    for(i = 0; i < tam; i++){
      l = fopen(arquivos[i], "r");
      if(!l) printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
      else{
        while(fscanf(l, "%s", aux) != EOF){
          insere_ArvBin(raiz, aux);
        }
        printf("%s ", arquivos[i]);
        Procura_ArvBin(raiz, procura);
        printf("\n");
        libera_ArvBin(raiz);
        fclose(l);
        raiz = cria_ArvBin();
      }
    }
    libera_ArvBin(raiz);
    free(aux);
  }
