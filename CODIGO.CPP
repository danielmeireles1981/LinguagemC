#include <stdio.h>
#include <conio.h>
void main()
{
clrscr();
char nome[30];
int codigo;
printf("Digite o nome do integrante: ");
scanf("%s",nome);
printf("Digite seu c¢digo: ");
scanf("%d",&codigo);
printf("O nome do integrante ‚ %s e seu c¢digo ‚ %d",nome,codigo);
getche();
}