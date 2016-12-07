#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void bubble_sort(int a[], int n)
{
  int i,j,t;

  for(i = 0;i < n-1; i++)
  {
    for(j = n-1;j > i;j--)
    {
      if(a[j] < a[j-1])
      {
        t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
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
  bubble_sort(d,n);

  fprintf(stdout,"\n");

  fprintf(stdout,"Output Data : ");
  for(i = 0;i < n-1; i++)
  {
    printf("%d ",d[i]);
  }
  printf("%d \n",d[n-1]);
  return 0;
}
