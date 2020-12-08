#include<stdio.h>
#include<stdlib.h>

FILE* ArquivoParaLeitura(){
    FILE* arquivo = fopen("arquivo.tr","r+b");

    if (arquivo == NULL){
        return "Arquivo vazio";
    }else{
        return arquivo;
    }

}