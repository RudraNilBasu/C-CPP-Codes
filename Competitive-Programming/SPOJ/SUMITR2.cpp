#define p(x) scanf("%d",&x)
#define x(a,b) a>b?a:b
main(t,n,i,j,k){int a[100][100];p(t);while(t--){p(n);for(i=0;i<n;i++)for(j=0;j<=i;j++)p(a[i][j]);k=n-1;for(i=n-1;i>0;i--){k--;for(j=k;j>=0;j--)a[i-1][j]+=x(a[i][j],a[i][j+1]);}printf("%d\n",a[0][0]);}}