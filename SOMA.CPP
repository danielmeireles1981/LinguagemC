#include <stdio.h>
#include <conio.h>

//prototipo
int leia(void);
void soma(int a, int b, int *c);
void escreva(int c);

//fun‡äes e procedimentos
int leia(void)
{
int num;
printf("Digite um n§:");
scanf("%d",&num);
return(num);
}
void soma(int a,int b, int *c)
{
*c=a+b;
}
void escreva(int c)
{
printf("O resultado ‚:%d",c);
}

//Programa principal

void main(void)
{
int a,b,c;
	clrscr();
	a=leia();
	b=leia();
	soma(a,b,&c);
	escreva(c);
	getch();
}