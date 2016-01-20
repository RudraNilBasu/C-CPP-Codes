#include<stdio.h>
typedef struct
{
    int left;
    int right;
    int best;
    int sum;
} element;
short int arr[50000];
element M[131200];
inline int max(int a,int b)
{
    return (a>b)?a:b;
}
element combine(element *l, element *r)
{
    //printf("2\n");
    element e;
    e.left=l->left;
    if(l->sum+r->left > e.left)
    {
        e.left = l->sum+r->left;
    }
    e.right=r->right;
    if(r->sum+l->right>e.right)
    {
        e.right=r->sum+l->right;
    }
    e.best=max(l->right+r->left,max(l->best,r->best));
    e.sum=l->sum+r->sum;
    return e;
}
element query(int si,int ss,int se,int qs,int qe)
{
    //printf("1\n");
    if(qs<=ss && se<=qe)
    {
        return M[si];
    }
    int mid=(ss+se)>>1;
    int left_child = si<<1;
    int right_child = (si<<1)+1;
    if(qe<=mid)
    {
        return query(left_child,ss,mid,qs,qe);
    }
    if(qs>mid)
    {
        return query(right_child,mid+1,se,qs,qe);
    }
    element p=query(left_child,ss,mid,qs,qe);;
    element q=query(right_child,mid+1,se,qs,qe);
    return combine(&p,&q);
}
int construct(int si,int ss,int se)
{
    if(ss==se)
    {
        M[si].sum=arr[ss];
        M[si].left=arr[ss];
        M[si].right=arr[ss];
        M[si].best=arr[ss];
    }
    else
    {
        int mid=(ss+se)>>1;
        int left_child=2*si;
        int right_child=2*si+1;
        construct(left_child,ss,mid);
        construct(right_child,mid+1,se);
        M[si]=combine(&M[left_child],&M[right_child]);
    }
}
int main()
{
    int n,i,m,qs,qe;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%hd",&arr[i]);
    }
    construct(1,0,n-1);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&qs,&qe);
        element e=query(1,0,n-1,qs-1,qe-1);
        printf("%d\n",e.best);
    }
    return 0;
}

