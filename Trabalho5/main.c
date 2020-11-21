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
#include <funcionamento.h>

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
	   struct MREC *prev;
};
// Tipo criado para instanciar variaveis do tipo agenda
typedef struct MREC Contact;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=0;
    while (op!=EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
       
    }
    return op;
}

// Permite excluir um contato da agenda
void delContact ()
{
     return;
}

// Lista o conteudo da agenda (todos os campos)
void listContacts ()
{
     return;
}

// Permite consultar um contato da agenda por nome
void queryContact ()
{
     return;
}

// Permite a atualização dos dados de um contato da agenda
void upContact ()
{
     return;
}

// Programa principal
int main() {
    int op=0;

    CriaObjetoAgenda();

    /*FILE *file;
    file = fopen("agenda.uf","rb");//abrindo o arquivo somente para leitura 
    
    if (file==NULL){
        //arquivo vazio

        int tam = 20;//atribui um tamanho para o arquivo

    }
    else{

    }*/

    
    
    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : insContact();
              case 2 : delContact();
              case 3 : upContact();
              case 4 : queryContact();
              case 5 : listContacts();
          }
    }
    return 0;
}