// Permite o cadastro de um contato
void insContact (Contact *raiz, char *nome, char *email, char *telefone, int dia, int mes, int ano) {
    
    Contact *novoContato = (Contact* ) malloc(sizeof (Contact));
    snprintf(novoContato->name, sizeof(novoContato->name), "%s", nome);
    novoContato->birth.day = dia;
    novoContato->birth.month = mes;
    novoContato->birth.year = ano;
    snprintf(novoContato->email, sizeof(novoContato->email), "%s", email);
    snprintf(novoContato->phone, sizeof(novoContato->phone), "%s", telefone);

    novoContato->next = raiz->next;
    raiz->next = novoContato;
}