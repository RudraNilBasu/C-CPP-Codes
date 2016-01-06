/*
http://www.spoj.com/problems/NY10A/
Solution of Penny's Game in SPOJ
*/
/*
NOTE : The Problem can be made a lot simpler by using string functions, namely
substring and compare, but due to some unusual problems, I had to use the hard way (extracting each character
and comparing). It will be revised later.
*/
#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<stdlib.h>

#define intd(x) scanf("%d",&x)
#define intstr(x) scanf("%s",x)
#define RUNbf(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
	int p,n,i,count=0;
	char seq[41];
	//string seq;
	intd(p); // no of test cases
	while(p--)
	{
		map<string,int> coins; // initialising the map
		coins["TTT"]=0;
		coins["TTH"]=0;
		coins["THT"]=0;
		coins["THH"]=0;
		coins["HTT"]=0;
		coins["HTH"]=0;
		coins["HHT"]=0;
		coins["HHH"]=0;
		intd(n); // data set number
		intstr(seq); // input of the sequence
		count++;
		RUNbf(i,0,strlen(seq)-2)
		{
			char o1=seq[i];
			char o2=seq[i+1];
			char o3=seq[i+2];
			// incrementing the coins[] value according to the input
			if(o1=='T'&&o2=='T'&&o3=='T')
			{
				coins["TTT"]++;
			}
			else if(o1=='T'&&o2=='T'&&o3=='H')
			{
				coins["TTH"]++;
			}
			else if(o1=='T'&&o2=='H'&&o3=='T')
			{
				coins["THT"]++;
			}
			else if(o1=='T'&&o2=='H'&&o3=='H')
			{
				coins["THH"]++;
			}
			else if(o1=='H'&&o2=='T'&&o3=='T')
			{
				coins["HTT"]++;
			}
			else if(o1=='H'&&o2=='T'&&o3=='H')
			{
				coins["HTH"]++;
			}
			else if(o1=='H'&&o2=='H'&&o3=='T')
			{
				coins["HHT"]++;
			}
			else if(o1=='H'&&o2=='H'&&o3=='H')
			{
				coins["HHH"]++;
			}
		}
		// printing
		printf("%d %d %d %d %d %d %d %d %d\n",count,coins["TTT"],coins["TTH"],coins["THT"],coins["THH"],coins["HTT"],coins["HTH"],coins["HHT"],coins["HHH"]);
	}
	return 0;
}
