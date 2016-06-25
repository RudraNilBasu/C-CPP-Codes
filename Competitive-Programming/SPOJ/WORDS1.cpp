#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int ab(int a) 
{
	if(a>=0)
		return a;
	return a*-1;
}
int graph[26][26];
int dfs(int node)
{
	int i;
	for(i=0;i<26;i++) {
		if(graph[node][i]>0) {
			graph[node][i]--;
			dfs(i);
		}
	}
}
int main()
{
	int t,i,j;
	int deg[2][26]; // storing the in degree and out degree (0 -> out degree  1-> in degree)
	char temp[1001];
	scanf("%d",&t);
	while(t--) {
		memset(graph,0,sizeof(graph));
		memset(deg,0,sizeof(deg));
		int m;
		scanf("%d",&m);
		while(m--) {
			scanf("%s",temp);
			// creating the graph
			graph[temp[0]-'a'][temp[strlen(temp)-1]-'a']++;
			deg[0][temp[0]-'a']++; // out degree
			deg[1][temp[strlen(temp)-1]-'a']++; // in degree
		}
		/* 
		   checking if for each degree - 
		   * there are exactly 2 nodes with |inDeg(a)-outDeg(a)| = 1
		   * rest all nodes have |inDeg(a)-outDeg(a)| = 0 (inDeg==outDeg)

		   else, the answer is NO.
		*/
		int c=0,flag=0;
		for(i=0;i<26 && !flag;i++) {
			int diff=ab(deg[0][i]-deg[1][i]);
			if(diff==1) {
				c++;
				if(c>2) {
					flag=1;
				}
			} else if(diff>1) {
				flag=1;
			}
		}
		if(flag) {
			printf("The door cannot be opened.\n");
			continue;
		}
		/*
		 Checking for the condition when two disconnected graphs are present with only two vertices have diff==1
		 */
		// finding the starting vertex (with outDeg=1 and diff==1)
		int start=-1;
		for(i=0;i<26;i++) {
			if(deg[0][i]==1 && deg[1][i]==0) {
				start=i;
				break;
			}
		}
		if(start==-1) {
			for(i=0;i<26;i++) {
				if((deg[0][i]-deg[1][i])==1) {
					start=i;
					break;
				}
			}
		}
		if(start==-1) {
			for(i=0;i<26;i++) {
				if(deg[0][i]>=1) {
					start=i;
					break;
				}
			}
		}
		// dfs on the graph
		dfs(start);
		// checking if any vertices in uncovered
		flag=0;
		for(i=0;i<26;i++) {
			for(j=0;j<26;j++) {
				if(graph[i][j]!=0) {
					//printf("this one exists %c---%c\n",(i+'a'),(j+'a'));
					flag=1;
				}
			}
		}
		if(flag) {
			printf("The door cannot be opened.\n");
		} else {
			printf("Ordering is possible.\n");
		}
	}
	return 0;
}
