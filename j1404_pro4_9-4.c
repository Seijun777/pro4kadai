#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void select_sort(int a[], int n)
{
  int i,j,t,min;

  for(i = 0;i < n-1; i++)
  {
    min = i;
    for(j = i+1;j <= n-1;j++)
    {
        if(a[j] > a[min])
          min = j;
    }
    t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
}

int main()
{
  int d[MAX],n,i;
  n = 0;

  fprintf(stdout,"Input Data : ");
  while( scanf("%d", &d[n]) != EOF)
  {
    n++;
  }
  select_sort(d,n);

  fprintf(stdout,"\n");

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n-1; i++)
  {
    printf("%d ",d[i]);
  }
  printf("%d \n",d[n-1]);
  return 0;
}
