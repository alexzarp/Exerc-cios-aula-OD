void upContact (Contact *raiz, char *nomeProcurado) {
    printf("entrou");
    raiz = raiz->next;//vai para o primeiro elemento
    char chave[30];
    char info[100];
    int info_int, info_int1, info_int2;

    while (raiz != NULL) {
        if (strcmp (nomeProcurado, raiz->name) == 0) {
            //listContacts(raiz);
            printf("\nDeseja atualizar o nome? [y or n]: ");
            scanf("%s", chave);
            if (strcmp(chave, "y") == 0)  {
                printf("Digite o novo nome: ");
                setbuf(stdin,NULL);
                scanf("%[^\n]",info);
                //setbuf(stdin,NULL);
                snprintf(raiz->name, sizeof(raiz->name), "%s", info);
            }

            printf("\nDeseja atualizar o email? [y or n]: ");
            scanf("%s", chave);
            if (strcmp(chave, "y") == 0) {
                printf("Digite o novo email: ");
                scanf("%s",info);
                snprintf(raiz->email, sizeof(raiz->email), "%s", info);
            }
            
            printf("\nDeseja atualizar o telefone? [y or n]: ");
            scanf("%s", chave);
            if (strcmp(chave, "y") == 0)  {
                printf("Digite o novo telefone: ");
                scanf("%s",info);
                snprintf(raiz->phone, sizeof(raiz->phone), "%s", info);
            }

            printf("\nDeseja atualizar a data de aniversário? [y or n]: ");
            scanf("%s", chave);
            if (strcmp(chave, "y") == 0)  {
                printf("Digite a data dia/mes/ano, separado apenas por espaço: ");
                scanf("%d %d %d",&info_int, &info_int1, &info_int2);
                raiz->birth.day = info_int;
                raiz->birth.month = info_int1;
                raiz->birth.year = info_int2;
            }

            printf("\nDados atualizados\n");
            printf("Nome: %s\n", raiz->name);
            printf("Email: %s\n", raiz->email);
            printf("Telefone %s\n", raiz->phone);
            printf("Data de nascimento %d/%d/%d\n", raiz->birth.day, raiz->birth.month, raiz->birth.year);
            return;
        }

        raiz = raiz->next;
    }
}