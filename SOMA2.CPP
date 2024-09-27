#include <stdio.h>
#include <conio.h>

//prototipo
int leia(void);
int soma(int a, int b);
void escreva(int c);

//fun‡äes e procedimentos
int leia(void)
{
int num;
printf("Digite um n§:");
scanf("%d",&num);
return(num);
}
int soma(int a,int b)
{
int c;
c=a+b;
return(c);
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
	c=soma(a,b);
	escreva(c);
	getch();
}