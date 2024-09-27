#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

//Defini‡Æo da estrutura
struct node{
		   int info;
		   struct node *prox;
		   struct node *ant;};
typedef struct node *NODEPTR;
//---------------------------------------
//Prototipos
void menu(void);
NODEPTR crialista(int x);
void insereNoAnt(NODEPTR p, int x);
void EscreveEsqDir(NODEPTR);

//---------------------------------------
//Fun‡Æo
void insereNoAnt(NODEPTR p, int x)
{
	NODEPTR novo, aux;
	novo=(NODEPTR)malloc(sizeof(struct node));
	novo->info=x;
	if(p->ant!=NULL){
	novo->prox=p;
	aux=p->ant;
	novo->ant=aux;
	aux->prox=novo;
	p->ant=novo;}
	else{
	p->ant=novo;
	novo->prox=p;
	novo->ant=NULL;}
}
//---------------------------------------
//menu
void menu()
{
puts("				  Menu");
puts("		1. Criar lista");
puts("		2. Inserir a esquerda");
puts("		3. Inserir a direita");
puts("		4. Remover a esquerda");
puts("		5. Remover a direita");
puts("		6. Remover ponteiro");
puts("		7. Listar de esquerda para direita");
puts("		8. Listar de direita para a esquerda");
puts("		9. Sair\n");
printf("Digite uma op‡Æo: ");
}
//---------------------------------------
void main(void)
{
clrscr();
//Vari veis
int opcao;
NODEPTR pont=NULL;
int num;

do{
//Desenhando menu
clrscr();
menu();

//Lendo op‡Æo
scanf("%d",&opcao);

switch(opcao){
	case 1://criar lista
		   //ler informa‡Æo a ser inserida
		   //pode-se criar apenas se pont=NULL
		   if (pont==NULL){
			   printf("Digite o elemento a ser inserido:");
			   scanf("%d",&num);
			   pont=crialista(num);}
		   else{
			   printf("J  existe uma lista! Tecle algo...");
			   getch();}
	break;
	case 2://inserir a esquerda
		   if (pont!=NULL){
			   printf("Digite o elemento a ser inserido:");
			   scanf("%d",&num);
			   insereNoAnt(pont,num);
			   }
		   else{
			   printf("A lista nÆo foi criada... Tecle algo...");
			   getch();}
	break;
	case 3://inserir a direita
	break;
	case 4://remover a esquerda
	break;
	case 5://remover a direita
	break;
	case 6://remover ponteiro
	break;
	case 7://listar de esquerda para direita
		   if (pont!=NULL){
			   EscreveEsqDir(pont);
			   getche();
			   }
		   else{
			   printf("A lista nÆo foi criada... Tecle algo...");
			   getch();}
	break;
	case 8://listar de direita para a esquerda
	break;
	case 9://sair
	exit(0);
	default:puts("Op‡Æo inv lida");
	getche();
	break;
  }
 }while(1);
}
//---------------------------------------
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
//---------------------------------------
//Listar informa‡äes da esquerda p/ direita
void EscreveEsqDir(NODEPTR p)
{
  NODEPTR aux;
  aux = p;
  while(aux->ant!=NULL)
  {
	aux = aux->ant;
  }
  while(aux->prox!=NULL)
	{
	printf("%d",aux->info);
	aux = aux->prox;
	printf("  ");
	delay(1000);
  }
  printf("%d",aux->info);
}
//---------------------------------------


