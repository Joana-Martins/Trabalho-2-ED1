#include "Tabela_Hash.h"
/*Hash* criaHash(int TABLE_SIZE){
    Hash* ha=(Hash*)malloc(sizeof(Hash));
    if(ha!=NULL){
        int i;
        ha->TABLE_SIZE=TABLE_SIZE;
        ha->itens=(struct aluno**)malloc(TABLE_SIZE*sizeof(struct aluno*));
        if(ha->itens==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd=0;
        for(i=0;i<ha->TABLE_SIZE;i++) ha->itens[i]=NULL;
    }
    return ha;
}
void liberaHash(Hash* ha){
    if(ha!=NULL){
        int i;
        for(i=0;i<ha->TABLE_SIZE;i++){
            if(ha->itens[i]!=NULL) free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}
int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave&0x7FFFFFFF)%TABLE_SIZE;
}
int chaveMultiplicacao(int chave, int TABLE_SIZE){
    float A=0.6180339887;
    float val=chave*A;
    val=val-(int)val;
    return (int)(TABLE_SIZE*val);
}
int chaveDobra(int chave, int TABLE_SIZE){
    int num_bits=10;
    int parte1=chave>>num_bits;
    int parte2=chave&(TABLE_SIZE-1);
    return (parte1^parte2);
}
int valorString(char* str){
    int i, valor=7;
    int tam=strlen(str);
    for(i=0;i<tam;i++) valor=31*valor+(int)str[i];
    return valor;
}
int insereHash_SemColisao(Hash* ha, struct aluno al){
    if(ha==NULL||ha->qtd==ha->TABLE_SIZE) return 0;
    int chave=al.matricula;
    int pos=chaveDivisao(chave,ha->TABLE_SIZE);
    struct aluno* novo;
    novo=(struct aluno*)malloc(sizeof(struct aluno));
    if(novo==NULL) return 0;
    *novo=al;
    ha->itens[pos]=novo;
    ha->qtd++;
    return 1;
}
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al){
    if(ha==NULL) return 0;
    int pos=chaveDivisao(mat,ha->TABLE_SIZE);
    if(ha->itens[pos]==NULL) return 0;
    *al=*(ha->itens[pos]);
    return 1;
}*/

void FLVazia_Hash(TipoLista *Lista){
    Lista->Primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

void GeraPesos(TipoPesos p){ 
    int i, j;
    struct timeval semente;
    /* Utilizar o tempo como semente para a funcao srand() */
    gettimeofday(&semente, NULL);
    srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));
    /* Usando semente fixa para garantir resultados iguais*/
    //srand(1000);
    for (i = 0; i < N; i++)
        for (j = 0; j < TAMALFABETO; j++)
            p[i][j] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

TipoIndice h(char* Chave, TipoPesos p){
    int i; unsigned int Soma = 0;
    int comp = strlen(Chave);
    for (i = 0; i < comp; i++) Soma += p[i][(unsigned int)Chave[i]];
    return (Soma % M);
}

void Inicializa(TipoDicionario T){
    int i;
    for (i = 0; i < M; i++) FLVazia_Hash(&T[i]);
}

void Ins(char* x, TipoLista *Lista, FILE *f){
    Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> item = (Item*)malloc(sizeof(Item));
    Lista -> Ultimo -> item -> palavra = (char*)malloc(strlen(x)+1 * sizeof(char));
    strcpy(Lista -> Ultimo -> item -> palavra, x);
    Lista -> Ultimo -> item -> posicao = ftell(f);
    Lista -> Ultimo -> Prox = NULL;
}

TipoApontador Pesquisa(char* Ch, TipoPesos p, TipoDicionario T){
    /* Obs.: TipoApontador de retorno aponta para o item anterior da lista */
    TipoIndice i;
    TipoApontador Ap;
    i = h(Ch, p);
    if (Vazia(&T[i])) return NULL;  /* Pesquisa sem sucesso */
    else{
        Ap = T[i].Primeiro;
        if(Ap!= NULL){
            while(Ap->Prox->Prox!=NULL && strncmp(Ch, Ap->Prox->item->palavra, sizeof(char*)))
                Ap = Ap->Prox;
            if (!strncmp(Ch, Ap->Prox->item->palavra, sizeof(char*))) return Ap;
        }  
        else return NULL;  /* Pesquisa sem sucesso */
    }
    return NULL;
}

void Insere_Hash(char *x, TipoPesos p, TipoDicionario T, FILE *f){
    if (Pesquisa(x, p, T) == NULL) Ins(x, &T[h(x, p)],f);
}

void Imp(TipoLista* Lista){
    TipoApontador aux = Lista->Primeiro->Prox;
    while(aux!=NULL){
        printf("%.*s ", N, aux->item->palavra);
        aux = aux->Prox;
    }
}

void Imprime(TipoDicionario Tabela){
    int i;
    for(i=0;i<M;i++){
        printf("%d: ", i);
        if(!Vazia(&Tabela[i])){
            Imp(&Tabela[i]);
        }
        printf("\n");
    }
}

void busca_Hash(char **arquivos, char *procurando, int tam){
  TipoDicionario T;
  Inicializa(T);
  FLVazia_Hash(T);
  TipoPesos p;
  GeraPesos(p);
  char *aux=malloc(47*sizeof(char));
  char *palavra;
  int i;
  FILE *l;
  for(i = 0; i < tam; i++){
    l = fopen(arquivos[i], "r");
    if(!l) printf("%s ARQUIVO INEXISTENTE\n", arquivos[i]);
    else{
      while(fscanf(l, "%s", aux) != EOF){
        padroniza_Palavra(aux);
        palavra=malloc(strlen(aux)+1);
        strcpy(palavra,aux);
        Insere_Hash(palavra,p,T,l);
        free(palavra);
      }
      printf("%s ", arquivos[i]);
      Pesquisa(procurando,p,T);
      printf("\n");
      //liberdade_lista(lista);
      fclose(l);
      FLVazia_Hash(T);
    }
  }
  //liberdade_lista(lista);
  free(aux);
}
/* 
void Retira_Hash(Item x, TipoPesos p, TipoDicionario T){
    TipoApontador Ap = Pesquisa(x.palavra, p, T);
    if (Ap == NULL) printf(" Registro nao esta presente\n");
    else Ret(Ap, &T[h(x.palavra, p)], &x);
}*/
