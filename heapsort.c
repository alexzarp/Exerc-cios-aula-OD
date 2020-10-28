#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "swap.c"













//Quando for usar esse código para testes, descomente o main.
//caso contrário comente ele.
void main(){
    int vet[8] = {-5,1,9,40,-6,29,7,32};
    int n=8;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    //mergesort(vet, 0, n);

    printf("Valore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}
//---------------------------------------------------

