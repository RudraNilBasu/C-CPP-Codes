#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct block {
	int height;
	int width;
	int depth;
} block;
int max(int a, int b) {
	if(a>=b)
		return a;
	return b;
}
int min(int a, int b) {
	if(a<=b)
		return a;
	return b;
}
int compare(const void *a, const void *b) {
	// sorting on decreasing order of box base area
	return (((*(block *)b).width) * ((*(block *)b).depth)) - (((*(block *)a).width) * ((*(block *)a).depth));
	//return ((*(block *)b).depth * (*(block *)b).width)-((*(block *)a).depth*(*(block *)a).width);
//	return ( (*(block *)b).depth * (*(block *)b).width ) –
//		           ( (*(block *)a).depth * (*(block *)a).width );
}
int main() {
	while(1) {
		int n,h,x,y,i,j;
		scanf("%d",&n);
		if(n==0)
			break;
		block a[6*n];
		int lis[6*n];
		int k=0;
		for(i=0;i<n;i++) {
			scanf("%d %d %d",&h,&x,&y);
			a[k].height=h;
			a[k].width=x;
			a[k].depth=y;
			k++;
			a[k].height=x;
			a[k].width=max(y,h);
			a[k].depth=min(y,h);
			k++;
			a[k].height=y;
			a[k].width=max(x,h);
			a[k].depth=min(x,h);
			k++;
			// taking all 6 combinations
			a[k].height=h;
			a[k].width=y;
			a[k].depth=x;
			k++;
			a[k].height=x;
			a[k].width=min(y,h);
			a[k].depth=max(y,h);
			k++;
			a[k].height=y;
			a[k].width=min(x,h);
			a[k].depth=max(x,h);
			k++;
		}
		n=6*n;
		qsort(a,n,sizeof(a[0]),compare);
		/* 
		   display the blocks
		for(i=0;i<n;i++)
			printf("height = %d, base area = %d\n",a[i].height, (a[i].width*a[i].depth));
		 end of display
		 */
		for(i=0;i<n;i++) {
			lis[i]=a[i].height;
		}
		for(i=1;i<n;i++) {
			for(j=0;j<i;j++) {
				if( a[j].width > a[i].width && a[j].depth > a[i].depth  ) {
					lis[i] = max( lis[i] , lis[j]+a[i].height );
				}
			}
		}
		int maxH = -1;
		for(i=0;i<n;i++) {
			if(maxH<lis[i])
				maxH=lis[i];
		}
		printf("%d\n",maxH);
	}
	return 0;
}
