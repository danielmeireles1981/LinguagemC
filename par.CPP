#include <stdio.h>
#include <conio.h>
void main()
{
	int num;
	float par, impar;
	clrscr();
	printf("Digite um numero:");
	scanf("%d",&num);
	if (num == num/2*2)
	   printf("\n O numero e par \n");
   else
		printf("O numero e impar");

	getche();
}


