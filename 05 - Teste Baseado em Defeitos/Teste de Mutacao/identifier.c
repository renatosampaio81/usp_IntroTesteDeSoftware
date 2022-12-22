#include <stdio.h>

int validStarter(char ch);
int validFollower(char ch);

int main()
{
  char ch;
  int length, valid_id;
  length = 0;
  printf("Digite um possivel identificador seguido por <ENTER>: ");
  ch = fgetc(stdin);
  valid_id = validStarter(ch);
  if(valid_id) length = 1;
  ch = fgetc(stdin);
  while(ch != '\n')
  {
    if(!validFollower(ch)) valid_id = 0;
    length++;
    ch = fgetc(stdin);
  }

  if(valid_id && (length >= 1) && (length <= 6))
  {
    printf("Valido\n");
  }
  else
  {
    printf("Invalido\n");
  }

  return 0;
}

int validStarter(char ch)
{
  if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return 1;
  else return 0;
}

int validFollower(char ch)
{
  if((ch >= 'A' && ch <= 'Z') ||
     (ch >= 'a' && ch <= 'z') ||
     (ch >= '0' && ch <= '9'))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
