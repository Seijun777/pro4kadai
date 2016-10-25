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
    return r-f +1;
  if(r < f)
    return (r + Q_size)-f +1;
  else
    return 0;
}

void enqueue(Q_type d)
{
  if(stock_Q() -1 < Q_size)
  {
    r++;
    if(r == Q_size -1)
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
  if( stock_Q() -1 > 0)
  {
    i = f;
    f++;
    if( f == Q_size-1 )
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
  fprintf(stdout,"All Array Data : ");
  while( stock_Q() -1 > 0)
    fprintf(stdout,"%c ",dequeue());
}
