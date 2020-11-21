// Permite o cadastro de um contato
void insContact (Date *MContact, char nome, char email, char telefone) {
    Contact *novoContato = (Contact *) malloc(sizeof (Contact *));
    novoContato->name = nome;
    novoContato->birth = MContact;
    novoContato->email = email;
    novoContato->phone = telefone;
    novoContato->next = NULL;
    novoContato->prev = NULL;

    Contact *agora = MContact->next;
    
// Isso se chama insetion sort
    while (agora->next) {
        for (int i = 0; i<strlen(nome); i++) {
            if (("%d",novoContato->name[i]) < ("%d", novoContato->name[i] = agora->next)) {
                
            }
        }


        agora = agora->next;
    }

    novoContato->next = agora->next;
    agora->next = novoContato;
   
}