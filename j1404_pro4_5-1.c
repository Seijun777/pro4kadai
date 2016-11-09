#include<stdio.h>
#include<stdlib.h>

//連結リストの構造体
typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
}LISTL;

LISTL root;  //先頭ノードを指す構造体

//連結リストを構築する関数
void construct_list()
{
  LISTL *p,*q;
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
      q = (LISTL *)malloc(sizeof(LISTL));

      q = root.next;      //先頭ノードのアドレスを格納
      p->data = y;        //追加するノードに値を代入
      p->next = q;        //追加するノードの次のノードを先頭ノードに
      p->prev = q->prev;  //追加するノードが指す前のノードを先頭を指すノードにする
      root.next = p;      //先頭を指すノードが追加するノードを指すように
      q->prev = p;        //追加前の先頭ノードが追加するノードを指すように

    }
  }
}

//連結リストを出力する関数
void print_list()
{
  LISTL *p,*q;
  p = (LISTL *)malloc( sizeof(LISTL) );
  q = (LISTL *)malloc( sizeof(LISTL) );

  p = root.next;
  q = root.prev;

  if(p->next == &root)
  {
    fprintf(stderr,"There Is No Data!\n");
    return ;
  }

  fprintf(stdout,"List Data (From Last) :");
  while(p != &root)                           //リストを後ろから出力
  {
    fprintf(stdout," %4d",p->data);
    p = p->next;
  }
  fprintf(stdout,"\n");
  fprintf(stdout,"List Data (From First) :");
  while(q != &root)                           //リストを前から出力
  {
    fprintf(stdout," %4d",q->data);
    q = q->prev;
  }
  fprintf(stdout,"\n");

}

int main()
{
  root.next = &root;        //リストの初期化
  root.prev = &root;
  construct_list();   //リストの構築
  print_list();       //リストの出力
  return 0;
}
