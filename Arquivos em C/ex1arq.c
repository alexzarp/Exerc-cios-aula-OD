#include <stdio.h>
#include <ctype.h>

int main () {
    FILE *file;
    char string[1000];
    int i;
    
    file = fopen("text.txt", "rt");
    if (file == NULL) {
        printf ("Não funcionou, programa sendo finalizado na linha 11.");
        return 1;
    }

    for (i = 0; i < 1000; i++) {
        fscanf (file, "%c", &string[i]);
    }
    fclose(file);

    file = fopen("texto.wtr", "wt");
    if (file == NULL) {
        printf ("Não funcionou, programa sendo finalizado na linha 20.");
        return 1;
    }

    for (i = 0; i < 1000; i++) {
        fprintf (file, "%c", toupper(string[i]));
    }
    fclose(file);
    
    return 0;
}