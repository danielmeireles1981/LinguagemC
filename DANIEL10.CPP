#include <stdio.h>
#include <conio.h>
void main()
{
clrscr();
float x, y, z, total;
printf("Digite o primeiro valor: ");
scanf("%f",&x);
printf("Digite o segundo valor: ");
scanf("%f",&y);
printf("Digite o terceiro valor: ");
scanf("%f",&z);
total = x+y+z;
printf("A Soma dos valores e:%.0f ",total);
getche();
}
