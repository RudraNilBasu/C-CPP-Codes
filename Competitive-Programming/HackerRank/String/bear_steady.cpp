#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

int main()
{
	char genes[4]={'A','G','T','C'};
	int n,i,k;
	char ch;
	scanf("%d",&n);
	int eachLen=n/4;
	char str[n+1];
	scanf("%s",str);

	map<char,int> tst;
	for(i=0;i<n;i++) {
		ch=str[i];
		tst[ch]++;
	}
	int flag=0;
	if(tst['A']==tst['C']==tst['G']==tst['T']==eachLen) {
		printf("0\n");
		return 0;
	}
	map<char,int> letter_count; // count the letters
			// which are present extra
	for(i=0;i<4;i++) {
		if(tst[genes[i]]>eachLen) {
			letter_count[genes[i]]=tst[genes[i]]-eachLen;
		}
	}

	int start=0,end=0,min_length=n;
	map<char,int> substring; // stores freq of characters
	//in the substring [start....end)
	while(1) {
		//printf("hue A=%d G=%d T=%d C=%d\n",substring['A'],substring['G'],substring['T'],substring['C']);
		if(end>=n) {
			printf("%d\n",min_length);
			return 0;
		}
		flag=1;
		for(i=0;i<4;i++) {
			if(substring[genes[i]]<letter_count[genes[i]]) {
				flag=0;
			}
		}
		//printf("Flag=%d\n",flag);
		if(flag) {
			// all letters are present in the substring
			// check if it is the min or not
			if((end-start)<min_length) {
				min_length=end-start;
			}
			start++;
			substring[str[start-1]]--;
		} else {
			end++;
			substring[str[end-1]]++;
		}
	}
	/*
	for(k=1;k<=n;k++) {
		map<char,int> rem;
		for(i=k;i<n;i++) {
			ch=str[i];
			rem[ch]++;
		}
		map<char,int> reqd;
		reqd['A']=eachLen-rem['A'];
		reqd['C']=eachLen-rem['C'];
		reqd['G']=eachLen-rem['G'];
		reqd['T']=eachLen-rem['T'];
		if(reqd['A']>=0 && reqd['T']>=0 &&
				reqd['G']>=0 && reqd['C']>=0 ) {
			if( reqd['A']+reqd['G']+reqd['T']+reqd['C']==k ) {
				printf("%d\n",k);
				return 0;
			}
		}
		for(i=1;i+k<n;i++) {
			rem[str[i-1]]++;
			rem[str[i+k-1]]--;

			reqd['A']=eachLen-rem['A'];
			reqd['C']=eachLen-rem['C'];
			reqd['G']=eachLen-rem['G'];
			reqd['T']=eachLen-rem['T'];
			if(reqd['A']>=0 && reqd['T']>=0 &&
					reqd['G']>=0 && reqd['C']>=0 ) {
				if( reqd['A']+reqd['G']+reqd['T']+reqd['C']==k ) {
					printf("%d\n",k);
					return 0;
				}
			}
		}
	}
	*/
	return 0;
}
