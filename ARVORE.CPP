//  ARVORES

//Bibliotecas
#include <stdio.h>
#include <conio.h>

//Estruturas
struct node{
	int info; //armazenar† a informaá∆o do n¢ da †rvore
	int use;  //flag de sinalizaá∆o utilizado para indicar se a posiá∆o
			  //do vetor est† ou n∆o sendo utilizado
	};
typedef struct node NODEPTR;

//Prot¢tipos
void ZeraArvore(NODEPTR arv[MAX]);
void CriaArvore(NODEPTR arv[MAX]);
void InsereNode(NODEPTR arv[MAX], int x);
void RemoveNode(NODEPTR arv[MAX], int x);
void Busca(NODEPTR arv[MAX], int x);

//Constantes
#define V 1
#define F 1
#define MAX 500

//Funá‰es
void ZeraArvore(NODEPTR arv[])
{
	int i;
	for (i=0;i<MAX;i++)
	{
		arv[i].use=F
	}
}
