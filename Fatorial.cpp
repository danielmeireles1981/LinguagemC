#include <stdio.h>
#include <conio.h>

int fat(n)
int n;
{
  if ((n==0)||(n==1))
  {
  return(1);
  }
  else
  {
  return (n*fat(n-1));
  }
}
void main()
{
clrscr();
int x,y;
printf("Digite um numero:",x);
scanf("%d",&x);
y=fat(x);
printf("O fat ‚ :%d",y);
getche();
}

