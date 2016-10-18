#include<stdio.h>
#include<stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include"stack.h"

int main()
{
	int ch,pch,small;
	small = 0;

	init_stack();
	fprintf(stdout,"Please enter English text: \n");
	pch = ' ';

	while( ( ch = getchar() ) !='\n')
	{
		if(ch != ' ' )
		{
			if(pch == ' ')
				small = 1;
			if(small == 1)
				push(ch);
			else
				fprintf(stdout,format,ch);
		}
		else
		{
			if(small == 1)
			{
				while(stack_stock() > 0)
				{
					fprintf(stdout,format,pop()	);
				}
			}
			fprintf(stdout,format,ch);
		}
		pch = ch;
	}

	while(stack_stock() > 0)
	{
		fprintf(stdout,format,pop()	);
	}

	fprintf(stdout,"\n----------Finish---------\n");

	return 0;
}
