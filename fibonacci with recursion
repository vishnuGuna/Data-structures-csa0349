#include<stdio.h>
int main()
{
	int array[100],search,c,number;
	printf("enter the number of elements in array\n");
	scanf("%d",number);
	printf("enter %d numbers\n",number);
	for(c=0;c<number;c++)
	scanf("%d",&array[c]);
	printf("enter the number to search\n");
	scanf("%d",search);
	for(c=0;c<number;c++)
	{
		if(array[c]==search)
		{
			printf("%d is present at location %D.\n",search,c+1);
			break;
		}
	}
	if(c==number)
	printf("%d is not present in array.\n",search);
	return 0;
}
