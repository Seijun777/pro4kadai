#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct item
{
  double data;
  int num;
}Item;

Item d[MAX];

void quick_sort(int le, int ri)
{
  int i,j,k;
  double pivot;
  Item tmp;

  if(le == ri)
  { return ;  }

  k = (le + ri)/2;
  pivot = d[k].data;
  i = le;
  j = ri;

  while(i <= j)
  {
    while(d[i].data < pivot)
    { i++;  }
    while(d[j].data > pivot)
    { j--;  }
    if(i >= j)
    { break;  }
    tmp.data = d[i].data;
    tmp.num = d[i].num;
    d[i].data = d[j].data;
    d[i].num = d[j].num;
    d[j].data = tmp.data;
    d[j].num = tmp.num;
    i++;
    j--;
  }

  if(le < i-1)
    quick_sort(le,i-1);
  if(ri > j+1)
    quick_sort(j+1,ri);
}

int main()
{
  int n,i,seed;
  n = 0;

  fprintf(stdout,"Input Random-Seed : ");
  scanf("%d",&seed);
  srand(seed);

  fprintf(stdout,"Input The Number Of Data : ");
  scanf("%d",&n);
  if(n > MAX)
  {
    fprintf(stderr,"The Number Is Too Large!\n");
    exit(1);
  }

  for(i = 0;i < n;i++)
  {
    d[i].data = rand() / 10000.0;
    d[i].num = 100+i;
  }

  fprintf(stdout,"\nInput Data :\n");
  for(i = 0;i < n;i++)
  {
    fprintf(stdout,"d[%3d] : Data = %10.3f, Num = %4d\n",i,d[i].data,d[i].num);
  }
  fprintf(stdout,"\n");

  quick_sort(0,n-1);

  fprintf(stdout,"\nOutput Data :\n");
  for(i = 0;i < n;i++)
  {
    fprintf(stdout,"d[%3d] : Data = %10.3f, Num = %4d\n",i,d[i].data,d[i].num);
  }
  fprintf(stdout,"\n");

  return 0;
}
