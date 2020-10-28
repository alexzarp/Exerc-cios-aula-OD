#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//FINALIZADO
void intercala (int *vet, int inicio, int meio, int fim) {
    int tam = fim - inicio + 1;
    int i = inicio;
    int j = meio + 1;
    int *aux;
    aux = (int *) malloc(tam*sizeof(int));
    int k = 0;

    while(i<=meio && j<=fim){  
        if(vet[i] < vet[j]){
            aux[k] = vet[i];
            i++;
        }
        else{
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i<=meio){
        aux[k] = vet[i];
        k++;
        i++;

    }
    while(j<=fim){
        aux[k] = vet[j];
        k++;
        j++;

    }
       
    for (k = inicio; k<=fim; k++) {
        vet[k] = aux[k-inicio];
    }  
    free(aux);
}

void mergesort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio =floor(((inicio + fim)/2));
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, fim);
        intercala(vet, inicio, meio, fim);
    }
}

//Quando for usar esse código para testes, descomente o main.
//Caso contrário comente ele.
/*void main(){
    int vet[6] = {50,55,88,150,-7,-65};
    int n=6;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    mergesort(vet, 0, n-1);

    printf("Valores ordenados ");
    for(int q=0; q < n; q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}*/

