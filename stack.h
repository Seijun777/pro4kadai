stack_type stack[stack_size];
int sp;

void init_stack()
{	sp = -1; }

void push(stack_type d)
{
	if( sp < stack_size-1)
	{	stack[++sp] = d; }
	else
	{
		fprintf(stderr,"Error : stack full \n");
		exit(1);
	}
}

int stack_stock()
{	return sp + 1; }

stack_type pop()
{
	if( sp >= 0)
	{	return stack[sp--]; }
	else
	{
		fprintf(stderr,"Error : stack empty \n");
		exit(1);
	}
}

void print_stack()
{
	int i;
	
	fprintf(stderr,"stack data ");
	for( i = 0; i <= sp; i++)
	{
		fprintf(stderr,"%d ",stack[i]);
	}
	fprintf(stderr,"\n");
}