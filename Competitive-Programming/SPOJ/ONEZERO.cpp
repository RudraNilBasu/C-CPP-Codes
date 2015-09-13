//http://www.spoj.com/problems/ONEZERO/

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
		if(current==0)
		{
			stack<int> s;
			while(parent[current])
			{
				s.push(value[current]);
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
