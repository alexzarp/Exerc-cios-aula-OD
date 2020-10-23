#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int x, int y){ 
   int temp;
   temp = x;
   x = y;
   y = temp;
}


void main(){
    int vet[5] = {3,27,6,4,5};
    int n=5;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    quicksort(vet, 0, n);

    printf("Valore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}