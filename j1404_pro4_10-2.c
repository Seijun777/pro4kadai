#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX];

void quick_sort(int le, int ri)
{
  int i,j,k,pivot,tmp;

  if(le == ri)
  { return ;  }

  k = (le + ri) / 2;
  pivot = d[k];
  i  =le;
  j = ri;

  while(i <= j)
  {
    while(d[i] > pivot)
    { i++;  }
    while(d[j] < pivot)
    { j--;  }
    if(i >= j)
      break;

    tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
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
  int n,i;
  n = 0;

  fprintf(stdout,"Input Data : ");
  while( scanf("%d",&d[n]) != EOF )
  {  n++; }

  quick_sort(0,n-1);

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n-1;i++)
  {
    fprintf(stdout,"%d ",d[i]);
  }
  fprintf(stdout,"%d\n",d[n-1]);

  return 0;
}
