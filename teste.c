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
   Contact temp;
   temp=*x;
   *x=*y;
   *y=temp;
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

// Permite excluir um contato da agenda
void delContact (Contact *raiz, char *nomeProcurado) {
    Contact *nav = raiz->next;
    Contact *anterior = raiz;

    while (nav) {
        anterior = nav;
        if (strcmp (nomeProcurado, nav->name) == 0) {
            break;
        }
        nav = nav->next;
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
    Contact *i,*j, *fim = NULL;
   
    if (raiz->next == NULL) {
        return;
    }

    for (i = raiz->next; i->next != NULL; i = i->next) {
        for (j = raiz->next; j->next != fim; j = j->next) {
            if (strcmp (i->name, j->name) > 0) {
                swap(i,j);
            }
        }
        fim = j;
    }
    /*while (b) {
        b = b->next;
        while (a) {
            if (strcmp(a->name,b->name) > 0){
                swap(a, b);
   
            }

            b = b->next;
        }
        a = a->next;
    }
    printf("entrou");*/
}

int main () {
    char nome[30];
    char email[40];
    char telefone[15];
    int dia, mes, ano;


    Contact *raiz = (Contact* ) malloc(sizeof (Contact));
    raiz->next = NULL;

    for (int i=0; i<4; i++){
        printf("Digite um nome ");
        scanf("%s",nome);
        printf("Digite um email ");
        scanf("%s",email);
        printf("Digite um telefone ");
        scanf("%s",telefone);
        printf("Digite o dia ");
        scanf("%d",&dia);
        printf("Digite o mes ");
        scanf("%d",&mes);
        printf("Digite o ano ");
        scanf("%d",&ano);
        insContact(raiz,nome,email,telefone,dia,mes,ano);
    }
    displayLL(raiz);

    ordena(raiz);
    displayLL(raiz);
    /*char nomeProcurado[100];
    printf ("Digite o nome a ser excluido: ");
    scanf ("%s", nomeProcurado);
    delContact(raiz, nomeProcurado);

    displayLL(raiz);*/
    free(raiz);

    return 0;
}

