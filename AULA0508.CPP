#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define V 1
#define F 0
#define MAX 500

struct node{
		int info;
		int use;
		};
typedef struct node NODEPTR;

//prot¢tipos
void ZeraArvore(NODEPTR arv[MAX]);
void CriaArvore(NODEPTR arv[MAX],int x);
void InsereNode(NODEPTR arv[MAX],int x);
void RemoveNode(NODEPTR arv[MAX],int x);
void Busca(NODEPTR arv[MAX],int x);

//fun‡äes/procedimentos
void ZeraArvore(NODEPTR arv[])
	{
		int i;
		for (i=0;i<MAX;i++)
			{
			arv[i].use = F;
			}
	}
//---------------------------------------
//menu
void menu()
{
gotoxy(34,1);
puts("Menu");
puts("\n1. Criar µrvore");
puts("2. Inserir µrvore");
puts("3. Busca");
puts("4. Remover");
puts("5. Imprimir");
puts("6. Sair\n");
printf("Digite uma op‡Æo: ");
}
//---------------------------------------
void main(void)
{
	NODEPTR arvore[MAX];
	int opcao;
	ZeraArvore(arvore);
do{
//Desenhando menu
clrscr();
menu();
int num;

//Lendo op‡Æo
scanf("%d",&opcao);

switch(opcao){
	case 1://criar arvore
		   if (arvore[0].use==F)
			{
			   printf("Digite o elemento a ser inserido: ");
			   scanf("%d",&num);
			   CriaArvore(arvore,num);
			}
		   else{
			   printf("J  existe uma µrvore! Tecle algo...");
			   getch();}
	break;
	case 2://inserir arvore
	break;
	case 3://busca
	break;
	case 4://remove
	break;
	case 5://imprime
	break;
	case 6://sair
	exit(0);
	default:puts("Op‡Æo inv lida");
	getche();
	break;
  }
 }while(1);
}
//---------------------------------------
//Criando µrvore
void CriaArvore(NODEPTR arv[],int x)
{
  arv[0].info = x;
  arv[0].use = V;
}
//---------------------------------------
//Insere µrvore
void InsereNode(NODEPTR arv[MAX],int x)
{
int p,q;

	q = 0;
	while((arv [q].use == V) && (q < MAX))
		{
		  p = q;
		  if (arv[p].info < x)
			  q = 2*p+2;
		  else
			  q = 2*p+1;
		}
	if (q < MAX)
		{
			arv[q].info = x;
			arv[q].use = V;
		}
	else
		puts("Overflow");
}