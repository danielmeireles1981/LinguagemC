/* programa evento.c */
#include "stdio.h"
#include <conio.h>
void main()
{
clrscr();
int evento;
char corrida;
float tempo;
evento=5;
corrida='c';
tempo=27.25;
printf("\n O tempo vitorioso na eliminatoria %c",corrida);
printf("\n da competicao %d foi %.2f",evento, tempo);
}