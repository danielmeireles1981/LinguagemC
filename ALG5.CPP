#include <stdio.h>
#include <conio.h>
void main()
{
   float n, h, cont;
   clrscr();
   printf("Digite um n£mero:");
   scanf("%f",&n);
   h=0;
   cont=0;
   while (cont<=n)
	{
	 cont=cont+1;
	 h=h+(1/cont);
	 }
   printf("O valor de h ‚: %.2f",h);
   getche();
}
