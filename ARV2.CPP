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
void PreOrdemNode(NODEPTR arv[MAX],int pos);

//fun‡äes/procedimentos
//ZeraArvore
void ZeraArvore(NODEPTR arv[])
	{
		int i;
		for (i=0;i<MAX;i++)
			{
			arv[i].use = F;
			}
	}

//---------------------------------------
//CriaArvore
void CriaArvore(NODEPTR arv[],int x)
{
  arv[0].info = x;
  arv[0].use = V;
}
//---------------------------------------
//InsereNode
void InsereNode(NODEPTR arv[], int x)
{
	int p, q;
	q=0;
	while ((arv[q].use==V)&&(p<MAX))
	{
		p=q;
		if (arv[p].info>x)
		{
			q=2*p+2;
		}
		else
		{
			q=2*p+1;
		}
	}
	if (q>MAX)
	{
		arv[q].info=x;
		arv[q].use=V;
	}
	else
	{
	puts("Overfloww");
	}
}
//fim de InsereNode

//---------------------------------------
//Busca
void BuscaNODE(NODEPTR arv[], int x)
{
	int p,q;
	p=q=0;
	while((q<MAX)&&(arv[q].use==V)&&(arv[p].info!=x))
	{
		p=q;
		if (arv[p].info>x)
		{
			q=2*p+1;
		}
		else
		{
			q=2*p+2;
		}
	}
		if (arv[p].info==x)
		{
			puts("Elemento encontrado");
			getch();
		}
		else
		{
			puts(" PAN!!! Tente de novo");
			getch();
		}
}

//Imprimir lista
void ImprimirNode(NODEPTR arv[], int pos)
{
	if (arv[pos].use!=F)
	{
		printf("%d",arv[pos].info);
		printf("    ");
		ImprimirNode(arv, 2*pos+1);
		ImprimirNode(arv, 2*pos+2);
	}
}

//---------------------------------------
//menu
void menu()
{
puts("                    Menu             ");
puts("\n                    1. Criar µrvore  ");
puts("                    2. Inserir µrvore ");
puts("                    3. Busca         ");
puts("                    4. Remover       ");
puts("                    5. Imprimir      ");
puts("                    6. Sair\n        ");
printf("                 --> Digite uma op‡Æo: ");
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
		   if (arvore[0].use!=F)
			 {
				printf("Digite elemento a ser inserido: ");
				scanf("%d",&num);
				InsereNode(arvore,num);
			 }
		   else{
			 printf("NÆo existe nenhuma arvore.....");
			 getch();}
	break;
	case 3://busca
		   if(arvore[0].use==V)
		   {
			printf("Digite elemento a ser procurado: ");
			scanf("%d",&num);
			BuscaNODE(arvore,num);
		   }
		   else{
			printf("NÆo achado ");
			getche();
		   }
	break;
	case 4://remove
	break;
	case 5://imprime
		   int pos;
		   pos = 0;
		   printf("Elementos contidos na arvore:  ");
		   ImprimirNode(arvore,pos);
		   getche();
	break;
	case 6://sair
	exit(0);
	default:puts("Op‡Æo inv lida");
	getche();
	break;
  }
 }while(1);
}