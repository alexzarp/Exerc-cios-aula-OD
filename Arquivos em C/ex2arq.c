#include <stdio.h>
#include <string.h>
//meu programa conta -1, não imagino qual seja o erro lógico
int main () {
    FILE *file;
    char string[1000];
    char nome[20];
    int i, j, conta_letras;
    
    printf("Qual o nome do arquivo? ");
    scanf("%s", nome);
    
    file = fopen(nome, "rt");
    if (file == NULL) {
        printf ("Não funcionou, programa sendo finalizado na linha 15.\n");
        return 1;
    }

    for (i = 0; i < 1000; i++) {
        fscanf (file, "%c", &string[i]);
    }
    

    for (i = 0; i <= strlen(string); i++) {
        if ((string[i] == ' ' || string[i] == '\n') && string[i-1] != ' ' && string[i+1] != ' ') {
            conta_letras++;
        }
    }
    
    printf ("Haviam %d palavras nesse arquivo\n", conta_letras);
    fclose(file);
    return 0;
}