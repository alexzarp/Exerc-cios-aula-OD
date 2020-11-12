#include <stdio.h>
#include <time.h>
#include "radixsort.c"
#include "geravet.c"

void main () {
    int n;
    int num = 10000;
    clock_t start,end;
    double difTempo;
    int tipovet;

    printf("Ok, agora escolha o tamanho do vetor a ser usado?\n");
    scanf("%d", &n);
    printf("\n");
    int vet[n];
    printf("Escolha agora o tipo de vetor.\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    scanf("%d", &tipovet);
    printf("\n");
    escolheTipoVet (tipovet, vet, n, num);

    //print(vet, n, 0);

    start = clock();
    
    radixsort(vet,n);
    
    end = clock();

    print(vet, n, 1);

    difTempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",difTempo);
    printf("Tempo(ms): %lf\n",difTempo*1000);
}

