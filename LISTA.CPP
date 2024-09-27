//TRABALHO DE ESTRUTURA DE DADOS
//ALUNO: DANIEL MEIRELES DO RÒGO
//COD: 19990135
//ENGENHARIA DE COMPUTA€ÇO NOTURNO - 2§ ANO
//EXERCÖCIO CRIAR E MANIPULAR LISTA


//declara‡Æo das bibliotecas
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//Defini‡Æo da estrutura
struct node{
		   int info;
		   struct node *prox;
		   struct node *ant;};
typedef struct node *NODEPTR;

//Prototipos
void menu(void);
NODEPTR crialista(int x);
void insereNoEsq(NODEPTR p, int x);
void insereNoDir(NODEPTR p, int x);
void escreveEsqDir(NODEPTR p);
void escreveDirEsq(NODEPTR p);
void removeEsq(NODEPTR p);
void removeDir(NODEPTR p);

//Fun‡Æo case2 Inserir um elemento … esquerda
void insereNoEsq(NODEPTR p, int x)
{
	NODEPTR novo, aux;
	novo=(NODEPTR)malloc(sizeof(struct node));
	novo->info=x;
	if (p->ant!=NULL)
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

//Fun‡Æo case3 Inserir um elemento … Direita
void insereNoDir(NODEPTR p, int x)
{
	NODEPTR novo, aux;
	novo=(NODEPTR)malloc(sizeof(struct node));
	novo->info=x;
	if (p->ant!=NULL)
	{
		novo->ant=p;
		aux=p->prox;
		novo->prox=aux;
		aux->ant=novo;
		p->prox=novo;
	}
	else
	{
		p->prox=novo;
		novo->ant=p;
		novo->prox=NULL;
	}
}


//Fun‡Æo case7 Listar da Esquerda para Direita
void EscreveEsqDir(NODEPTR p)
{
	NODEPTR aux;
	aux=p;
	while(aux->ant!=NULL)
	{
		aux=aux->ant;
	}
	while (aux->prox!=NULL)
	{
		printf("%5d",aux->info);
		aux=aux->prox;
	}
	printf("%5d",aux->info);
}

//Fun‡Æo case8 Listar da Direita para Esquerda
void EscreveDirEsq(NODEPTR p)
{
	NODEPTR aux;
	aux=p;
	while(aux->prox!=NULL)
	{
		aux=aux->prox;
	}
	while (aux->ant!=NULL)
	{
		printf("%5d",aux->info);
		aux=aux->ant;
	}
	printf("%5d",aux->info);
}

//Fun‡Æo case4 Remove elemento … Esquerda
void removeEsq(NODEPTR p)
{
	NODEPTR aux1, aux2;
	if (p->ant==NULL)
	{
		puts("          NÆo tem nada desse lado ....");
		getch();
	}
	else
	{
		aux1=p->ant;
		if (aux1->ant==NULL)
		{
			p->ant=NULL;
			aux1->prox=NULL;
			free(aux1);
		}
		else
		{
			aux2=aux1->ant;
			p->ant=aux2;
			aux2->prox=p;
			aux1->ant=NULL;
			aux1->prox=NULL;
			free(aux1);
		}
	}
}

//Fun‡Æo case5 Remove elemento … Direita
void removeDir(NODEPTR p)
{
	NODEPTR aux1, aux2;
	if (p->prox==NULL)
	{
		puts("          NÆo tem nada desse lado ....");
		getch();
	}
	else
	{
		aux1=p->prox;
		if (aux1->prox==NULL)
		{
			p->prox=NULL;
			aux1->ant=NULL;
			free(aux1);
		}
		else
		{
			aux2=aux1->prox;
			p->ant=aux2;
			aux2->ant=p;
			aux1->prox=NULL;
			aux1->ant=NULL;
			free(aux1);
		}
	}
}



//Cria menu
void menu()
{
puts("               Menu                          ");
puts("          1.criar lista                      ");
puts("          2.inserir a esquerda               ");
puts("          3.inserir a direita                ");
puts("          4.remover a esquerda               ");
puts("          5.remover a direita                ");
puts("          6.remover ponteiro                 ");
puts("          7.listar de esquerda para direita  ");
puts("          8.listar de direita para a esquerda");
puts("          9.sair                             ");
printf("          --> Digite uma op‡Æo:");
}


void main(void)
{
clrscr();

//Declara‡Æo das Vari veis
int opcao;
NODEPTR pont=NULL;
int num;

do{

//Desenhando Menu
clrscr();
menu();

//Lendo op‡Æo
scanf("%d",&opcao);
switch(opcao){
	case 1://criar lista
		   //ler informa‡Æo a ser inserida
		   //pode-se criar apenas se pont=NULL
		   if (pont==NULL){
				printf("          Digite o elemento a ser inserido:");
				scanf("%d",&num);
				pont=crialista(num);
		   }
		   else{
				printf("          J  existe uma lista, besta! Tecle algo...");
				getch();
		   }
	break;
	case 2://inserir a esquerda
		   if (pont!=NULL){
				printf("          Digite um n§:");
				scanf("%d",&num);
				insereNoEsq(pont,num);
		   }
		   else{
				printf("          Lista vazia sua anta.....aperte qq coisa");
				getch();
		   }
	break;
	case 3://inserir a direita
		   if (pont!=NULL){
				printf("          Digite um n§:");
				scanf("%d",&num);
				insereNoDir(pont,num);
		   }
		   else{
				printf("          Lista vazia sua anta.....aperte qq coisa");
				getch();
		   }
	break;
	case 4://remover a esquerda
		if (pont==NULL)
		{
			puts("           NÆo tem nada desse lado .... ");
			getch();
		}
		else
		{
			removeEsq(pont);
			getch();
		}
	break;
	case 5://remover a direita
		   if (pont==NULL)
		{
			puts("           NÆo tem nada desse lado .... ");
			getch();
		}
		else
		{
			removeDir(pont);
			getch();
		}
	break;
	case 6://remover ponteiro
	break;
	case 7://listar de esquerda para direita
		   if (pont!=NULL){
				EscreveEsqDir(pont);
				getch();
		   }
		   else{
				printf("          Lista vazia sua Anta.....aperte qq coisa");
				getch();
		   }
	break;
	case 8://listar de direita para a esquerda
		   if (pont!=NULL){
				EscreveDirEsq(pont);
				getch();
		   }
		   else{
				printf("          Lista vazia sua Anta.....aperte qq coisa");
				getch();
		   }
	break;
	case 9://sair
	exit(0);
	default:puts("         Op‡Æo inv lida");
	getche();
	break;
  }
 }while(1);
}

//Criando a lista
NODEPTR crialista(int x)
{
  NODEPTR p;
  p=(NODEPTR)malloc(sizeof(struct node));
  p->info=x;
  p->prox=NULL;
  p->ant=NULL;
  return(p);
}



