#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iostream>
#include<string>

#define ll long long int
#define ull unsigned ll

#define PI 3.14159265
#define DEBUG(X) cout << (X) << endl;

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
	int n,k,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
	}
	scanf("%d",&k);
	ll b[k];
	for(i=0;i<k;i++) {
		cin>>b[i];
	}
	i=0;
	// if all values of b[] are not a subset of a[] then NO
	ll sum=0;
	int m=0;
	int g[k]; // stores the intervals
	while(1) {
		if(m>=k || i>=n) {
			printf("NO\n");
			return 0;
		}
		sum+=a[i];
		if(sum>b[m]) {
			printf("NO\n");
			return 0;
		} else if(sum==b[m]) {
			g[m]=i;
			m++;
			sum=0;
		} else if(sum<b[m] && i==n-1 && m==k-1) {
			printf("NO\n");
			return 0;	
		}
		if(m==k && i==n-1) {
			break;
		}
		i++;
		if(i>=n) {
			printf("NO\n");
			return 0;
		}
	}
	g[k-1]=n-1;
	int j;
	m=0;
	int index;
	char dir;
	vector<char> str;
	vector<int> num;
	int st=0;
	int sz=0;
	for(j=0;j<k;j++) {
		vector<ll> d;
		map<ll,int> hash;
		// creating each intervals in vector d
		for(m=st;m<=g[j];m++) {
			d.push_back(a[m]);
			hash[a[m]]++;
		}
		while(d.size()>1) {
			// if all elements are same, then NO
			if(hash.size()==1 && d.size()>1) {
				printf("NO\n");
				return 0;
			}
			// finding the max and pos of max
			ll max=d[0];
			int pos=0;
			for(i=0;i<d.size();i++) {
				if(max<d[i]) {
					max=d[i];
					pos=i;
				}
			}
			/*
			cout<<"Elements are\n";
			for(i=0;i<d.size();i++) {
				cout<<d[i]<<endl;
			}
			cout<<"Max pos="<<pos<<endl;*/
			// if left is okay, eat left, else eat right
			while(1) {
				if(pos!=d.size()-1 && d[pos+1]<d[pos]) {
					// if there is any element less than max in the right
					d[pos+1]+=d[pos];
					index=sz+pos;
					dir='R';
					d.erase(d.begin()+pos);
					break;
				} else if(pos!=0 && d[pos-1]<d[pos]) {
					// if there is any element less than max in the left
					d[pos-1]+=d[pos];
					index=sz+pos;
					dir='L';
					d.erase(d.begin()+pos);
					break;
				} else {
					// this case: 2 2 1 2 2
					if(pos==0) {
						pos++;
					} else if(pos==d.size()-1) {
						pos--;
					} else {
						pos++;
					}
				}
			}
			num.push_back(index+1);
			str.push_back(dir);
		}
		st=g[j]+1;
		sz++;
	}
	printf("YES\n");
	for(i=0;i<str.size();i++) {
		cout<<num[i]<<' '<<str[i]<<endl;
	}
	return 0;
}

