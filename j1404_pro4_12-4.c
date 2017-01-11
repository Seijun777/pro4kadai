#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct item
{
  int data;
  int num;
}Item;
Item d[MAX];

void downheap(int j,int k)
{
  int i;
  Item v;
  v.data = d[j].data;
  v.num = d[j].num;

  while(j <= k/2)
  {
    i = 2*j;

    if(i < k && d[i].data > d[i+1].data)
      i++;
    if(v.data <= d[i].data || i > k)
      break;
    d[j].data = d[i].data;
    d[j].num = d[i].num;
    d[i].data = v.data;
    d[i].num = v.num;
    j = i;
  }
}

void heap_sort(int n)
{
  int i,j,k;
  Item t;

  for(j = n/2;j >= 1;j--)
  {
    downheap(j,n);
  }

  k = n;
  while(k > 1)
  {
    t.data = d[1].data;
    t.num = d[1].num;
    d[1].data = d[k].data;
    d[1].num = d[k].num;
    d[k].data = t.data;
    d[k].num = t.num;
    downheap(1,--k);
  }
}

int main()
{
  int n,i,seed;
  n = 0;

  fprintf(stdout,"Input Random-Seed : ");
  scanf("%d",&seed);

  fprintf(stdout,"Input the Number of Data : ");
  scanf("%d",&n);
  if(n > MAX)
  {
    fprintf(stderr,"N is Too Large!\n");
    exit(1);
  }

  srand(seed);
  for(i = 1;i <= n;i++)
  {
    d[i].data = (rand()*rand() / 1000) % 100;
    d[i].num = 100+i;
  }

  fprintf(stdout,"\nInput Data :\n");
  for(i = 1;i <= n;i++)
  {
    fprintf(stdout,"d[%3d] : data = %5d, num = %4d\n",i,d[i].data,d[i].num);
  }

  heap_sort(n);

  fprintf(stdout,"\nOutput Data :\n");
  for(i = 1;i <= n;i++)
  {
    fprintf(stdout,"d[%3d] : data = %5d, num = %4d\n",i,d[i].data,d[i].num);
  }

  return 0;
}
