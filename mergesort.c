#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mergesort (int *vet, int inicio, int fim);
void intercala (int *vet, int inicio, int meio, int fim);

/*void main(){
    int vet[8] = {-5,1,9,50,-6,100,7,50};
    int n=8;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    mergesort(vet, 0, n);

    printf("Valore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}*/

void mergesort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio =floor(((inicio + fim)/2));
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, fim);
        intercala(vet, inicio, meio, fim);
    }
}
void intercala (int *vet, int inicio, int meio, int fim) {
    int aux = fim - inicio + 1;
    int  i = inicio;
    int a;
    int j = meio + 1;
    int p1 = 0, p2 = 0;
    int *k;
    k = (int *) malloc(aux*sizeof(int));

    if(k != NULL){  
        for(int x = 0; x<aux; x++){
            if (!p1 && !p2) {
                if(vet[i] < vet[j]){
                    k[x] = vet[i++];
                }
                else{
                    k[x] = vet[j++];
                }
                if(i>meio) p1=1;
                if(j>fim) p2=1;
            }
            else{
                if(!p1){
                    k[x] = vet[i++];
                }else{  
                    k[x] = vet[j++];
                }
            }
        
    
        }

    for (j = 0, a=inicio; j<aux;j++, a++) {
        vet[a] = k[j];
        }
    }
    free(k);
}