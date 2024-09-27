#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

struct no {
	int info;
	struct no *esq;
	struct no *dir;
};

typedef struct no *NODEPTR;


NODEPTR CriaArvore(int x);
void DesenhaArvore(NODEPTR arv,int num);

NODEPTR CriaArvore(int x)
{
	NODEPTR arv;

	arv = (NODEPTR) malloc (sizeof (struct no));
	arv->info = x;
	arv -> esq = NULL;
	arv -> dir = NULL;
	return(arv);
}


void Insere(NODEPTR arv, int x)
{
	int  i;
	NODEPTR p,q;

	p = q = arv;
	while (q!=NULL)
	{
		p = q;
		if (x < p->info)
		{
			q = p->esq;
		}
		else
		{
			q = p->dir;
		}
	}

	q = (NODEPTR) malloc (sizeof (struct no));
	q->info = x;
	q->esq = NULL;
	q->dir = NULL;

	if (x < p->info)
	{
		p->esq = q;
	}
	else
	{
		p->dir = q;
	}
}


void InOrdem(NODEPTR arv)
{
	if (arv!=NULL){
		InOrdem(arv->esq);
		printf("%d", arv->info);
		InOrdem(arv->dir);
	}
}


void Nivel(NODEPTR arv, int niv, int *max)
{
	if (arv!=NULL){
		niv = niv+1;
		if (niv>*max)
			*max = niv;
		Nivel(arv->esq,niv,max);
		Nivel(arv->dir, niv,max);
		niv = niv -1;

	}
}


void DesenhaNo(NODEPTR arv, int raio,int x, int y, int nivel)
{
	int novox,novoy,dx;
	if (arv!=NULL){
		char *s;
		itoa(arv->info,s,10);
		circle(x,y,raio);
		outtextxy(x,y,s);
		nivel=nivel+1;
		if(arv->esq!=NULL){
				//DesenhaLinha
				dx = getmaxx()/pow(2,(nivel+1));
				novox = x  - dx;
				novoy = y + 2*raio +50;
				line(x,y+raio,novox,novoy-raio);
		}
		DesenhaNo(arv->esq,raio,novox,novoy, nivel);
		if (arv->dir!=NULL){
			// dESENHA LINHA
			dx = getmaxx()/pow(2,(nivel+1));
			novox = x + dx;
			novoy = y + 2*raio + 50;
			line(x,y+raio,novox,novoy-raio);
		}

		DesenhaNo(arv->dir,raio,novox,novoy,nivel);
		nivel=nivel-1;
	}
}

void DesenhaArvore(NODEPTR arv)
{
	NODEPTR aux;
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics mode */
	/**********************************
	/*********************************
	/**********************************/
	// DIGITE ENTRE OS PARENTESES O LOCAL ONDE SE ENCONTRA O DIRETORIO
	// BGI COMO MOSTRADO ABAIXO, SE O SEU TC ESTµ EM OUTRO DIRETORIO
	// MODIFIQUE-O - Ç necessario colocar duas barras invertidas`
	initgraph(&gdriver, &gmode, "i:\\bgi");

	/* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt");
		getch();
	}
	else
	{
		settextjustify(1,1);  //alinhamento do texto na horizontal e vertical
		settextstyle(0,0,1);  //seta algumas caracteristicas do texto (fonte, direcao, tamanho)
		aux = arv;
		DesenhaNo(aux,15,getmaxx()/2, 30,0 );
		getch();
		closegraph();
	}


}
void Menu(void)
{
	 puts("MENU:");
	 puts("1. Cria †rvore.");
	 puts("2. Inserir elemento");
	 puts("3. Altura da †rvore ");
	 puts("4. Procurar elemento");
	 puts("5. Imprimir a †rvore");
	 puts("6. Desenhar a †rvore");
	 puts("7. Sair");
	 printf("Opá∆o: ");
}

void main(void)
{
	NODEPTR arvore,aux;
	int opcao,num,max;
	char resp;
	int p, achou;

	arvore = NULL;
	do{
		clrscr();
		Menu();
		scanf("%d", &opcao);
		switch (opcao){
			case 1:  // Cria arvore
						if (arvore==NULL)
						{
							printf("Digite o elemento a ser inserido: ");
							scanf( "%d", &num);
							arvore = CriaArvore(num);
						}
						else
						{
							puts("J† existe uma †rvore criada ");
							getch();
						}
						break;

			case 2:  // INSERCAO DE ELEMENTO
						printf("Digite o elemento a ser inserido: ");
						scanf( "%d", &num);
						Insere(arvore,num);
						break;

			case 3:  max = 0;
						Nivel(arvore,0,&max);
						printf("Altura da †rvore = %d", max-1);
						getch();
			case 4:  // Procurar elemento
						break;

			case 5:	// Imprimir a †rvore
						InOrdem(arvore);
						puts("\n");
						getch();
						break;

			case 6: // Desenha a arvore
						aux = arvore;
						Nivel(aux,0,&max);
						max=max-1;
						if (max > 4)
						{
							puts("Sua †rvore pode n∆o ser desenhada corretamente, a altura");
							puts("da †rvore ultrapassa o limite da tela");
							printf("Desenha desenhar mesmo assim (s/n?)?");
							resp =getche();
							if ((resp == 'S') || (resp=='s'))
								DesenhaArvore(aux);
						}
						else
						DesenhaArvore(arvore);
						break;
			case 7:// sai do programa
						break;

			default: puts(" Opá∆o inv†lida");
						puts("Tecle algo para continuar...");
						getch();
		}
	}while (opcao!=7);
}





