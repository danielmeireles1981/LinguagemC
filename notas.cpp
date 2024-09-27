#include <stdio.h>
#include <conio.h>
void main()
{
char nome[40];
float codigo, mediaS;
float pro1, pro2, trab1, trab2, medB1, n1, n2, medB2, n3, n4;
clrscr();
printf("Programa M‚dia Bimestral\n");
printf("\nNome: ");
gets(nome);
printf("\nC¢digo:");
scanf("%f",&codigo);
printf("\n\n1§Bimestre");
printf("\nNota da Prova:");
scanf("%f",&pro1);
printf("Nota do Trabalho:");
scanf("%f",&trab1);
printf("\n\n 2§Bimestre");
printf("\nNota da Prova:");
scanf("%f",&pro2);
printf("Nota do Trabalho:");
scanf("%f",&trab2);
n1=(pro1*7)/10;
n2=(trab1*3)/10;
n3=(pro2*7)/10;
n4=(trab2*3)/10;
medB1=(n1+n2);
medB2=(n3+n4);
mediaS=(medB1+medB2)/2;
if (mediaS<3)
  printf("\n\nA sua m‚dia ‚ %.2f e vocˆ esta reprovado",mediaS);
else if (mediaS >=3 & mediaS < 7)
  printf("\n\nA sua m‚dia ‚ %.2f e vocˆ esta de exame",mediaS);
else if (mediaS >=7)
  printf("\n\nA sua m‚dia ‚ %.2f e vocˆ esta aprovado",mediaS);
getche();
}

