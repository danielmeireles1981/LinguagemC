//implementando uma arvore em estrutura dinamica

#include <conio.h>
#include <stdlib.h>

//criando a estrutura
struct node
{
	int info;
	struct node *esq;
	struct node *dir;
};
typedef struct node *NODEPTR;

//criar arvore
NODEPTR CriaArvore(int x)
{
	NODEPTR arv;
	arv=(NODEPTR)malloc(sizeof(struct node)); //cria caixinha
	arv->info=x; //coloca x na caixinha
	arv->esq=NULL; //faz com q a esquerda seja vazio
	arv->dir=NULL; //faz com q a direita seja vazio
	return(arv);
}

//insercao
void Insere(NODEPTR arv, int x)
{
	NODEPTR p,q;
	q=arv;  //q inicia como arv
	while (q!=NULL)
	{
		p=q;
		if (p->info==x)  //se p aponta para info que e igual a x
		{
			q=p->esq;  //q igual p que aponta para esquerda
		}
		else
		{
			q=p->dir;    //q igual a p que aponta para direita
		}
	}
   q=CriaArvore(x);  //cria em q uma caixinha com NULL na esquerda na direita
   q->info=x;
   if (x<p->info)
   {
	q->dir=p;
   }
   else
   {
	q->esq=p;
   }
}








