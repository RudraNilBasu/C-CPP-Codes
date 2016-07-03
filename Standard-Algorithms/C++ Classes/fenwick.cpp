#include<stdio.h>
using namespace std;
//template<class T, class V>
class FenwickTree
{
public:
	int *FTree;
	int len;
	FenwickTree(int arr[],int size)
	{
		FTree = new int[size+1];
		create(arr,size);
	}
	void updateTr(int val, int index)
	{
		update(val,index);
	}
	int getSum(int index)
	{
		return sum(index);
	}
private:
	int sum(int index)
	{
		index=index+1;
		int sum=0;
		while(index>0) {
			sum+=FTree[index];
			index=getParent(index);
		}
		return sum;
	}
	int getParent(int index) 
	{
		return index - (index & -index);
	}
	int getNext(int index)
	{
		return index + ( index & -index );
	}
	void update(int val, int index)
	{
		while( index < len ) {
			FTree[index]+=val;
			index=getNext(index);
		}
	}
	void reset(int size)
	{
		int i;
		for(i=0;i<size;i++) {
			FTree[i]=0;
		}
	}
	void create(int arr[], int size)
	{
		reset(size+1);
		int i;
		len=size+1;
		for(i=1;i<size+1;i++) {
			update(arr[i-1],i);
		}
	}
};
int main()
{
	int a[]={3,2,-1,6,5,4,-3,3,7,2,3};
	int size=sizeof(a)/sizeof(a[0]);
	FenwickTree ftr(a,size);
	printf("%d\n",ftr.getSum(10));
	return 0;
}
