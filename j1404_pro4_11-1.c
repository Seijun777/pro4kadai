#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int tmp[MAX];

void merge_sort(int a[], int le, int ri)
{
  int i,j,k,m;
  if(le >= ri)
    return ;

  m = (le + ri) / 2;
  merge_sort(a,le,m);
  merge_sort(a,m+1,ri);

  for(i = le;i <= m;i++)
  {
    tmp[i] = a[i];
  }
  for(j = m+1;j <= ri;j++)
  {
    tmp[ri+m+1-j] = a[j];
  }

  i = le;
  j = ri;
  for(k = le;k <= ri;k++)
  {
    if(tmp[i] <= tmp[j])
      a[k] = tmp[i++];
    else
      a[k] = tmp[j--];
  }
}

int main()
{
  int n,i;
  int d[MAX];
  n = 0;

  fprintf(stdout,"Input Data : ");
  while(scanf("%d",&d[n]) != EOF)
  { n++;  }

  merge_sort(d,0,n-1);

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n; i++)
  {
    fprintf(stdout,"%d ",d[i]);
  }
  fprintf(stdout,"\n");

  return 0;
}
