#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

// Estrutura que contém os campos dos registros da agenda
struct MREC {
       char name[30];
       Date birth;
       char email[40];
       char phone[15];

	   struct MREC *next;
	   struct MREC *prev;
};
// Tipo criado para instanciar variaveis do tipo agenda
typedef struct MREC Contact;

void swap(Contact *x, Contact *y){ 
    Contact *temp = (Contact* ) malloc(sizeof (Contact));
    snprintf(temp->name, sizeof(temp->name), "%s", x->name);
    temp->birth.day = x->birth.day;
    temp->birth.month = x->birth.month;
    temp->birth.year = x->birth.year;
    snprintf(temp->email, sizeof(temp->email), "%s", x->email);
    snprintf(temp->phone, sizeof(temp->phone), "%s", x->phone);

    snprintf(x->name, sizeof(x->name), "%s", y->name);
    x->birth.day = y->birth.day;
    x->birth.month = y->birth.month;
    x->birth.year = y->birth.year;
    snprintf(x->email, sizeof(x->email), "%s", y->email);
    snprintf(x->phone, sizeof(x->phone), "%s", y->phone);

    snprintf(y->name, sizeof(y->name), "%s", temp->name);
    y->birth.day = temp->birth.day;
    y->birth.month = temp->birth.month;
    y->birth.year = temp->birth.year;
    snprintf(y->email, sizeof(y->email), "%s", temp->email);
    snprintf(y->phone, sizeof(y->phone), "%s", temp->phone);

    free(temp);
}

int contagem(Contact *raiz) {
    raiz = raiz->next;
    int contagem = 0;

    while (raiz) {
        contagem++;
    }

    return contagem;
}

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

// Permite consultar um contato da agenda por nome
void queryContact (char chave, Contact *raiz) {
    int cima, meio, baixo;

    int ultimo = contagem (raiz);
    

}

// Permite excluir um contato da agenda
void delContact (Contact *raiz, char *nomeProcurado) {
    Contact *nav = raiz->next;

    if (strcmp (nomeProcurado, nav->name)== 0) {
        raiz->next = nav->next;
        free(nav);
        return;
    }

    Contact *anterior = raiz;

    while (nav->next) {
        anterior = nav;
        nav = nav->next;
        if (strcmp (nomeProcurado, nav->name) == 0) {
            break;
        }
    }
    anterior->next = nav->next;
    nav->next = NULL;
    free(nav);
}

void listContacts(Contact *p) {
    p = p->next;
    printf("\nOs contatos armaznados são:\n");
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

void ordena(Contact *raiz){
    Contact *aux;

    while (raiz != NULL){
        aux = raiz->next;
        while (aux != NULL){
            if (strcmp(raiz->name,aux->name) > 0){
                swap(raiz,aux);
            }

            aux = aux->next;
        }
        raiz = raiz->next;
    }    
}

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
                setbuf(stdin,NULL);
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

int main () {
    char nome[100];
    char email[40];
    char telefone[15];
    int dia, mes, ano;


    Contact *raiz = (Contact* ) malloc(sizeof (Contact));
    raiz->next = NULL;

    for (int i=0; i<2; i++){
        printf("Digite um nome ");
        //fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%[^\n]",nome);
        printf("Digite um email ");
        scanf("%s",email);
        printf("Digite um telefone ");
        scanf("%s",telefone);
        printf("Digite o dia/mes/ano separado por espaço ");
        scanf("%d %d %d",&dia, &mes, &ano);
        /*printf("Digite o mes ");
        scanf("%d",&mes);
        printf("Digite o ano ");
        scanf("%d",&ano);*/
        insContact(raiz,nome,email,telefone,dia,mes,ano);
    }
    //listContacts(raiz);
    ordena(raiz);
    listContacts(raiz);

    char nomeProcurado[100];
    printf ("Digite o nome a ser alterado: ");
    setbuf(stdin,NULL);
    scanf ("%[^\n]", nomeProcurado);
    //delContact(raiz, nomeProcurado);
    upContact(raiz, nomeProcurado);
    printf("nome %s ", nomeProcurado);
    
    listContacts(raiz);
    free(raiz);

    return 0;
}

