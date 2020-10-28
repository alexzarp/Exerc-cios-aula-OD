#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mergesort (int *vet, int inicio, int fim);
void intercala (int *vet, int inicio, int meio, int fim);


void main(){
    int vet[8] = {-5,1,9,50,-6,100,150,50};
    int n=8;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    mergesort(vet, 0, n);

    printf("Valores ordenados ");
    for(int q=0;q < n; q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}

void mergesort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio =floor(((inicio + fim)/2));
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, fim);
        intercala(vet, inicio, meio, fim);
    }
}
void intercala (int *vet, int inicio, int meio, int fim) {
    int k = fim - inicio + 1;
    int i = inicio;
    int a,y;
    int j = meio + 1;
    int *tam;
    tam = (int *) malloc(k*sizeof(int));
    k=0;

    while(i<=meio && j<=fim){  
        if(vet[i] <= vet[j]){
            tam[k] = vet[i];
            i++;
        }
        else{
            tam[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        tam[k] = vet[i];
        k++;
        i++;

    }
    while(j<=fim){
        tam[k] = vet[j];
        k++;
        j++;

    }
       
    for (y = 0, a=inicio; y<k;y++, a++) {
        vet[a] = tam[y];
        //printf("vetor ordenado %d \n", vet[a]);
    }  
    free(tam);
}