#include<stdio.h>
using namespace std;
/*
bool check(int a[], int i, int b[], int j)
{
    if(i==j) {
        if(a[i] == b[j]) {
            return check(a,i+1,b,j+1);
        } else if(a[i]==1 && b[j]==0) {
            return check(a,i+1,b,j);
        } else if(a[i]==0 && b[j]==1) {
            return check(a,i,b,j+1);
        }
    } else if(i==j+1) {
        if(a[i]== b[j]) {
            return check(a,i+1, b, j+1);
        } else if(a[i]==1 && b[j]==0) {
            return check(a,i+1, b, j);
        } else if(a[i]==0 && b[j]==1) {
            return check(a,i,b,j+1);
        }
    } else if(j==i+1) {
        if(a[i+1]==1) {
            return false;
        } else if(b[j]==1) {
            return check(a,i+2, b, j+1);
        } else if(a[i+1]==0 && b[j]==0) {
            return check(a,i+2, b, j+1);
        }
    } else if(i==j+2) {
        return check(a,i+3, b, j+1);
    } else if(j==i+2)
}
*/

bool check2(char a[], char b[], int n)
{
    int i,j;
    int sum=0;
    for(i=0;i<n;i++) {
        if(a[i]) {
            sum++;
        }
        if(b[i]) {
            sum++;
        }
    }
    if(sum%2) {
        return false;
    }
    if(sum==(2*n)) {
        return true;
    }

    int sum_so_far=0;
    for(i=0;i<n;i++) {
        sum_so_far+=(1-a[i]);
        if(i>0 && a[i] && b[i]) {
            if(sum_so_far%2) {
                return false;
            }
        }
        if(i>0 && a[i] && b[i-1]) {
            if( sum_so_far%2 ) {
                return false;
            }
        }
        sum_so_far+=(1-b[i]);
    }
    return true;
}


int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        char a[n+1],b[n+1];
        scanf("%s %s",a,b);
        for(i=0;i<n;i++) {
            a[i]-='0';
            b[i]-='0';
        }
        /*
        for(i=0;i<n;i++) {
            scanf("%d",b+i);
        }
        */
        if(check2(a,b,n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
