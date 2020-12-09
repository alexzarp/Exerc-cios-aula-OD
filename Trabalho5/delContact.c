// Permite excluir um contato da agenda
void delContact (Contact *raiz, char *nomeProcurado) {
    Contact *nav = raiz->next;
    Contact *anterior = raiz;

    while (nav) {
        anterior = nav;
        if (strcmp (nomeProcurado, nav->name) == 0) {
            break;
        }
        nav = nav->next;
    }
    anterior->next = nav->next;
    nav->next = NULL;
    free(nav);
}