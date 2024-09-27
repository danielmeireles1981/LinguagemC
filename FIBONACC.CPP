#include <stdio.h>
#include <conio.h>

int fi(n)
{
  if ((n==0)||(n==1))
  {
  return 1;
  }
  else
  {
  return fi(n-1)+fi(n-2);
  }
}
void main()
{
clrscr();
int x;
printf("Digite um numero:",x);
scanf("%d",&x);
printf("A porra do numero ‚: %d",fi(x));
getche();
}