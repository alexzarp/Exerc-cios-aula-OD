void ordena(Contact *raiz){
    Contact *aux;

    while (raiz != NULL){
        aux = raiz->next;
        while (aux != NULL){
            if (strcmp(raiz->name,aux->name) > 0){
                swap(raiz,aux);
            }
            aux = aux->next;
        }
        raiz = raiz->next;
    }
    //Aqui deveria haver um free no aux?
}