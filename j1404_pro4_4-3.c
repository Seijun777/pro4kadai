#include<stdio.h>
#include<stdlib.h>

//連結リストの構造体
typedef struct node
{
  int data;
  struct node *next;
}LISTL;

LISTL root;  //先頭ノードを指す構造体

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
      p->data = y;
      p->next = root.next;
      root.next = p;
    }
  }
}

//連結リストを出力する関数
void print_list()
{
  LISTL *p;
  p = (LISTL *)malloc( sizeof(LISTL) );
  p = root.next;

  if(p->next == &root)
  {
    fprintf(stderr,"There Is No Data!\n");
    return ;
  }

  fprintf(stdout,"List Data :");
  while(p != &root)
  {
    fprintf(stdout," %4d",p->data);
    p = p->next;
  }
  fprintf(stdout,"\n");
}


//連結リストに挿入する関数
void insert_node(int k, int y)
{
  int i;
  LISTL *p,*q;

  if(k <= 0)
  {
    fprintf(stderr,"Error  : Target Node Is Not Found\n");
    return ;
  }

  p = (LISTL *)malloc( sizeof(LISTL) );
  p = root.next;

  for(i = 1; i < k; i++)
  {
    if(p == NULL)
    {
      fprintf(stderr,"Error  : Target Node Is Not Found\n");
      return ;
    }
    p = p->next;
  }

  //ノードを追加
  q = (LISTL *)malloc( sizeof(LISTL) );
  q->data = y;
  q->next = p->next;
  p->next = q;
}

//ノードを削除する関数
void delete_node(int k)
{
  int i;
  LISTL *p,*q;

  p = (LISTL *)malloc( sizeof(LISTL) );
  p = root.next;

  if(p == NULL || k <= 0)
  {
    fprintf(stderr,"Error  : Target Node Is Not Found\n");
    return ;
  }

  if(k == 1)    //先頭のノードを削除
  {
    p = p->next;
    root.next = p;
  }

  q = (LISTL *)malloc( sizeof(LISTL) );
  q = NULL;

  if(k > 1)
  {
    for(i = 2; i < k; i++)
    {
      if(p == &root)
      {
        fprintf(stderr,"Error  : Target Node Is Not Found\n");
        return ;
      }
      p = p->next;
    }

    //ノードを削除（外す）
    q = p->next;
    p->next = q->next;
  }
}

//ノードのデータを置き換える関数
void replace_node(int x, int y)
{
  int i;
  LISTL *p;

  p = (LISTL *)malloc( sizeof(LISTL) );
  p = root.next;

  while(p != &root)
  {
    if(p->data == x)  //データが見つかったら置き換える
      p->data = y;
    p = p->next;
  }
}

int main()
{
  int k,x,y;
  root.next = &root;        //リストの初期化
  construct_list();   //リストの構築
  print_list();       //リストの出力

  //データの挿入
  fprintf(stdout,"********Insert********\n");
  fprintf(stdout,"Input Insert-Location :");
  scanf("%d",&k);
  fprintf(stdout,"Input Insert-Data :");
  scanf("%d",&y);
  insert_node(k,y);
  print_list();      //リストの出力

  //データの削除
  fprintf(stdout,"********Delete********\n");
  fprintf(stdout,"Input Delete-Location :");
  scanf("%d",&k);
  delete_node(k);
  print_list();      //リストの出力

  //データの置き換え
  fprintf(stdout,"********Replace********\n");
  fprintf(stdout,"Input Search Data :");
  scanf("%d",&x);
  fprintf(stdout,"Input Replace Data :");
  scanf("%d",&y);
  replace_node(x,y);
  print_list();     //リストの出力

  return 0;
}
