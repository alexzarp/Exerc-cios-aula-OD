#include <stdio.h>

void radixSort(int v[], int n);
void countingSort(int v[], int p, int n);
int buscaMax(const int v[], int n);

int buscaMax(const int v[], int n){
    int maior = v[0];
    
    for(int i; i<n; i++){
        
        if(v[i]>maior){
            maior = v[i];
        }
    }
    return maior;

}
void countingSort(int v[], int p, int n){
    int aux = (v[0]/ p) % 10;
    int cont[n+1];
    
    for(int i; i<n; i++){
        if(((v[i]/p) % 10) > aux){
            aux = v[i];
        }
    }
    int contagem[aux + 1];
    
    for(int j=0; j < aux; j++){
        contagem[j] = 0;
    }
    for(int i=0; i < n; i++){
        contagem[((v[i]/p) % 10)]++;
    }
    for (int i=1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }
    for (int i=n-1; i >= 0; i--) {
        cont[contagem[(v[i] / p) % 10] - 1] = v[i];
        contagem[(v[i] / p) % 10]--;
    }
    for (int i=0; i < n; i++) {
        v[i] = cont[i];
    }
}
void radixSort(int v[], int n){
    int max = buscaMax(v,n);
    
    for(int i = 1; max/i > 0; i*=10){
        countingSort(v,i,n);
    }

}
int main(int argc, char const *argv[])
{
    /*int vet[4] = {5,3,10,8};
    int n=4;

    /*printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
    }
    
    //printf("\n");

    radixSort(vet,n);

    printf("Valores ordenados ");
    for(int q=0; q < n; q++){
        printf("%d ",vet[q]);
    }
    printf("\n");*/
    int vetor[5] = {5,4,3,2,1};
	int n = 5;

	radixSort(vetor, n-1);

	for(int i = 0;i < 5; i++){
		printf("%d  ",vetor[i]);
	}
	printf("\n");
    return 0;
}
