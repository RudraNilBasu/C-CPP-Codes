/* Find the sum of all a[i] & a[j] pairs in an array for all i<j
where a[0...n-1] is an array .
& is the bitwise AND Operator
Expected Runtime - O(n)
Assumption - The numbers are 32 bit
Link - http://www.geeksforgeeks.org/calculate-sum-of-bitwise-and-of-all-pairs/
*/
#include<stdio.h>
#include<math.h>
int pairs(int a[],int n)
{
	int i,j,k,ans=0;
	for(i=0;i<32;i++) // traversing through all the 32 bits
	{
		k=0; // counter to count how many 1s are present in the ith bit
		for(j=0;j<n;j++)
		{
			if(a[j]&(1<<i))
			{
				k++;
			}
		}
		// if the number of 1s in the ith bit of all nos in the array
		// is k, then number of pairs possible is kC2
		// each of this pair adds 2^i to the sum
		// We add 2^i * kC2 to the answer
		ans+=(1<<i)*(k*(k-1)/2);
	}
	return ans;
}
int main()
{
	int a[]={5,10,15};
	int n=sizeof(a)/sizeof(int);// calculating the array size
	int ans=pairs(a,n);
	printf("%d\n",ans);
	return 0;
}
