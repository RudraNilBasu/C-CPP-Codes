#include<stdio.h>
#include<string.h>
#include<limits.h>
using namespace std;
int n;
int findNext(int index, char str[])
{
    int i=index;
    for(;i<n;i++) {
        if(str[i]=='1') {
            return i;
        }
    }
    return -1;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        char str[n+1];
        scanf("%s",str);
        int coor[n];
        for(i=0;i<n;i++) {
            scanf("%d",&coor[i]);
        }
        int l,r;
        int sum=0;
        l = findNext(0, str);
        for(i=1;i<=l;i++) {
            sum+=(coor[i]-coor[i-1]);
        }
        int min=INT_MAX;
        while(1) {
            r=findNext(l+1, str);
            if(r==-1) {
                break;
            }
            if(r==l+1) {
                l=r;
                continue;
            }
            int sum1=0,sum2=0;
            min=INT_MAX;
            for(i=l;i<r;i++) {
                sum1=0;
                sum2=0;
                for(j=l+1;j<=i;j++) {
                    sum1+=(coor[j]-coor[j-1]);
                }
                for(j=(i+2);j<=r;j++) {
                    sum2+=(coor[j]-coor[j-1]);
                }
                if(min>(sum1+sum2)) {
                    min = (sum1+sum2);
                }
            }
            sum+=min;
            l=r;
        }

        for(i=l+1;i<n;i++) {
            sum+=(coor[i]-coor[i-1]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
