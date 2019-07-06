#include "Arvore_Binaria_NB.h"

ArvBin* cria_ArvBin(){
  ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
  *raiz = NULL;
  return raiz;
}

int insere_ArvBin(ArvBin* raiz, char *p, FILE *f){
  if(*raiz == NULL){
    *raiz = malloc(sizeof(struct NO));
    (*raiz) -> dir = NULL;
    (*raiz) -> esq = NULL;
    (*raiz) -> info = (Info*) malloc (sizeof(Info));
    (*raiz) -> info -> palavra = (char*)malloc((strlen(p)+1)*sizeof(char));
    strcpy((*raiz) -> info -> palavra, p);
    (*raiz) -> info -> posicoes = malloc(100000*sizeof(long int));
    (*raiz) -> info -> indice = 0;
  }

  if(strcmp(p, (*raiz) -> info -> palavra) < 0){
    return insere_ArvBin(&((*raiz)-> esq), p, f);
  }
  if(strcmp(p, (*raiz) -> info -> palavra) > 0){
    return insere_ArvBin(&((*raiz)-> dir), p, f);
  }
  if(strcmp(p, (*raiz) -> info -> palavra) == 0){
    (*raiz) -> info -> posicoes[(*raiz) -> info -> indice] = ftell(f);
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
  free(no -> info -> posicoes);;;
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

void Procura_ArvBin(ArvBin *raiz, char *procura){
  if((*raiz)==NULL) printf("\nPALAVRA NAO ENCONTRADA!\n");
  else if(strcmp(procura, (*raiz)->info->palavra)==0){
    for(int j = 0; j < (*raiz)->info->indice; j++){
      printf("%ld ", (*raiz) -> info -> posicoes[j] - strlen(procura)+1);
    }
  } 
  else if(strcmp(procura, (*raiz)->info->palavra)<0) Procura_ArvBin(&(*raiz)->esq, procura);
  else if(strcmp(procura, (*raiz)->info->palavra)>0) Procura_ArvBin(&(*raiz)->dir, procura);
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
          padroniza_Palavra(aux);
          insere_ArvBin(raiz, aux, l);
        }
        printf("%s ", arquivos[i]);
        Procura_ArvBin(raiz,procura);
        printf("\n");
        libera_ArvBin(raiz);
        fclose(l);
        raiz = cria_ArvBin();
      }
    }
    libera_ArvBin(raiz);
    free(raiz);
    free(aux);
  }
