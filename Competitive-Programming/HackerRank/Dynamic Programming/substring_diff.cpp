#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int max2(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int max3(int a, int b, int c)
{
    return max2(a, max2(b, c));
}

char p[1501],q[1501];
int s,n;

int findBest(int i, int j)
{
    int i1, j1, l=0, best, func;
    i1=i;
    j1=j;
    best=0;
    func=0;
    while(1) {
        if( (i1+l)>=n || (j1+l)>=n ) {
            best=max2(best, l);
            break;
        }
        
        if(p[i1+l]!=q[j1+l]) {
            func++;
        }
        
        if(func>s) {
            best = max2(best, l);
            // ignoring all the prefix from p[i1]
            // and q[j1] when they are of same 
            // values (basically they do not contribute)
            while(p[i1]==q[j1]) {
                i1++;
                j1++;
                l--;
            }
            // now we are on the pos where p[i1]!=q[j1]
            // and M(i1, j1, l)=func
            i1++;
            j1++;
            func--;
        } else {
            l++;
        }
    }
    return best;
}

int main() {
    int t,i,j,l,func,size,max=-1;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d %s %s",&s,p,q);
        max=-1;
        n=strlen(p);
        int ans=0;
        for(i=0;i<n;i++) {
            ans=max3(ans, findBest(0,i), findBest(i,0));
        }
        printf("%d\n",ans);
    }
    return 0;
}
