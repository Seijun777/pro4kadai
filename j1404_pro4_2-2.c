#include<stdio.h>
#include<stdlib.h>
#define Q_size 11
#define Q_type int
#include "j1404_queue_2.h"

int main()
{
  int c,i,num;

  init_Q();

  fprintf(stdout,"Queue size : %d",Q_size-1);
  fprintf(stdout,"\nPlease eneter text : ");

  while( ( c = getchar()) != '\n')
  {
    enqueue(c);
  }

  fprintf(stdout,"\nArray Q data : ");
  for(i = 0; i < stock_Q(); i++)
    fprintf(stdout,"%c ",Q[i]);

  fprintf(stdout,"\nPlease enter dequeu number:");
  scanf("%d",&num);

  fprintf(stdout,"Deque data : ");
  for(i = 0; i < num; i++)
    fprintf(stdout,"%c ",dequeue());

  fprintf(stdout,"\nPlease enter next text(MAX num:%d)",Q_size - stock_Q() - 1);
  c = getchar();
  while( ( c = getchar()) != '\n')
  {
    enqueue(c);
  }

  fprintf(stdout,"Front : %d     Rear : %d",f,r);
  print_Q();

  getchar();

 fprintf(stderr,"\nArray Q data : ");
  for(i = 0; i < Q_size; i++)
    fprintf(stdout,"%c ",Q[i]);
}
