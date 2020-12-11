// Lista o conteudo da agenda (todos os campos)
void listContacts(Contact *p)
{
    p = p->next;
    printf("Os contatos armaznados são:\n");
    if(p)
    {
        do
        {            
            printf("%s \n ", p->name);
            printf("%s \n ", p->email);
            printf("%s \n ", p->phone);
            printf("%d/%d/%d \n ", p->birth.day,p->birth.month,p->birth.year);
            printf("\n\n");
            p = p->next;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Agenda vazia.\n\n");
}