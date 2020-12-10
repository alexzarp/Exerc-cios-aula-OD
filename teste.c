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
    //x = x->next;

    snprintf(y->name, sizeof(y->name), "%s", temp->name);
    y->birth.day = temp->birth.day;
    y->birth.month = temp->birth.month;
    y->birth.year = temp->birth.year;
    snprintf(y->email, sizeof(y->email), "%s", temp->email);
    snprintf(y->phone, sizeof(y->phone), "%s", temp->phone);

    free(temp);
}
    /*Contact *temp;
    temp = x;
    x = x->next;
    y=temp;
    free(temp);*/

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



// Permite excluir um contato da agenda
void delContact (Contact *raiz, char *nomeProcurado) {
    Contact *nav = raiz->next;
    Contact *anterior = raiz;

    if (strcmp (nomeProcurado, nav->name)== 0 ) {
        raiz->next = nav->next;
        free(nav);
        return;
    }

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

void displayLL(Contact *p)
{
    p = p->next;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {            
            printf(" %s \n ", p->name);
            printf(" %s \n ", p->email);
            printf(" %s \n ", p->phone);
            printf(" %d/%d/%d \n ", p->birth.day,p->birth.month,p->birth.year);
            printf("\n\n");
            p = p->next;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
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

int main () {
    char nome[30];
    char email[40];
    char telefone[15];
    int dia, mes, ano;


    Contact *raiz = (Contact* ) malloc(sizeof (Contact));
    raiz->next = NULL;

    for (int i=0; i<6; i++){
        printf("Digite um nome ");
        scanf("%s",nome);
        /*printf("Digite um email ");
        scanf("%s",email);
        printf("Digite um telefone ");
        scanf("%s",telefone);
        printf("Digite o dia ");
        scanf("%d",&dia);
        printf("Digite o mes ");
        scanf("%d",&mes);
        printf("Digite o ano ");
        scanf("%d",&ano);*/
        insContact(raiz,nome,email,telefone,dia,mes,ano);
    }
    //displayLL(raiz);
    ordena(raiz);
    displayLL(raiz);

    char nomeProcurado[100];
    printf ("Digite o nome a ser excluido: ");
    scanf ("%s", nomeProcurado);
    delContact(raiz, nomeProcurado);

    displayLL(raiz);
    free(raiz);

    return 0;
}

