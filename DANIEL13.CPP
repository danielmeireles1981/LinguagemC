#include <stdio.h>
#include <conio.h>
void main()
{
clrscr();
int ftemp, ctemp, ktemp;
printf("Digite temperatura em graus Fahrenheit:");
scanf("%d",& ftemp);
ctemp=(ftemp-32)*5/9;
printf("\n A temperatura em graus Celsius ‚ %d",ctemp);
ktemp=ctemp+273;
printf("\n A temperatura em graus Kelvin ‚ %d",ktemp);
getche();
}