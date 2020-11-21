#include<stdio.h>
#include<stdlib.h>

void abreArquivo(){

    FILE *file;
    file  = fopen("agenda.txt","w+");
    
    if (file == NUll){
        printf("Não está abrindo \n")
        return 1;
    }



    fclose(file);

}