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

int main()
{
  //二分木の初期化
  root = (TREE *)malloc( sizeof(TREE) );
  root = NULL;

  construct_tree();           //二分木の構築
  print_tree(0,root);         //二分木の出力
  return 0;
}
