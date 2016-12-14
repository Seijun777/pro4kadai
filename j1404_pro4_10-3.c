#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX];

void quick_sort(int le, int ri, int n)
{
  int i,j,k,pivot,tmp;
  int a;

  if(le == ri)
  { return ;  }

  k = (le + ri) / 2;
  pivot = d[k];
  i  =le;
  j = ri;
  fprintf(stdout,"<< Sort Region : Left = %d, Right = %d, Pivot = %d >>\n",le,ri,pivot);

  fprintf(stdout,"Before : ");
  for(a = 0;a < n-1;a++)
  {
    fprintf(stdout,"%d ",d[a]);
  }
  fprintf(stdout,"%d\n",d[n-1]);

  while(i <= j)
  {
    while(d[i] < pivot)
    { i++;  }
    while(d[j] > pivot)
    { j--;  }
    if(i >= j)
      break;

    tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
    i++;
    j--;
  }

  fprintf(stdout,"After : ");
  for(a = 0;a < n-1;a++)
  {
    fprintf(stdout,"%d ",d[a]);
  }
  fprintf(stdout,"%d\n",d[n-1]);

  fprintf(stdout,"Partition : Left[%d - %d], Right[%d- %d]\n",le,i-1,j+1,ri);

  fprintf(stdout,"\n");

  if(le < i-1)
  {
    quick_sort(le,i-1,n);
    fprintf(stdout,"<< Right Call : quick_sort(%d,%d) >>\n",j+1,ri);
  }
  if(ri > j+1)
  {
    quick_sort(j+1,ri,n);
    fprintf(stdout,"<< Left Call : quick_sort(%d,%d) >>\n",le,i-1);
  }
}

int main()
{
  int n,i;
  n = 0;

  fprintf(stdout,"Input Data : ");
  while( scanf("%d",&d[n]) != EOF )
  {  n++; }

  fprintf(stdout,"\n");
  quick_sort(0,n-1,n);
  fprintf(stdout,"\n");

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n-1;i++)
  {
    fprintf(stdout,"%d ",d[i]);
  }
  fprintf(stdout,"%d\n",d[n-1]);

  return 0;
}
