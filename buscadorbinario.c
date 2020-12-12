int queryContact (Contact *raiz, char nomeProcurado) {
    Contact *primeiro, *meio, *ultimo;
    int inicio = 0, centro = 0, fim = 0;
    int centro_while;

    primeiro = raiz->next;
    meio = raiz->next;
    ultimo = raiz->next;

    while (ultimo != NULL) {
        fim++;
        ultimo = ultimo->next;
    }

    centro = (inicio + fim)/2;

    while (meio != NULL) {

        if () {
            return meio->name;
        }

        meio = meio->next;
        centro++;
    }

}