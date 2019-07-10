#include "Tabela_Hash.h"

void FLVazia(TipoLista *Lista)
{ Lista->Primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro; Lista->Primeiro->Proximo = NULL;
}

void Inicializa_Hash(TipoDicionario Hash){
    for (int i = 0; i < TAM_MAX; i++) FLVazia(&Hash[i]);
}

void Gera_Pesos(TipoPesos pesos){
    struct timeval semente;
    gettimeofday(&semente, NULL);
    srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < TAMALFABETO; j++)
            pesos[i][j] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

int Funcao_Hash(char* Palavra, TipoPesos Pesos){
    int i;
    unsigned int Soma = 0;
    for (i = 0; i < strlen(Palavra); i++) Soma = Soma + Pesos[i][(unsigned int)Palavra[i]];
    return (Soma % TAM_MAX);
}

void Insere_Hash(char* Palavra, TipoPesos Pesos, TipoDicionario Hash, FILE *Arquivo){
    int Posicao=Funcao_Hash(Palavra,Pesos);
    Insere_Lista(Palavra,&Hash[Posicao],Arquivo);
}

void Procura_Hash(char* Palavra, TipoPesos Pesos, TipoDicionario Hash){
    int Posicao=Funcao_Hash(Palavra,Pesos);
    TipoLista* Lista=&Hash[Posicao];
    Procura_Lista(Palavra,Lista);
}

void Desaloca_Hash(TipoDicionario Hash){
    for (int i = 0; i < TAM_MAX; i++){
        if(Lista_Vazia(&Hash[i])) Desaloca_Lista(&Hash[i]);
    }
}

void Busca_Hash(char **Arquivos, char *Procura, int qtdArquivos){
    TipoDicionario Hash;
    Inicializa_Hash(Hash);
    TipoPesos Pesos;
    Gera_Pesos(Pesos);
    char *aux=malloc(47*sizeof(char));
    char *Palavra;
    FILE *Arquivo;
    for(int i = 0; i < qtdArquivos; i++){
        Arquivo = fopen(Arquivos[i], "r");
        if(!Arquivo) printf("%s ARQUIVO INEXISTENTE\n", Arquivos[i]);
        else{
        while(fscanf(Arquivo, "%s", aux) != EOF){
            padroniza_Palavra(aux);
            Palavra=malloc(strlen(aux)+1);
            strcpy(Palavra,aux);
            Insere_Hash(Palavra,Pesos,Hash,Arquivo);
            free(Palavra);
        }
      printf("%s ", Arquivos[i]);
      Procura_Hash(Procura,Pesos,Hash);
      Desaloca_Hash(Hash);
      fclose(Arquivo);
      Inicializa_Hash(Hash);
    }
  }
  Desaloca_Hash(Hash);
  free(aux);
}
