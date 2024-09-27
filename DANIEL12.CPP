#include <stdio.h>
#include <conio.h>
void main()
{
clrscr();
int n1=3, n2=5;
float vf=13.0;
char txt[]="exibir";
printf("[%3d]",n1);
printf("[%-4d]",n2);
printf("[%10s]",txt);
printf("[%c]",txt[2]);
printf("[%-8.3s]",txt);
printf("[%4.6f]",vf);
getche();
}