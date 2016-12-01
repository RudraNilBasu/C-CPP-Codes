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
#define SWAP(A,B) (A)=((A)+(B))-((B)=(A))

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define DEBUGL(x) std::cerr << "In " << __FILE__ << " at line " << __LINE__ << #x << ' = ' << x << std::endl;

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

int main()
{
	int a[5][5];
	int i,j,l,m,k;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	int ssum=0,smax=0;
	// produce all PnCs
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(j==i)
				continue;
			for(k=0;k<5;k++) {
				if(k==i||k==j)
					continue;
				for(l=0;l<5;l++) {
					if(l==i||l==j||l==k)
						continue;
					for(m=0;m<5;m++) {
						if(m==i||m==j||m==k||m==l)
							continue;
						ssum=a[j][k]+a[k][j]+a[j][i]+a[i][j];
						ssum+=2*(a[k][l]+a[l][k]+a[l][m]+a[m][l]);
						if(ssum>smax) {
							smax=ssum;
						}
					}
				}
			}
		}
	}
	cout<<smax<<endl;
	// waste
	/*
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	int mx=0,smx=0,s,mi,mj,smi,smj;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(i!=j) {
				s=a[i][j]+a[j][i];
				if(s>mx) {
					mx=s;
					mi=i;
					mj=j;
				}
			}
		}
	}
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(i!=j) {
				s=a[i][j]+a[j][i];
				if(s>smx && s!=mx) {
					smx=s;
					smi=i;
					smj=j;
				}
			}
		}
	}
	int ans=0;
	cout<<mi<<mj<<endl;
	cout<<smi<<smj<<endl;
	ans=2*(a[mi][mj]+a[mj][mi]+a[smi][smj]+a[smj][smi]);
	cout<<ans<<endl;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(i==smi||i==mi||i==smj||i==mj)
				continue;
			if(j==smi||j==smj||j==mi||j==mj)
				continue;
			ans+=a[i][j]+a[j][i];
			//ans+=a[i][j]+a[j][i];
		}
	}
	cout<<ans<<endl;
	*/
	return 0;
}

