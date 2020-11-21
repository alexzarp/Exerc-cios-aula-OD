void CriaObjetoAgenda () {
    Contact *MContact = (Contact *) malloc(sizeof(Contact *));
    MContact->name = NULL;
    MContact->birth = NULL;
    MContact->email = NULL;
    MContact->phone = NULL;
    MContact->prev = NULL;
    MContact->next = NULL;
}