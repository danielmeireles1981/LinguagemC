#include <stdio.h>
#include <conio.h>

void main()
{
  char nome[30];
  float nota1, nota2;
  float media;

  clrscr();
  printf("Digite o nome do aluno: ");
  scanf("%s",nome);
  printf("Digite a nota1: ");
  scanf("%f",&nota1);
  printf("Digite a nota2: ");
  scanf("%f",&nota2);
  media=((nota1+nota2)/2);
  printf("O nome do aluno ‚ %s e sua m‚dia ‚ %4.2f",nome,media);
  getche();
}
