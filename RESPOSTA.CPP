#include <stdio.h>
#include <conio.h>
void main()
{
	int temp, num_i= 20;
	double num_f = 50.33333;
	char txt[10] = "exemplo";

	clrscr();
	printf("\n\n [%10.2f] \n", num_i);
	num_i= 2;
	printf("[%06d] \n", num_i);
	printf("[%10s]", txt);
	temp = num_i - 1;
	printf("[%-5d] \n", temp);
	printf("[%-5.2s] \n", txt);
	getche();
}

