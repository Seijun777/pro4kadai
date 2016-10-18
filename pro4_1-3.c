#include<stdio.h>
#include<stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include"stack.h"
#define BUFLEN 100

int main()
{
  int ch,chst,err,i;
  char buf[BUFLEN];
  init_stack();
  err = 0;

  fprintf(stdout,"Please Enter C Program : \n");

  while(1)
  {
    fgets(buf,sizeof(buf),stdin);
    if(buf[1] == '\0')
    {
      if(stack_stock() <= 0 && err == 0)
        fprintf(stdout,"Parentheses are correct!! \n");
      else
        fprintf(stdout,"Parentheses error!! \n");
      break;
    }

    for( i = 0; i < BUFLEN ; i++)
    {
      if(buf[i] == '{' || buf[i] == '}' || buf[i] == '(' ||
         buf[i] == ')' || buf[i] == '[' || buf[i] == ']'    )
          push(buf[i]);
    }
    while(stack_stock() > 2 && err != 1)
    {

      ch = pop();
      chst = pop();
      switch(ch)
      {
        case'}':
          if(chst != '{')
            err = 1;
          break;
        case')':
          if(chst != '(')
            err = 1;
          break;
        case']':
          if(chst != '[')
            err = 1;
          break;
        default:
          err = 1;
          break;
      }
    }
}

  return 0;
}
