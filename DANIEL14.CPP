/*
*/
#include <stdio.h>
#include <conio.h>
void main()
{
float a, b, c, menor;
clrscr();
printf("\n Forne‡a um numero: ");
scanf("%f",&a);
printf("\n Forne‡a um numero: ");
scanf("%f",&b);
printf("\n Forne‡a um numero: ");
scanf("%f",&c);
 if (a<b && a<c)
  menor=a;
 else {
	  if (b<c)
		 menor=b;
	  else
		 menor=c;
  }
  printf("\n Menor numero ‚ %.2f:",menor);
  getche();
}

