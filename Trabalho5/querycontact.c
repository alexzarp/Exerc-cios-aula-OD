// Permite consultar um contato da agenda por nome
int queryContact (Contact *raiz, char *nomeProcurado, int n) {
    int ativacao = 0;
    raiz = raiz->next;

    while (raiz != NULL) {
        if (strncmp (raiz->name, nomeProcurado, n) == 0) {
            printf("\nNome: %s\n", raiz->name);
            printf("Email: %s\n", raiz->email);
            printf("Telefone: %s\n", raiz->phone);
            printf("Data de nascimento: %d/%d/%d\n", raiz->birth.day, raiz->birth.month, raiz->birth.year);
            ativacao = 1;
        }

        if ((ativacao == 1) && (strncmp (raiz->name, nomeProcurado, n) != 0)) {
            break;
        }
        raiz = raiz->next;
    }
        
}