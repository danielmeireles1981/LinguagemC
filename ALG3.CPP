#include <stdio.h>
#include <conio.h>
void main()
{
int num;
printf("Digite um n£mero: %d", num);
scanf("%d",num);
if (num>0)
   printf("O n£mero ‚ positivo",num);
   else if (num==0)
		printf("O n£mero ‚ neutro",num);
		else printf("O n£meor ‚ negativo",num);
getche();
}
