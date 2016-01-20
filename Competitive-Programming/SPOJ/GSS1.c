//http://www.spoj.com/problems/GSS1/
#include <stdio.h>

typedef struct{
    int sum;
    int best;
    int left;
    int right;
}element;

short int arr[50000];
element M[131200];

inline int max(int a,int b)
{
    return (a>b)?a:b;
}

element combine(element *l,element *r)
{
    element e;
    e.left = l->left;
    if(l->sum+r->left>e.left)
        e.left = l->sum + r->left;
    e.right = r->right;
    if(r->sum+l->right>e.right)
        e.right = r->sum + l->right;
    e.best = max(l->right+r->left,max(l->best,r->best));
    e.sum = l->sum + r->sum;
    return e;
}

void initialise(int node,int b,int e)
{
    if(b==e)
    {
        M[node].sum = arr[b];
        M[node].right = arr[b];
        M[node].left = arr[b];
        M[node].best = arr[b];
    }
    else{
        int mid = (b+e)>>1;
        int left_child = 2*node;
        int right_child = 2*node+1;
        initialise(left_child,b,mid);
        initialise(right_child,mid+1,e);
        M[node] = combine(&M[left_child],&M[right_child]);
    }
}

element query(int node,int b,int e,int l,int r)
{
    if((l<=b)&&(e<=r))
        return M[node];
    int mid = (b+e)>>1;
    int left_child = node<<1;
    int right_child = (node<<1)+1;
    if(r<=mid)
        return query(left_child,b,mid,l,r);
    if(l>mid)
        return query(right_child,mid+1,e,l,r);
    element p = query(left_child,b,mid,l,r);
    element q = query(right_child,mid+1,e,l,r);
    return combine(&p,&q);
}

int main(void)
{
    int i,n,m,x,y;
    element e;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%hd",&arr[i]);
    initialise(1,0,n-1);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        e = query(1,0,n-1,x-1,y-1);
        printf("%d\n",e.best);
    }
    return 0;
}
