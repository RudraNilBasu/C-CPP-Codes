#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,n,i;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        ll b[n];
        ll a[n];
        for(i=0;i<n;i++) {
            scanf("%lld",&b[i]);
        }
        for(i=0;i<n;i++) {
            scanf("%lld",&a[i]);
        }
        bool visited[n];
        //int nos[4]={a[0], a[0]+b[0], a[0]+b[1], a[0]+b[0]+b[1]};
        ll len;
        if(n==1) {
            len=2;
        } else {
            len=4;
        }
        ll nos[len];
        nos[0]=a[0];
        nos[1]=a[0]+b[0];
        if(len==4) {
            nos[2]=a[0]+b[1];
            nos[3]=a[0]+b[0]+b[1];
        }
        bool status[len];
        for(ll k=0;k<len;k++) {
            memset(visited, false, sizeof(visited));
            ll no=nos[k];
            // IMP set value of visited here
            if(k==1) {
                visited[0]=true;
            }
            if(k==2) {
                visited[1]=true;
            }
            if(k==3) {
                visited[0]=true;
                visited[1]=true;
            }
            ll flag1=0;
            for(i=1;i<n;i++) {
                if( a[i]> no ) {
                    status[k]=false;
                    flag1=1;
                    break;
                }
                // itself
                if(a[i]==no) {
                    continue;
                }
                // i-1
                if( !visited[i-1] && (a[i]+b[i-1])==no ) {
                    visited[i-1]=true;
                    continue;
                }
                // i-1, i
                if( !visited[i-1] && !visited[i] && (a[i]+b[i-1]+b[i])==no ) {
                    visited[i-1]=true;
                    visited[i]=true;
                    continue;
                }
                // i-1 , i+1
                if( i!=(n-1) && !visited[i-1] && !visited[i+1] && (a[i]+b[i+1]+b[i-1])==no ) {
                    visited[i+1]=true;
                    visited[i-1]=true;
                    continue;
                }
                // i, i-1, i+1
                if( i!=(n-1) && !visited[i-1] && !visited[i] && !visited[i+1] && (a[i]+b[i-1]+b[i]+b[i+1])==no ) {
                    visited[i-1]=true;
                    visited[i+1]=true;
                    visited[i]=true;
                    continue;
                }
                // i
                if(!visited[i] && (a[i]+b[i])==no) {
                    visited[i]=true;
                    continue;
                }
                // i+1
                if( i!=(n-1) && !visited[i+1] && (a[i]+b[i+1])==no) {
                    visited[i+1]=true;
                    continue;
                }
                // i, i+1
                if( i!=(n-1) && !visited[i] && !visited[i+1] && (a[i]+b[i+1]+b[i])==no ) {
                    visited[i+1]=true;
                    visited[i]=true;
                    continue;
                }

                status[k]=false;
                flag1=1;
                break;
            }
            ll flag=0;
            for(i=0;i<n;i++) {
                if(visited[i]==false) {
                    flag=1;
                    break;
                }
            }
            //printf("%lld %lld\n",flag,flag1);
            if(flag || flag1) {
                status[k]=false;
            } else {
                status[k]=true;
            }
        }
        ll max=-1;
        for(i=0;i<len;i++) {
            if(status[i]==true && max<nos[i]) {
                max=nos[i];
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}
