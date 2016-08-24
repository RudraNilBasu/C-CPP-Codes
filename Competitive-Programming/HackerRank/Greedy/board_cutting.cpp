#include<stdio.h>
#include<algorithm>

#define ll long long int
#define MOD 1000000007

using namespace std;

int main()
{
	int t, posX, posY, x, y;
	ll m,n,i,maxX=-1,maxY=-1, cutX, cutY, sum, amt;
	bool isX;
	scanf("%d",&t);
	while(t--) {
		sum=0;
		cutX=0;
		cutY=0;
		amt=0;
		scanf("%lld %lld",&m, &n);
		ll cx[m-1], cy[n-1];
		for(i=0;i<m-1;i++) {
			scanf("%lld",&cx[i]);
		}
		for(i=0;i<n-1;i++) {
			scanf("%lld",&cy[i]);
		}
		sort(cx, cx+m-1);
		reverse(cx, cx+m-1);
		sort(cy, cy+n-1);
		reverse(cy, cy+n-1);
		x=0;
		y=0;
		while(1) {
			// find max in cx and cy
			maxX=-1;
			maxY=-1;
			posX=-1;
			posY=-1;
			if(x>=m-1) {
				maxX=-1;
			} else {
				maxX=cx[x];
			}
			if(y>=n-1) {
				maxY=-1;
			} else {
				maxY=cy[y];
			}
			if(maxX==-1 && maxY==-1) {
				break;
			}
			amt=0;
			if(maxX==maxY) {
				if( cutX>cutY ) {
					isX=true;
					amt=maxX;
					cutX++;
					x++;
				} else {
					isX=false;
					amt=maxY;
					cutY++;
					y++;
				}
			} else if(maxX>maxY) {
				// cut through maxX
				isX=true;
				amt=maxX;
				cutX++;
				//cx[posX]=-1;
				x++;
			} else {
				// cut through maxY
				isX=false;
				amt=maxY;
				cutY++;
				//cy[posY]=-1;
				y++;
			}
			if(isX) {
				sum = (sum%MOD + ((cutY+1)*amt)%MOD)%MOD;
			} else {
				sum = (sum%MOD + ((cutX+1)*amt)%MOD )%MOD;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
