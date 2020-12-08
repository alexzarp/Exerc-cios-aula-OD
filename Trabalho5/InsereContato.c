// Permite o cadastro de um contato
void insContact (Contact *raiz, char *nome, char *email, char *telefone, int *dia, int *mes, int ano) {
    Contact *novoContato = (Contact* ) malloc(sizeof (Contact));
    snprintf(novoContato->name, sizeof(novoContato->name), "%s", nome);
    novoContato->birth.day = dia;
    novoContato->birth.month = mes;
    novoContato->birth.year = ano;
    snprintf(novoContato->email, sizeof(novoContato->email), "%s", email);
    snprintf(novoContato->phone, sizeof(novoContato->phone), "%s", telefone);

    Contact *nav = raiz->next;

    int posicao = strcmp(novoContato->name, nav->name);
// Isso se chama insetion sort
    do {
        if (strcmp(novoContato->name, nav->name) == -1) {  
            break;
        }

        else if (strcmp(novoContato->name, nav->name) == 0){
            break;
        }

        nav = nav->next;

    } while (nav != NULL);

    novoContato->next = nav->next;
    nav->next = novoContato;
} 