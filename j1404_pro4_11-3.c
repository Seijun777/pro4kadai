#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int tmp[MAX];

void merge_sort(int a[], int le, int ri, int n, int nest)
{
  fprintf(stdout,"\n");
  fprintf(stdout,"Nest = %d [%d - %d]\n",nest,le,ri);

  int i,j,k,m;
  if(le >= ri)
  {
    nest--;
    return ;
  }

  m = (le + ri) / 2;
  fprintf(stdout,"<< Left Call : merge_sort(%d,%d) >>\n",le,m);
  merge_sort(a,le,m,n,nest+1);

  fprintf(stdout,"\n");
  fprintf(stdout,"Nest = %d [%d - %d]\n",nest,le,ri);
  fprintf(stdout,"<< Right Call : merge_sort(%d,%d) >>\n",m+1,ri);
  merge_sort(a,m+1,ri,n,nest+1);

  fprintf(stdout,"\n");
  fprintf(stdout,"Nest = %d [%d - %d]\n",nest,le,ri);

  fprintf(stdout,"Partition : ");
  fprintf(stdout,"Left[%d - %d],  ",le,m);
  for(i = le;i <= m;i++)
  {
    tmp[i] = a[i];
  }
  fprintf(stdout,"Right[%d - %d]\n",m+1,ri);
  for(j = m+1;j <= ri;j++)
  {
    tmp[ri+m+1-j] = a[j];
  }

  fprintf(stdout,"<< Sort Region : Left = %d, Right = %d, m = %d >>\n",le,ri,m);
  fprintf(stdout,"Before : ");
  for(i = 0;i < n; i++)
  {
    fprintf(stdout,"%d ",a[i]);
  }
  fprintf(stdout,"\n");
  i = le;
  j = ri;
  for(k = le;k <= ri;k++)
  {
    if(tmp[i] <= tmp[j])
      a[k] = tmp[i++];
    else
      a[k] = tmp[j--];
  }
  fprintf(stdout,"After : ");
  for(i = 0;i < n; i++)
  {
    fprintf(stdout,"%d ",a[i]);
  }
  fprintf(stdout,"\n");
  
  nest--;
}

int main()
{
  int n,i;
  int d[MAX];
  n = 0;

  fprintf(stdout,"Input Data : ");
  while(scanf("%d",&d[n]) != EOF)
  { n++;  }

  merge_sort(d,0,n-1,n,1);

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n; i++)
  {
    fprintf(stdout,"%d ",d[i]);
  }
  fprintf(stdout,"\n");

  return 0;
}
