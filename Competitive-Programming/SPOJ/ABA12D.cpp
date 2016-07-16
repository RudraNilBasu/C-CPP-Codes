#include<stdio.h>
#include<math.h>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	int t,a,b,i;
	int oasis[38]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921, 1190281};
	map<int,int> mp;
	for(i=0;i<38;i++) {
		mp[ oasis[i] ]++;
	}
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		int count=0;
		for(i=0;i<38;i++) {
			if( oasis[i]>=a && oasis[i]<=b ) {
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
