/*
 Este é um esqueleto que deve ser utilzado como base para implementação da Agenda.
	- As funções não tem os parâmetros definidos e os parâmetros caso necessários, devem ser incluídos.
    - Caso seja necessário novas funções podem ser incluídas
 	- Devem ser respeitados os nomes dados mara o métodos e estruturas, porém novas estruturas e funções podem ser criados, caso julgue necessário
	- Faça os includes necessários
	- A organização das funções fica a critério do programador
	- Códigos não identados sofrerão duras penalidades
	- Não serão toleradas variaveis globais
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/
#include "funcionamento.h"

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
//Representa o nascimento da pessoa.
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
	   //struct MREC *prev; Fizemos uma lista simplesmente encadeada.
};
// Tipo criado para instanciar variaveis do tipo agenda
typedef struct MREC Contact;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu() {
    int op=0;
    while (op != EXIT) {
        printf("Para finalizar o programa e salvar automaticamente, digite %d e tecle enter. E da mesma forma tecle:\n",EXIT);
        printf("1 - Para inserir um novo contato;\n");
        printf("2 - Para deletar um contato existente;\n");
        printf("3 - Para atualizar um contato existente;\n");
        printf("4 - Para pesquisar contatos;\n");
        printf("5 - Para listar todos os contatos contidos na memória.\n");
        scanf("%d",&op);
    }
    return op;
}

// Programa principal
int main() {
    int op=0;

    char nome[30];
    char email[40];
    char telefone[15];
    int dia, mes, ano;

    char nomeProcurado[30];
    int n = 0;

    Contact *raiz = (Contact*) malloc(sizeof (Contact));
    raiz->next = NULL;
    /*FILE *arquivo;
    arquivo = fopen("agenda.ab","rb");
    //se for igual a null arquivo vazio

    if (arquivo == NULL){
        arquivo = fopen("agenda.ab","wb");
        
    } else {
        arquivo = fopen("agenda.ab", "rb");
        
        Contact *aux = malloc (sizeof(Contact));

        while (fread(aux, sizeof(aux), 1, fileOrigem) > 0){
            aux->next = NULL;
    
            if (headLista == NULL) //verifica se vai ser o primeiro
                headLista = aux;

            if (ultimo == NULL)  //controla o ultimo para encadear
                ultimo = aux;
            else{
                ultimo->next = aux;
                ultimo = aux;
            }
            aux = malloc (sizeof(Pessoa));
        }
    }*/

    
    while (op != EXIT) {       
        op=menu();
        switch(op) {
            case 1:
                printf("Digite um nome ");
                setbuf(stdin,NULL);
                scanf("%[^\n]",nome);
                printf("Digite um email ");
                scanf("%s",email);
                printf("Digite um telefone ");
                scanf("%s",telefone);
                printf("Digite o dia/mes/ano separado por espaço ");
                scanf("%d %d %d",&dia, &mes, &ano);
                insContact(raiz, nome, email, telefone, dia, mes, ano);

            case 2:
                printf("Digite o nome completo da pessoa que deseja excluir,\npor exemplo, Gabriel Lima da Silva: ");
                setbuf(stdin,NULL);
                scanf("%[^\n]",nomeProcurado);
                delContact(raiz, nomeProcurado);

            case 3:
                printf("Digite o nome completo da pessoa que deseja atualizar,\npor exemplo, Gabriel Lima da Silva: ");
                setbuf(stdin,NULL);
                scanf("%[^\n]",nomeProcurado);
                upContact(raiz, nomeProcurado);

            case 4:
                printf("Digite o nome que seja buscar na agenda,\npor exemlo Gabriel, joão Lima ou PEDRO SANTOS");
                setbuf(stdin,NULL);
                scanf("%[^\n]",nomeProcurado);
                n = strlen(nomeProcurado);
                queryContact(raiz, nomeProcurado, n);

            case 5:
                listContacts(raiz);
        }
        ordena(raiz);
    }
    free(raiz);
    return 0;
}