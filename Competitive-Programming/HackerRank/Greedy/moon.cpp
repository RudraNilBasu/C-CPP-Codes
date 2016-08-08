#include<stdio.h>
#include<vector>
#include<queue>

#define ll long long int

using namespace std;

int no;

vector<int> graph[100001];
int dfs(int node, bool covered[])
{
    covered[node]=true;
    no++;
    int i;
    for(i=0;i<graph[node].size();i++) {
        if( !covered[ graph[node][i] ] ) {
            dfs(graph[node][i], covered);
        }
    }
    return 0;
}

vector<int> ans;

int main()
{
    int n,i,j,x,y;

    scanf("%d %d",&n,&i);

    //vector<int> graph[n];
    bool covered[n];

    for(j=0;j<n;j++) {
        covered[j]=false;
    }

    for(j=1;j<=i;j++) {
        scanf("%d %d",&x,&y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    ll result=0;

    int dfsNumb=1;
    queue<int> q;
    int distSet[n];
    int freq;
    while(1) {
/*
        int u=-1;
        for(j=0;j<n;j++) {
            if(covered[j]==false) {
                u=j;
                break;
            }
        }
        if(u==-1) {
            break;
        }
        no=0;
        dfs(j, covered);
        //printf("%d\n",no);
        ans.push_back(no);
*/

        int u=-1;

        for(j=0;j<n;j++) {
            if(covered[j]==false && graph[j].size()==0) {
                covered[j]=true;
                ans.push_back(1);
                continue;
            }
            if(covered[j]==false && graph[j].size()!=0) {
                u=j;
                break;
            }
        }

        if(u==-1) {
            break;
        }
        covered[u]=true;
        distSet[u]=dfsNumb;
        freq=1;

        q.push(u);
        while(!q.empty()) {
            int num=q.front();
            q.pop();
            for(j=0;j<graph[num].size();j++) {
                if( !covered[graph[num][j]]  ) {
                    covered[graph[num][j]]=true;
                    distSet[graph[num][j]]=dfsNumb;
                    q.push(graph[num][j]);
                    freq++;
                }
            }
        }
        dfsNumb++;
        ans.push_back(freq);
        freq=0;

    }

/*
    for(j=0;j<ans.size();j++) {
        printf("%d\n",ans[j]);
    }
*/
    if(ans.size()<=1) {
        result=0;
    } else {
        /*
        for(i=0;i<ans.size();i++) {
            for(j=i+1;j<ans.size();j++) {
                result += (ans[i]*ans[j]);
            }
        }
        */
        ll suffix_sum=0;
        result=0;
        for(i=ans.size()-1;i>=1;i--) {
            suffix_sum+=ans[i];
            result += suffix_sum*ans[i-1];
        }
    }
    printf("%lld\n",result);

    return 0;
}
