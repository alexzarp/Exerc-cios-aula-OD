// Permite excluir um contato da agenda
void delContact (Contact *raiz) {
    int digito, contador = 0;
    
    Contact *aux = raiz->next;
    Contact *nav = raiz->next;
    Contact *anterior = raiz;

    while (aux->next) {
        contador++;
        printf("%d - %s\n", contador, aux->name);
    }

    printf("Por favor digite o número correspondente a pessoa\nque você deseja excluir: ");
    scanf("%d", &digito);
    contador = 0;

    while (nav->next) {   
        contador++;
        anterior = nav;
        nav = nav->next;

        if (contador == digito) {
            break;
        }
    }

    anterior->next = nav->next;
    nav->next = NULL;
    free(nav);
}