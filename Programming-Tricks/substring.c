#include<stdio.h>
int main()
{
	char a[10]; // original string
	char* b; // string where substring will be stored
	scanf("%s",a);
	b=(a+1); // extracting from 2nd character till last
	printf("%s\n",b);
	return 0;
}
