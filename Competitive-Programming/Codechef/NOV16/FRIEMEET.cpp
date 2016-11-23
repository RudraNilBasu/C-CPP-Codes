#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iostream>

#define ll long long int
#define ull unsigned ll

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

// inputs
#define inpd(x) scanf("%d",&x)
#define inpc(x) scanf("%c",&x)

using namespace std;

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int max3(int a, int b, int c)
{
	return max(a,max(b,c));
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

#define MAX 100100

typedef struct node {
	int dest;
	int wt;
}node;

vector<node> graph[MAX];
bool isSpecial[MAX];
int sum[MAX];

ll total;
int m,n;


ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void dfs(int v, int parent)
{
	if(isSpecial[v]) {
		sum[v]=1;
	} else {
		sum[v]=0;
	}
	int i;
	for(i=0;i<graph[v].size();i++) {
		node temp=graph[v][i];
		if(temp.dest==parent) {
			continue;
		}
		dfs(temp.dest, v);
		sum[v]=sum[v]+sum[temp.dest];
		total+=2*(ll)(sum[temp.dest]*(m-sum[temp.dest]))*temp.wt;
	}
	//total=total+(2*sum[v]*(m-sum[v]));
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--) {
		int v,u,l,sum;
		//sum=0;
		scanf("%d %d",&n,&m);
		int a[m];
		for(i=0;i<=n;i++) {
			graph[i].clear();
		}
		//vector<node> g[n+1];
		
		//int graph[n+1][n+1];
		//memset(graph, -1, sizeof(graph));
		for(i=0;i<n-1;i++) {
			scanf("%d %d %d",&v,&u,&l);
			node temp;
			temp.dest=v;
			temp.wt=l;
			graph[u].push_back(temp);
			temp.dest=u;
			graph[v].push_back(temp);
			//graph[u][v]=l;
			//graph[v][u]=l;
		}
		memset(isSpecial, false, sizeof(isSpecial));
		for(i=0;i<m;i++) {
			scanf("%d",a+i);
			isSpecial[a[i]]=true;
		}
		total=0;
		dfs(1,-1);
		ll num=total;
		ll deno=m*(ll)(m);
		ll g=__gcd(num,deno);
		num/=g;
		deno/=g;
		cout<<num<<' '<<deno<<endl;
	}
	return 0;
}

