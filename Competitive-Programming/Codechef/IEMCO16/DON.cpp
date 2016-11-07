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

int lis(int arr[], int n, int *max_ref)
{
	if(n==1)
		return 1;
	int res, max_ending_here = 1;
	for (int i = 1; i < n; i++)
	{
		res = lis(arr, i, max_ref);
		if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}
	if (*max_ref < max_ending_here)
		       *max_ref = max_ending_here;
	return max_ending_here;
}

int calc(int a[], int n, int i, int sum, int prev)
{
	if(i==n-1) {
		if(a[i]==3)
			return 1;
		if(prev=3)
			return 0;
		return -1;
	}
	if(i>=n)
		return 0;
}

int main()
{
	int t,i,j;
	char s[100001];
	t=1;
	//scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		int n=strlen(s);
		/*
		int a[n];
		for(i=0;i<n;i++) {
			if(s[i]=='I') {
				a[i]=1;
			} else if(s[i]=='E') {
				a[i]=2;
			} else if(s[i]=='M') {
				a[i]=3;
			}
		}
		*/
		int lis[n];
		int l_i=0, l_e=0, l_m=0;
		memset(lis, 0, sizeof(lis));
		for(i=n-1;i>=0;i--) {
			if(s[i]=='M') {
				l_m++;
			}
			if(s[i]=='E') {
				if(l_m>0) {
					if(l_e==0) {
						l_e=l_m+1;
					} else {
						l_e=max(l_e+1, l_m+1);
					}
				}
			}
			if(s[i]=='I') {
				if(l_e>0) {
					if(l_i==0) {
						l_i=l_e+1;
					} else	{
						l_i=max(l_i+1, l_e+1);
					}
				}
			}
		}
		cout<<l_i<<endl;
		/*
		for(i=0;i<n;i++) {
			if(a[i]==1) {
				calc(a,n,i+1,1,1);
			}
		}
		int dist=0;
		int max=0;
		int count;
		for(i=0;i<n;) {
			if(a[i]==1) {
				count=0;
				for(j=i+1;j<n;j++) {
					if(a[j]==1||)
						if(a[j]==3) {

						}
				}
				i=findNext(a,i,n);
			} else {
				i++;
			}
		}
		*/
		/*
		int max=1;
		lis(a,n,&max);
		cout<<max<<endl;
		*/
		/*
		bool is=false;
		bool check=false;
		int dist,maxDist;
		maxDist=0;
		int mi,mj;
		for(i=0;i<n;i++) {
			if(a[i]==1) {
				check=false;
				is=false;
				for(j=i+1;j<n;j++) {
					if(!check) {
						if(a[j]==2)
							is=true;
						if(a[j]==3 && is)
							check=true;
						if(a[j]==3 && !is) {
							check=false;
							break;
						}
					} else {
						if(a[j]!=3) {
							//DEBUG(i)
							//DEBUG(j)
							dist=j-1-i+1;
							if(dist>maxDist) {
								maxDist=dist;
								i=j-1;
								mi=i;
								mj=j;
								check=false;
								//DEBUG(maxDist)
								break;
							}
						}
					}
				}
				if(check) {
					DEBUG(i)
					DEBUG(n-1)
					dist=n-1-i+1;
					if(dist>maxDist) {
						mi=i;
						mj=n-1;
						maxDist=dist;
						i=n;
						break;
					}
				}
			}
		}
		cout<<mi<<" "<<mj<<endl;
		printf("%d\n",maxDist);
		*/
	}
	return 0;
}

