void ordena(Contact *raiz){
    Contact *aux;
    char s[100];

    while (raiz != NULL){
        aux = raiz->next;
        while (aux != NULL){
            if (strcmp(raiz->name,aux->name) > 0){
                strcpy(s, raiz->name);
                strcpy(raiz->name, aux->name);
                strcpy(aux->name,s);
            }

            aux = aux->next;
        }
        raiz = raiz->next;
    }    
}




//função de insertion sort com lista simplesmente encadeada
/*void insertionSort(Contact *raiz){
    Contact *i,*j,*next,*name;
    for (i = raiz->next; i!= NULL; i = i->next){
    }

}*/



/*void insertionSort(Lista *lista){
    ItemLista *i, *j, *elemento, *aux, *aux2;

    for (i=lista->head->next; i != NULL; i = i->next){
        for(j = i->prev; j != NULL; j = j->prev ){
            if (j->valor < i->valor){
                if (j == i->prev){
                    break;
                }
                aux = i->prev; //anterior do atual
                swap (lista, j, i); //troca os dois elementos
                i = aux;
                break;
            }        
        }
        if (j == NULL){ //foi até a cabeça da lista

            aux = i->prev;
            swap(lista, NULL, i);
            i = aux;
        } 

    }/*