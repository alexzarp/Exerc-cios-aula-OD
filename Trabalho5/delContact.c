// Permite excluir um contato da agenda
void delContact (Contact *raiz, char *nomeProcurado) {
    Contact *nav = raiz->next;

    if (strcmp (nomeProcurado, nav->name)== 0) {
        raiz->next = nav->next;
        free(nav);
        return;
    }

    Contact *anterior = raiz;

    while (nav->next) {
        anterior = nav;
        nav = nav->next;
        if (strcmp (nomeProcurado, nav->name) == 0) {
            break;
        }
    }
    anterior->next = nav->next;
    nav->next = NULL;
    free(nav);
}