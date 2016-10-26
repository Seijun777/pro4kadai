#include<stdio.h>
#include<stdlib.h>

//連結リストの構造体
typedef struct node
{
  int data;
  struct node *next;
}LISTL;

LISTL *root;  //リストの先頭をあらわすポインタ

//連結リストを構築する関数
void construct_list()
{
  LISTL *p;
  int n,y,i,k,noIndex[50];
  char buf[100];

  while(1)
  {
    fprintf(stdout,"Input Data : ");
    fgets(buf, sizeof(buf), stdin);

    if(buf[0] == '\n')
      return ;

    i = 0,k = 0;
    if(buf[i] != ' ')
      noIndex[k++] = i;

    while(buf[i] != '\0')
    {
      i++;
      if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n')
        noIndex[k++] = i;
    }

    //文字数がオーバーした場合
    if(buf[i-1] != '\n')
    {
      fprintf(stderr,"Error : Too Long Input Data\n");
      exit(1);
    }

    //リストに入力された値を格納
    for(i = 0; i < k; i++)
    {
      n = sscanf(&buf[noIndex[i]], "%d", &y);
      if(n != 1)
      {
        fprintf(stderr,"Error : Non-Number Input Data\n");
        continue;
      }
      p = (LISTL *)malloc(sizeof(LISTL));
      p->data = y, p->next = root;
      root = p;
    }
  }
}

//連結リストを出力する関数
void print_list()
{
  LISTL *p;
  p = (LISTL *)malloc( sizeof(LISTL) );
  p = root;

  if(p == NULL)
  {
    fprintf(stderr,"There Is No Data!\n");
    return ;
  }

  fprintf(stdout,"List Data :");
  while(p != NULL)
  {
    fprintf(stdout," %4d",p->data);
    p = p->next;
  }
  fprintf(stdout,"\n");
}

int main()
{
  root = NULL;        //リストの初期化
  construct_list();   //リストの構築
  print_list();       //リストの出力
  return 0;
}
