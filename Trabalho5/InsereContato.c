// Permite o cadastro de um contato
void insContact (Date *MContact, char *nome, char *email, char *telefone, Lista *lista) {
    Contact *novoContato = malloc(sizeof (Contact));
    
    snprintf(novoContato->name, sizeof(novoContato->name), "%s", nome);
    novoContato->birth = *MContact;
    snprintf(novoContato->email, sizeof(novoContato->email), "%s", email);
    snprintf(novoContato->phone, sizeof(novoContato->phone), "%s", telefone);
    novoContato->next = NULL;
    novoContato->prev = NULL;

    Contact *agora = lista->head;
    
// Isso se chama insetion sort
    do {
        if (strcmp(novoContato->name, agora->name) == (-1 || 0)) {
            //insere antes do atual

            novoContato->next = agora;
            agora->prev->next = novoContato;
            novoContato->prev = agora->prev;
            agora->prev = novoContato;
            
            break;
        }

        else  {
            //vai para o proximo
            agora = agora -> next;
        }
    } while (agora != NULL);

} 