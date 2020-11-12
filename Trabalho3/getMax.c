int getMax(int *vet, int n) { 
    int aux = vet[0]; 
    for (int i = 1; i < n; i++) 
        if (vet[i] > aux) 
            aux = vet[i]; 
    return aux; 
} 