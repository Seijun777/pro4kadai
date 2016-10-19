#include<stdio.h>
#include<stdlib.h>
#define Q_size 10
#define Q_type int
#include "j1404_queue.h"

int main()
{
  int c,i,num;

  init_Q();

  fprintf(stdout,"Queue size: %d",Q_size);
  fprintf(stdout,"\nPlease enter text:");

  while( ( c = getchar()) != '\n')
  {
    enqueue(c);
  }

  fprintf(stdout,"Front : %d     Rear : %d",f,r);

  fprintf(stdout,"\nArray Q data");
  for(i = 0; i < count; i++)
    fprintf(stdout,"%c ",Q[i]);

  fprintf(stdout,"\nPlease enter dequeu number:");
  scanf("%d",&num);

  fprintf(stdout,"Deque data : ");
  for(i = 0; i < num; i++)
    fprintf(stdout,"%c ",dequeue());

  fprintf(stdout,"\nPlease enter next text(MAX num:%d):",count);
  c = getchar();
  while( ( c = getchar()) != '\n')
  {
    enqueue(c);
  }

  fprintf(stdout,"Front : %d     Rear : %d\n",f,r);
  fprintf(stderr,"Queue all data : ");
  while(count != 0)
  {
    fprintf(stderr,"%c ",dequeue());
  }

  fprintf(stderr,"\nArray Q data : ");
  for(i = 0; i < Q_size; i++)
    fprintf(stdout,"%c ",Q[i]);
}
