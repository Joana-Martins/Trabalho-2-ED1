#include "Padroniza_Palavra.h"

void padroniza_Palavra(char* palavra){
  for(int i=0;i<strlen(palavra);i++){
    if((palavra[i]>=' ' && palavra[i]<='@')||(palavra[i]>='[' && palavra[i]<='`')||(palavra[i]>='{' && palavra[i]<='~')){
      palavra[i]=palavra[i+1];
    }
  }
  for(int i=0;i<strlen(palavra);i++){
    if(palavra[i]>='A' && palavra[i]<='Z') palavra[i]=palavra[i]+32;
  }
}