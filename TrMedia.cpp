#include <stdio.h>
#include <conio.h>
void main()
{
char nome[40];
float codigo, total;
float n1, n2, t1, t2, medn1, p1, p2, medn2, p3, p4;
textbackground(1);
clrscr();
gotoxy(25,1);
cprintf("Programa M‚dia Bimestral");
gotoxy(2,3);
printf("Nome: ");
gets(nome);
gotoxy(2,4);
printf("C¢digo:");
scanf("%f",&codigo);
gotoxy(10,8);
textbackground(4);
cprintf("1§Bimestre");
gotoxy(10,10);
printf("Nota da Prova   :");
gotoxy(10,11);
printf("Nota do Trabalho:");
gotoxy(45,8);
textbackground(4);
cprintf("2§Bimestre");
gotoxy(45,10);
printf("Nota da Prova   :");
gotoxy(45,11);
printf("Nota do Trabalho:");
gotoxy(28,10);
scanf("%f",&n1);
gotoxy(28,11);
scanf("%f",&t1);
gotoxy(63,10);
scanf("%f",&n2);
gotoxy(63,11);
scanf("%f",&t2);
p1=(n1*7)/10;
p2=(t1*3)/10;
p3=(n2*7)/10;
p4=(t2*3)/10;
medn1=(p1+p2);
medn2=(p3+p4);
total=(medn1+medn2)/2;
gotoxy(18,18);
if (total<3)
  printf("A sua m‚dia ‚ %.2f e vocˆ esta reprovado",total);
else if (total >=3 & total < 7)
  printf("A sua m‚dia ‚ %.2f e vocˆ esta de exame",total);
else if (total >=7)
  printf("A sua m‚dia ‚ %.2f e vocˆ esta aprovado",total);


getche();
}
