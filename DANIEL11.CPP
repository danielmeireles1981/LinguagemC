#include <stdio.h>
#include <conio.h>
void main()
{
char tecla;
clrscr();
printf("pressione uma tecla:");
tecla=getche();
if (tecla >= '0' & tecla <= '9')
 printf("\n voce teclou um numero");
else{
 printf("\n nao e um numero \n");
 printf("A tecla pressionada %c e a sua sucessora ‚ %c",tecla,tecla+1);
 }
 getche();
}
