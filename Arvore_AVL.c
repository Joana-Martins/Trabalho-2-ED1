#include "Arvore_AVL.h"

int altura_NO(struct NO* no){
  if(no == NULL){
    return -1;
  }else{
    return no->altura;
  }
}

int fatorBalanceamento_NO(struct NO* no){
  return labs(altura_NO(no -> esq) - altura_NO(no -> dir));

}

Info maior(Info x, Info y){
  if (strcmp(x.palavra, y.palavra) > 0){
    return x;
  }else{
    return y;
  }
}

int estaVazia_ArvAVL(ArvBin *raiz){
  if(raiz == NULL){
    return 1;
  }
  if(*raiz == NULL){
    return 1;
  }
  return 0;
}

int totalNO_ArvAVL(ArvBin *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz == NULL){
    return 0;
  }
  int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
  int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
  return (alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvBin *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz = NULL){
    return 0;
  }
  int alt_esq = altura_ArvAVL(&((*raiz) -> esq));
  int alt_dir = altura_ArvAVL(&((*raiz)-> dir));
  if(alt_esq > alt_dir){
    return (alt_esq + 1);
  }else{
    return (alt_dir + 1);
  }
}

void RotacaoLL(ArvBin *A){
  struct NO *B;
  B = (*A) -> esq;
  (*A)->esq = B -> dir;
  B -> dir = *A;

  (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B -> altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
  *A = B;

}

void RotacaoRR(ArvBin *A){
  struct NO* B;
  B = (*A) -> dir;
  (*A)->dir = B -> esq;
  B -> esq = (*A);
  (*A) -> altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B -> altura = maior(altura_NO(B->dir), (*A) -> altura) + 1;
  (*A) = B;
}

void RotacaoLR(ArvBin *A){
  RotacaoRR(&(*A)->esq);
  RotacaoLL(A);
}

void RotacaoRL(ArvBin *A){
  RotacaoLL(&(*A)->dir);
  RotacaoRR(A);
}

int insere_ArvAVL(ArvBin *raiz, char *valor, FILE *l){
  char *res;

  if(*raiz == NULL){
    struct NO *novo.
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL){
      return;
    }

    novo -> info -> palavra = (char*)malloc(47 * sizeof(char));
    novo -> info -> posicoes = (long int*)malloc(1000 *sizeof(long int));
    strcpy(novo -> info -> palavra, valor);
    novo -> info -> indice = 0;
    novo -> altura = 0;
    novo -> esq = 0;
    novo -> dir = NULL;
    *raiz = novo;
    return 1;
  }

  struct NO *atual = *raiz;
  if(strcmp(valor -> , (*raiz) -> info -> palavra) < 0){
    if(insere_ArvAVL(&(atual -> esq), valor) == 1){
      if(fatorBalanceamento_NO(atual) >= 2){
        if(strcmp(valor -> , (*raiz) -> esq -> info -> palavra) < 0){
          RotacaoLL(raiz);
        }else{
        RotacaoLR(raiz);
        }
      }
    }
  }else{
    if(strcmp(valor -> , (*raiz) -> info -> palavra) < 0){
      if(insere_ArvAVL(&(atual -> esq), valor) == 1){
        if(fatorBalanceamento_NO(atual) >= 2){
            if(strcmp(valor -> , (*raiz) -> dir -> info -> palavra) < 0){
              RotacaoRR(raiz);
            }else{
              RotacaoRL(raiz);
            }
        }
      }
    }else{
      (*raiz) -> info -> posicoes[(*raiz) -> info -> indice] = ftell(l);
      (*raiz) -> info -> indice++;
      return 0;
    }
  }
  atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;
}
