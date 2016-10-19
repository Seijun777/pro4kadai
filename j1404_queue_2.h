Q_type Q[Q_size];
int f,r;

void init_Q()
{
  f = 0;
  r = -1;
}

int stock_Q()
{
  if(r > f)
    return r - f ;
  if(r < f)
    return (Q_size + r) - f ;
}

void enqueue(Q_type d)
{
  if(stock_Q() < Q_size)
  {
    r++;
    if(r == Q_size)
      r = 0;
    Q[r] = d;
  }
  else
  {
    fprintf(stderr,"Error : queue is full\n");
    exit(1);
  }
}

Q_type dequeue()
{
  int i = 0;
  if( stock_Q() > 0)
  {
    i = f;
    f++;
    if( f == Q_size)
      f = 0;
    return Q[i];
  }
  else
  {
    fprintf(stderr,"Error : queue is empty\n");
    exit(1);
  }
}

void print_Q()
{
  getchar();

  fprintf(stderr,"Queue all data : ");
  while(stock_Q() != 0)
  {
    fprintf(stderr,"%c ",dequeue());
  }
}
