#include<stdio.h>
inline void fast_int(int *a)
{
	char c=0;
	while(c<33)
	{
		c=getchar_unlocked();
	}
	*a=0;
	while(c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}
inline void fast_string(char *s)
{
	register char c=0;
	register int i=0;
	while(c<33)
	{
		c=getchar_unlocked();
	}
	while(c>65)
	{
		s[i]=c;
		c=getchar_unlocked();
		i=i+1;
	}
	s[i]='\0';
}
int main()
{
	int n;
	char s[50];
	fast_int(&n);
	fast_string(s);
	printf("%s\n",s);
	return 0;
}
