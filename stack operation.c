include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1,inp_array[size];
void push();
void pop();
void show();
int main()
{
	int choice;
	while(1)
	{
		printf("\nperform operations on the stack:");
		printf("\n1.push the element\n2.pop the element \n3.show\n4.end");
		printf("\n\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			show();
			break;
			case 4:
			exit(0);
			default:
			printf("\ninvalid choice!!");
		}
	}
}
void push()
{
	int x;
	if(top==size-1)
	{
		printf("\noverflow!!");
	}
	else
	{
		printf("\npopped element:%d",inp_array[top]);
		top=top-1;
	}
}
void show()
{
	if(top==-1)
	{
		printf("\nunder flow!!");
	}
	else
	{
		int i;
		printf("\nelements present in the stack:\n");
		for(i=top;i>=0;i--)
		printf("%d\n",inp_array[i]);
	}
}
