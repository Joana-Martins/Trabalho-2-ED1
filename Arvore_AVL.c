#include "Arvore_AVL.h"

int altura_NO(struct NO* no) {
	if (no == NULL) {
		return -1;
	} else {
		return no->altura;
	}
}

int fatorBalanceamento_NO(struct NO* no) {
	return labs(altura_NO(no -> esq) - altura_NO(no -> dir));

}

int maior(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

int estaVazia_ArvAVL(ArvBin *raiz) {
	if (raiz == NULL) {
		return 1;
	}
	if (*raiz == NULL) {
		return 1;
	}
	return 0;
}

int totalNO_ArvAVL(ArvBin *raiz) {
	if (raiz == NULL) {
		return 0;
	}
	if ((*raiz) == NULL) {
		return 0;
	}
	int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
	int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
	return (alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvBin *raiz) {
	if (raiz == NULL) {
		return 0;
	}
	if (*raiz == NULL) {
		return 0;
	}
	int alt_esq = altura_ArvAVL(&((*raiz) -> esq));
	int alt_dir = altura_ArvAVL(&((*raiz)-> dir));
	if (alt_esq > alt_dir) {
		return (alt_esq + 1);
	} else {
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

void RotacaoRR(ArvBin *A) {
	struct NO* B;
	B = (*A) -> dir;
	(*A)->dir = B -> esq;
	B -> esq = (*A);
	(*A) -> altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
	B -> altura = maior(altura_NO(B->dir), (*A) -> altura) + 1;
	(*A) = B;
}

void RotacaoLR(ArvBin *A) {
	RotacaoRR(&(*A)->esq);
	RotacaoLL(A);
}

void RotacaoRL(ArvBin *A) {
	RotacaoLL(&(*A)->dir);
	RotacaoRR(A);
}

int insere_ArvAVL(ArvBin *raiz, char *valor, FILE *l) {
	if (*raiz == NULL) {
		struct NO *novo;
		novo = (struct NO*) malloc(sizeof(struct NO));
		if (novo == NULL) {
			return 0;
		}

		novo -> info = (Info*) malloc(sizeof(Info));
		novo -> esq = NULL;
		novo -> dir = NULL;
		//printf("%p\n", novo);
		novo -> info -> palavra = (char*) malloc(47 * sizeof(char));
		novo -> info -> posicoes
				= (long int*) malloc(100000 * sizeof(long int));
		strcpy(novo -> info -> palavra, valor);
		printf("inserido = %s\n",novo -> info -> palavra );
		novo -> info -> indice = 0;
		novo -> info -> posicoes[novo -> info -> indice] = ftell(l);
		novo -> altura = 0;
		*raiz = novo;
		return 1;
	}else{

		struct NO *atual = *raiz;
		if (strcmp(valor, (*raiz) -> info -> palavra) < 0) {
			if (insere_ArvAVL(&(atual -> esq), valor, l) == 1) {
				if (fatorBalanceamento_NO(atual) >= 2) {
					if (strcmp(valor, (*raiz) -> esq -> info -> palavra) < 0) {
						RotacaoLL(raiz);
					}else{
						RotacaoLR(raiz);
					}
				}
			}
		}else{
			if (strcmp(valor, (*raiz) -> info -> palavra) > 0) {
				if (insere_ArvAVL(&(atual -> dir), valor, l) == 1) {
					if (fatorBalanceamento_NO(atual) >= 2) {
						if (strcmp(valor, (*raiz) -> dir -> info -> palavra) > 0) {
							RotacaoRR(raiz);
						} else {
							RotacaoRL(raiz);
						}
					}
				}
			} else{
				(*raiz) -> info -> indice++;
				(*raiz) -> info -> posicoes[(*raiz) -> info -> indice] = ftell(l);
				return 0;
			}
		}
		atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;
		return 0;
	}
}

void Procura_ArvAVL(ArvBin *raiz, char *procura) {
	int i;
	printf("enderco raiz %p\n", *raiz);
	if (*raiz == NULL) {
		printf("Erro na insercao de palavras");
		return;
	}
	printf("palavra %s\n", (*raiz) -> info -> palavra);
	if (strcmp(((*raiz) -> info -> palavra), procura) == 0) {
		for (i = 0; i < (*raiz)->info->indice + 1; i++) {
			printf("oi: %ld ", (*raiz) -> info -> posicoes[i] - strlen(procura) + 1);
		}
	}
	if (strcmp(procura, (*raiz) -> info -> palavra) < 0) {
		return Procura_ArvAVL(&((*raiz)-> esq), procura);
	}
	if (strcmp(procura, (*raiz) -> info -> palavra) > 0) {
		return Procura_ArvAVL(&((*raiz)-> dir), procura);
	}
	// return 0;
}

void consulta_ArvAVL(char *procura, char **arquivos, int tam) {
	ArvBin *raiz = cria_ArvBin();
	FILE *l;
	char *aux = malloc(47 * sizeof(char));
	int i;
	for (i = 0; i < tam; i++) {
		l = fopen(arquivos[i], "r");
		if (!l)
			printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
		else {
			while (fscanf(l, "%s", aux) != EOF) {
				insere_ArvAVL(raiz, aux, l);
			}
			printf("%s ", arquivos[i]);
			Procura_ArvAVL(raiz, procura);
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
