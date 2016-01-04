/*
http://www.spoj.com/problems/AGGRCOW/
 
Algorithm explanation - https://www.quora.com/What-is-the-correct-approach-to-solve-the-SPOJ-problem-Aggressive-cow/answer/Raziman-T-V
*/
 
#include<stdio.h>
#include<stdlib.h>
#define intd(x) scanf("%d",&x)
#define RUNbf(i,a,b) for(i=a;i<b;i++)
#define SWAP(a,b) a=(a+b)-(b=a)
int *pos;
int n,c;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int input()
{
	// to accept the stall locations in the array pos[]
	int i;
	RUNbf(i,0,n)
	{
		intd(pos[i]);
	}
	return 0;
}
int arrange(int x)
{
	int cowsPlaced=1,lastPlacedPos=pos[0];// placing first cow in the first position (lowest position)
	int i;
	RUNbf(i,1,n)
	{
		if((pos[i]-lastPlacedPos)>=x)
		{
			if(++cowsPlaced==c)
			return 1;
			lastPlacedPos=pos[i];
		}
	}
	return 0;
}
int main()
{
	int t=0,start=0,end=0,mid=0;
	intd(t);
	while(t--)
	{
		intd(n);
		intd(c);
		// dynamically declaring the array
		pos=(int *)malloc(n*sizeof(int));
		// taking input of stall locations
		input();
		// sort the array pos[] which is a pre-requisite of the function
		//sort();
		qsort(pos,n,sizeof(int),cmpfunc);
		// Perform Binary Search
		start=0;
		end=pos[n-1]-pos[0]+1;
		while((end-start)>1)
		{
			mid=(end+start)>>1;
			// finding the mid position of the positions
			// arrange(x) = 1 if it is possible to arrange 
			// C no of cows keeping at least x distance between them
			// arrange(x)=0 , if it is not possible
			//(arrange(mid)?start:end)=mid; // not working for some reason
			if(arrange(mid))
			{
				start=mid;
			}
			else
			{
				end=mid;
			}
		}
		printf("%d\n",start);
	}
}
 
