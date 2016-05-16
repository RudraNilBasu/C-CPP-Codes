#include<stdio.h>
int main()
{
	int diff;
	printf("1\n3 1 2 2\n3 4 4 5\n");fflush(stdout);
	scanf("%d",&diff);
	if(diff==0)
	{
		printf("2\n3\n");fflush(stdout);
		return 0;
	}
	else if(diff==-1)
	{
		printf("2\n5\n");fflush(stdout);
		return 0;
	}	
	else if(diff==-2)
	{
		printf("2\n4\n");fflush(stdout);
		return 0;
	}
	else if(diff==1)
	{
		printf("2\n1\n");fflush(stdout);
		return 0;
	}
	else if(diff==2)
	{
		printf("2\n2\n");fflush(stdout);
		return 0;
	}
	return 0;
}
