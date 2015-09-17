//http://www.spoj.com/problems/ONEZERO/

/*
The basic logic of this code is to first take an initial number (1) in the queue and then For each node, we add 
two more numbers to the queue, one of which is num*10 and the other is num*10+1, both modulo n (the given input).
We also keep a track of the parent of each number in the parent[] array, and also the number added after multiplying
the parent number by 10 in the value[] array.
The number pushed in the queue is modulo of the input number, and once we find the number we need (it will be 0 as 
modulo of the number will be =0), we backtrack using the help of the value[] and the parent[] arrays to print the
required number. For this, we use a Stack.
*/

#include<cstdio>
#include<stack>
#include<queue>
#include<cstdlib>

using namespace std;

queue<int> q;
int parent[20000];
int value[20000];

int temp,current;

int bfs(int n)
{
	q.push(1);
	parent[1]=0;
	while(!q.empty())
	{
		current=q.front();
		q.pop();
		if(current==0)// backtracking using Stack
		{
			stack<int> s;
			while(parent[current])    // parent[current] contains the number (or parent) from where "current" 
						  //originated
			{
				s.push(value[current]);    // value[current] contains the value(x) added after 
							   //Prevcurrent*10 + x to get the value of "current"
				current=parent[current];
			}
			s.push(1);
			while(!s.empty())
			{
				printf("%d",s.top());
				s.pop();
			}
			printf("\n");
			break;
		}
		temp=current*10;
		temp%=n;
		if(parent[temp]==-1)
		{
			parent[temp]=current;
			q.push(temp);
			value[temp]=0;
		}
		temp=(current*10)+1;
		temp%=n;
		if(parent[temp]==-1)
		{
			parent[temp]=current;
			q.push(temp);
			value[temp]=1;
		}
	}
}

int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while(!q.empty())
		{
			q.pop();
		}
		for(i=0;i<20000;i++)
		{
			parent[i]=-1;
		}
		bfs(n);
	}
}
