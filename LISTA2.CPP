/* PROGRAMA QUE IMPLEMENA UM LISTA DUPLAMENTE ENCADEADA
   Dados dos Autores:
   Nome : SILAS CESAR VELLINI  		Codi : 19983735
   Nome : JULIANO CESAR CANEVAROLLO  	Codi : 19983734
   Nome : EMAR ANTONIO DONADI		Codi : 19982782
   Curso: ENG. COMPUTA€ÇO */

// DECLARA€AO DAS BIBLIOTECAS
//***************************
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//***************************

// DECLARA€AO DA ESTRUTURA DO PROGRAMA (INFORMA€AOES)
//***************************
struct no        {	int info;
			struct no *prox;
			struct no *ant;
		 };
//****************************

typedef struct no *NODEPTR;   // DECLARANDO A VARIAVEL NODEPTR COMO UMA ESTRUTA (Nà)

// DECLARA€AO DOS PROTOTICOS
//****************************
void menu(void);
NODEPTR CriaLista(int x);
void InsereNoEsq(NODEPTR p,int x);
void InsereNoDir(NODEPTR p,int x);
void ListaNoEsq(NODEPTR p);
void ListaNoDir(NODEPTR p);
void RemovNoEsq(NODEPTR p);
void RemovNoDir(NODEPTR p);

//****************************
//FUNCAO MENU DO PROGRAMA
//****************************
void menu(void)
{
	textcolor(15); // cor do texto
	textbackground(0); // cor do fundo
	clrscr();
	puts("	  LISTA DUPLAMENTE ENCADEADA: Eng. Computa‡Æo - Silas Vellini\n");
	puts("                         ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	puts("                         º       MENU PRINCIPAL      º");
	puts("                         º 1. Criar a lista          º");
	puts("                         º 2. Inserir … Esquerda     º");
	puts("                         º 3. Inserir … Direita      º");
	puts("                         º 4. Remover … Esquerda     º");
	puts("                         º 5. Remover … Direita      º");
	puts("                         º 6. Remover o n¢           º");
	puts("                         º 7. Listar da Esq p/ Dir   º");
	puts("                         º 8. Listar da Dir p/ Esq   º");
	puts("                         º 9. Sair                   º");
	puts("                         ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	printf("\n   Digite uma Op‡Æo: ");
	printf("\n");
	printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	printf("³                                                                              ³");
	printf("³                                                                              ³");
	printf("³                                                                              ³");
	printf("³                                                                              ³");
	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
	printf("³MENSAGEM:						                       ³");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
}
//*******************************
// FUNCAO - CRIANDO UM LISTA (Nà)
//*******************************
NODEPTR CriaLista(int x)   // criando a lista utilizando a estrutura
{
	NODEPTR p; // declarando p utilizando a estrutura.
	p=(NODEPTR)malloc(sizeof(struct no)); // alocando espa‡o para o n¢
	p->info=x;
	p->prox=NULL; // deixando nulo o proximo de p
	p->ant=NULL; // deixando nulo o anterior de p
	return(p); // retornando o valor p
}
//********************************
// FUNCAO - INSERINDO UM ELEMENTO A ESQUERDO DO NO CRIADO.
//********************************
void InsereNoAnt(NODEPTR p, int x)
{
	NODEPTR novo, aux; // declarando as variaveis utilizando a estrutura.
	novo=(NODEPTR)malloc(sizeof(struct no)); // alocando espa‡o para a variavel novo
	novo->info=x;
	if (p->ant != NULL) // rotina de verifica‡ao
	{
		novo->prox=p;
		aux=p->ant;
		novo->ant=aux;
		aux->prox=novo;
		p->ant=novo;
	}
	else
	{
		p->ant=novo;
		novo->prox=p;
		novo->ant=NULL;
	}
}
//*******************************
// FUNCAO - INSERINDO UM ELEMENTO A DIREITA DO NO CRIADO.
//*******************************
void InsereNoDir(NODEPTR p, int x)
{
	NODEPTR novo, aux; // declarando as variaveis como a estrutura
	novo=(NODEPTR)malloc(sizeof(struct no)); // alocando espa‡o para a var. novo
	novo->info=x; // atribuindo o valor de x p/ a var. novo
	if (p->prox != NULL) // rotina de verifica‡ao
	{
		novo->ant=p;
		aux=p->prox;
		novo->prox=aux;
		aux->ant=novo;
		p->prox=novo;
	}
	else
	{
		novo->prox=NULL;
		novo->ant=p;
		p->prox=novo;
	}
}
//********************************
// FUN€AO - LISTA OS ELEMENTOS A ESQUERDA P/ DIREITA DO Nà
//********************************
void ListaNoEsq(NODEPTR p)
{
	NODEPTR aux; // declarando a var. como estrutura
	aux=p; // atribuindo valor a var. aux
	gotoxy(4,18); puts("N§s da esquerda para a direita...");
	while (aux->ant != NULL) // rotina de andamento na lista.
	{
		aux=aux->ant;
	}
	int x=4;
	do 	{ // listando os elementos.
		if (aux->prox == NULL)
		{
			gotoxy(x,20); printf("%d.",aux->info); // termina os numeros com o ponto final
			aux=aux->prox;
		}
		else
		{
			gotoxy(x,20); printf("%d,", aux->info); // termina os numeros com a virgula
			aux=aux->prox;
			x=x+5;
		}
		}   while (aux != NULL); // equando nao achar o n¢ nulo - fa‡a
}
//********************************
// FUN€AO - LISTANDO OS ELEMENTOS DA DIREITA P/ ESQUERDA DO NO
//********************************
void ListaNoDir(NODEPTR p)
{
	NODEPTR aux; // declarando a var. como a estrutura
	aux=p;
	gotoxy(4,18); puts("N§s da direita para a esquerda...");
	while (aux->prox != NULL) // enquanto o proximo do no nao for nulo - fa‡a
	{
		aux=aux->prox; // rotina de andamento da lista
	}
	int x=4;
	do{ // mostrando os elementos
		if (aux->ant == NULL)
		{
			gotoxy(x,20); printf("%d.",aux->info); // termina os numeros com o ponto final
			aux=aux->ant;
		}
		else
		{
			gotoxy(x,20); printf("%d,", aux->info); // termina os numeros com a virgula
			aux=aux->ant;
			x=x+5;
		}
	   } while (aux != NULL); // enquando aux nao for nulo  - fa‡a
}
//********************************
// FUNCAO - REMOVENDO ELEMENTO A ESQUERDA DO NO
//********************************
void RemovNoEsq(NODEPTR p)
{
	NODEPTR aux,aux2; // declarando as variveis
	aux=p->ant; // atribuindo valor a aux
	if (aux->ant != NULL) // verificando de o anterior de aux nao ‚ nulo
	{
	   aux2=aux->ant;
	   aux2->prox=p;
	   p->ant=aux2;
	}
	else // se for nulo - fa‡a
	{
		p->ant=NULL;
	}
	gotoxy(4,18); printf("O N£mero apagado a esquerda ‚ o %d", aux->info);
	free(aux); // apagando a aux
	getch(); // pausa na tela
}
//********************************
// FUNCAO - REMOVENDO ELEMENTO A DIREITA DO NO
//********************************
void RemovNoDir(NODEPTR p)
{
	NODEPTR aux,aux2; // declarando as var. como a estrutura
	aux=p->prox;
	if (aux->prox!=NULL) // verificando se o proximo de aux nao ‚ nulo
	{
		aux2=aux->prox;
		aux2->ant=p;
		p->prox=aux2;
	}
	else // se for nulo - faca
	{
		p->prox=NULL;
	}
	gotoxy(4,18); printf("O N£mero apagado a direita ‚ o %d", aux->info);
	free(aux); // apaga aux
	getch();
}
//********************************
// FUNCAO PRINCIPAL DO PROGRAMA
//********************************
void main(void)
{
	int opc,num; // declara‡ao de variaveis
	NODEPTR pont=NULL; // declara‡ao de variaveis como a estrutura
	do { // rotina do menu para nao sair da tela inicial
		menu(); // chama a funcao menu
		gotoxy(22,16);scanf("%d",& opc); // le a opcao desejada
		if (opc > 9 || opc < 1) // verificando os n§ digitados da opc
			{
				textcolor(2);
				gotoxy(12,23); cputs(" Op‡Æo Invalida!!!");
				textcolor(0);
				getch();
			}
		switch (opc) // comando que valida a opc digitada
		{
			case 1: // criar lista
			// lendo a informa‡ao a ser inserido
				if (pont==NULL)
				{
					textbackground(2);
					gotoxy(27,5); cputs(" 1. Criar Lista            ");
					textbackground(0);
					gotoxy(4,18); puts("Digite o elemento (n¢) a ser incerido:");
					gotoxy(43,18); scanf("%d", &num); // ler o elemente a ser digitado
					pont = CriaLista(num); // chama a funa‡ao crialista e atribui o resultado dela em pont
					textcolor(2);
					gotoxy(12,23); cputs("Lista Inserida com Sucesso!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textcolor(2);
					gotoxy(12,23); cputs("J  existe uma lista(n¢) cadastrado!!!");
					textcolor(0);
					getch();
				}
			break; // para o case 1
			case 2: // inserir a esquerda
				if (pont==NULL)
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe lista(n¢) cadastrada!!!");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,6); cputs(" 2. Inserir … Esquerda     ");
					textbackground(0);
					gotoxy(4,18); puts("Digite o Elemento a ser inserido:");
					gotoxy(38,18); scanf("%d", &num);
					InsereNoAnt(pont,num); // chama a funcao inserenoant com os valores pont e num
					textcolor(2);
					gotoxy(12,23); cputs("Elemento inserido com secesso!!!\a");
					textcolor(0);
					getch();
				}
			break; // para o case 2
			case 3: // inserir a direita
				if (pont==NULL)
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe lista(n¢) cadastrada!!!");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,7); cputs(" 3. Inserir … Direita      ");
					textbackground(0);
					gotoxy(4,18); puts("Digite o Elemento a ser inserido:");
					gotoxy(38,18); scanf("%d", &num);
					InsereNoDir(pont,num); // chama a funcao inserenodir com os valores pont e num
					textcolor(2);
					gotoxy(12,23); cputs("Elemento inserido com secesso!!!\a");
					textcolor(0);
					getch();
				}
			break; // para o case 3
			case 4: // remover a esquerda
				if((pont == NULL) || (pont->ant == NULL))
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe lista(n¢) a ser apagada!!!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,8); cputs(" 4. Remover … Esquerda     ");
					textbackground(0);
					RemovNoEsq(pont); // chama a funcao removnoesq , com o valor a ser removido
				}
			break; // para o case 4
			case 5: // remover a direita
				if((pont == NULL) || (pont->prox == NULL))
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe lista(n¢) a ser apagada!!!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,9); cputs(" 5. Remover … Direita      ");
					textbackground(0);
					RemovNoDir(pont); // chama a funcao removnodir , com o valor a ser removido
				}
			break; // para o case 5
			case 6: // remover o no
				if ((pont->ant != NULL) || (pont->prox != NULL)) // rotina de verifica‡ao
				{
					textcolor(2);
					gotoxy(12,23); cputs("Existe elementos Cadastrado a Dir. ou a Esq. da lista(n¢)!!!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,10); cputs(" 6. Remover o n¢           ");
					textbackground(0);
					gotoxy(4,18); printf("O N£mero da lista(n¢) a ser apagado ‚ o %d",pont->info);
					pont=NULL; // faz o var pont ser nula
					free(pont); // apaga o espa‡ao de pont
					textcolor(2);
					gotoxy(12,23); cputs("Lista(n¢) excluida com sucesso!!!\a");
					textcolor(0);
					getch();
				}
			break; // para o case 6
			case 7: // listar da esq p/ dir
				if (pont == NULL) // rotina de verifa‡ao
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe elementos a esquerda da lista(n¢)!!!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,11); cputs(" 7. Listar da Esq  p/ Dir  ");
					textbackground(0);
					ListaNoEsq(pont); // chama a funcao listanoesq com a variavel pont
					textcolor(2);
					gotoxy(12,23); cputs("Pressione qualquer tecla para continuar...");
					textcolor(0);
					getch();
				}
			break;
			case 8: // lista da dir p/ esq
				if (pont == NULL) // rotina de verifica‡ao
				{
					textcolor(2);
					gotoxy(12,23); cputs("NÆo existe elementos a direita da lista(n¢)!!!\a");
					textcolor(0);
					getch();
				}
				else
				{
					textbackground(2);
					gotoxy(27,12); cputs(" 8. Listar da Dir  p/ Esq  ");
					textbackground(0);
					ListaNoDir(pont); // chama a funcao listanodir com a var pont
					textcolor(2);
					gotoxy(12,23); cputs("Pressione qualquer tecla para continuar...");
					textcolor(0);
					getch();
				}
			break; // para o case 8
			case 9: // encerra o sistema
			char resp,flag; // declarando as var
			textbackground(2);
			gotoxy(27,13); cputs(" 9. Sair                   ");
			textbackground(0);
			textcolor(2);
			flag='V';
			while(flag=='V')
			{
				fflush(stdin);// limpa o buffer do teclado
				gotoxy(12,23); cputs("Deseja encerrar o Sistema? <S-Sim><N-NÆo>.");
				gotoxy(55,23); scanf("%c", &resp); // le a resposta do operador
				fflush(stdin); // limpa o buffer do teclado
				if (resp=='S' || resp=='s') // rotina de verifica‡ao
				{
					exit(0); //  sai do programa
				}
				if (resp=='N' || resp=='n') // rotina de verifica‡ao
				{
					flag='F';
				}
			}
			break; // para o case 9
			default: menu(); // se nao for nenhumas das opc chama a funcao menu
			break; // para o default
		}
	}while (1); // enquanto for 1 fa‡a
}
//*********************************












