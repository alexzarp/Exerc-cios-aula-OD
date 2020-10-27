#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mergesort.h>
#include <quicksort.h>
//#include <>

void main(){
    int n;
    int num = 1000000;
    clock_t start,end;
    double difTempo;
    int metodo;
    int tipovet;

    printf("Qual método de ordenção usar?\n1 - BubbleSort\n2 - InsertionSort\n3 - SelectionSort\n");
    scanf("%d", &metodo);
    printf("\n");
    printf("Ok, agora escolha o tamanho do vetor a ser usado?\n");
    scanf("%d", &n);
    printf("\n");
    int vet[n];
    printf("Escolha agora o tipo de vetor.\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &tipovet);
    printf("\n");
    escolheTipoVet (tipovet, vet, n, num);

    if (metodo == 1) {
        
        start = clock();
        bubble_sort(vet, n);  
    }
    else if (metodo == 2) {
    
        start = clock();
        insertionsort(vet, n);
    }
    else if (metodo == 3) {
        
        start = clock();
        selectionsort (vet, n);
    }
    
    end = clock();

    printf("\nValore ordenados ");
   /* for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");*/

    difTempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",difTempo);
    printf("Tempo(ms) %lf\n",difTempo*1000);
}