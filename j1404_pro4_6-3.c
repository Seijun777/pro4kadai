#include<stdio.h>
#include<stdlib.h>

//二分木の構造体
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
}TREE;

TREE *root;       //根のノードを指すポインタ

//二分木を構造する関数
void construct_tree()
{
  TREE *p,*q;
  int n,y,i,k,noIndex[50];
  char buf[100];

  p = (TREE *)malloc( sizeof(TREE) );

  while(1)
  {
    fprintf(stdout,"Input Data : ");
    fgets(buf,sizeof(buf),stdin);

    if(buf[0] == '\n')
      return ;
    i = 0;
    k = 0;
    if(buf[i] != ' ')
      noIndex[k++] = i;
    while(buf[i] != '\0')
    {
      i++;
      if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n')
        noIndex[k++] = i;
    }
    if(buf[i-1] != '\n')
    {
      fprintf(stderr,"Error : Too Long Input Data\n");
      exit(1);
    }

    //入力された数字をノードに格納して木を構築する
    for(i = 0; i < k; i++)
    {
      n = sscanf(&buf[ noIndex[i] ],"%d",&y);
      if(n != 1)
      {
        fprintf(stderr,"Error : Non-Number Input Data\n");
        continue;
      }
      if(i == 0)                                   //根を構築
      {
        q = (TREE *)malloc( sizeof(TREE) );
        q->data = y;
        q->right = NULL;
        q->left = NULL;
        root = q;
      }
      else
      {
        p = root;
        while(p != NULL)
        {
          if(y < p->data)
          {
            if(p->left != NULL)
              p = p->left;                      //左に移動
            else                                //葉を構築
            {
                q = (TREE *)malloc( sizeof(TREE) );
                q->data = y;
                q->left = NULL;
                q->right = NULL;
                p->left = q;                    //つなげる
                break;
            }
          }
          else if(y > p->data)
          {
            if(p->right != NULL)
              p = p->right;                    //右に移動
            else                               //葉を構築
            {
                q = (TREE *)malloc( sizeof(TREE) );
                q->data = y;
                q->left = NULL;
                q->right = NULL;
                p->right = q;                    //つなげる
                break;
            }
          }
        }
      }
    }
  }
}

//二分木を出力する関数
void print_tree(int depth, TREE *p)
{
  int i;

  if(p == NULL)
    return ;

  print_tree(depth+1,p->right);
  for(i = 0;i < depth; i++)
  {
    fprintf(stdout,"  ");
  }
  fprintf(stdout,"  %4d\n",p->data);
  print_tree(depth+1,p->left);

}

//新しいノードを挿入する関数
void insert_node(int y,TREE *p)
{
  TREE *q;

  if(p == NULL)
  {
    fprintf(stderr,"Error : There Is No Data\n");
    return ;
  }

  //ノード挿入
  while(p != NULL)
  {
    if(y < p->data)
    {
      if(p->left != NULL)
        p = p->left;                //左に移動
      else
      {
        q = (TREE *)malloc( sizeof(TREE) );
        q->data = y;
        q->left = NULL;
        q->right = NULL;
        p->left = q;                    //つなげる
        return ;
      }
    }
    else if(y > p->data)
    {
      if(p->right != NULL)
        p = p->right;                //右に移動
      else
      {
        q = (TREE *)malloc( sizeof(TREE) );
        q->data = y;
        q->left = NULL;
        q->right = NULL;
        p->right = q;                    //つなげる
        return ;
      }
    }
  }
}

//指定されたデータを持つノードを削除する関数
int delete_node(int y)
{
  TREE *n,*p_n,*l_b;
  int d, count = 1;
  n = root;
  p_n = NULL;
  d = 0;
  int Ccount  = 0;

  if(n == NULL)
  {
    fprintf(stderr,"Error : There Is No Data\n");
    return -1;
  }

  //削除対象のデータを見つける
  while(n != NULL && n->data != y)
  {
    if(n->data > y)
    {
      p_n = n;
      n = n->left;
      d = -1;
    }
    else
    {
      p_n = n;
      n = n->right;
      d = 1;
    }
  }

  if(n->data != y)
  {
    fprintf(stderr,"Error : Search Data Not Found\n");
    return 0;
  }

  if(n->left != NULL)
    Ccount++;
  if(n->right != NULL)
    Ccount++;
  switch(Ccount)
  {
    case 0:
      if(d == -1)
        p_n->left = NULL;
      else if(d == 1)
        p_n->right = NULL;
      break;

    case 1:
      if(d == -1)
        {
          if(n->left != NULL)
            p_n->left = n->left;
          if(n->right != NULL)
            p_n->left = n->right;
        }
      if(d == -1)
        {
          if(n->left != NULL)
            p_n->right = n->left;
          if(n->right != NULL)
            p_n->right = n->right;
        }
      break;

    case 2:
      l_b = n->left;
      while(l_b->right != NULL)
      {
        p_n = l_b;
        l_b = l_b->right;
        count = 0;
      }
      n->data = l_b->data;
      if(count == 0)
        p_n->right = NULL;
      else
        n->left = l_b->left;
      break;

  }

}

int main()
{
  int y;

  //二分木の初期化
  root = (TREE *)malloc( sizeof(TREE) );
  root = NULL;

  construct_tree();           //二分木の構築
  fprintf(stdout,"-----Tree Data-----\n");
  print_tree(0,root);         //二分木の出力

  //データの挿入
  fprintf(stdout,"-----Insert Node-----\n");
  fprintf(stdout,"Input Insert Data : ");
  scanf("%d",&y);
  insert_node(y,root);
  fprintf(stdout,"-----Tree Data-----\n");
  print_tree(0,root);

  //データの削除
  fprintf(stdout,"-----Delete-----\n");
  fprintf(stdout,"Input Delete Data : ");
  scanf("%d",&y);
  delete_node(y);
  fprintf(stdout,"-----Tree Data-----\n");
  print_tree(0,root);

  return 0;
}
