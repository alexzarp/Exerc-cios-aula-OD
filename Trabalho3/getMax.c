int getMax (int *vet, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] > max) {
            max = vet[i];
        }
    }

    return max;
}
