//
//

#include<stdio.h>
#include<string.h>
int main()
{
	long long int t,c=0,i,n,c1=0,c2=0;
	int isl1 = 0,isno=0;
	char l1[200001];
	char l2[200001];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s %s",l1,l2);
		isl1=0;
		isno=0;
		c=0;
		c1=0;
		c2=0;
		n=strlen(l1);
		if(l1[0]=='#' && l2[0]=='#')
		{
			isno=1;
			printf("No\n");
		}
		else if(l1[0]!=l2[0])
		{
			if(l1[0]=='.')
			{
				isl1=1;  // 1 meaning true
			}
			else if(l2[0]=='.')
			{
				isl1=0;  // 0 meaning false
			}
			for(i=1;i<n;i++)
			{
				if(isl1==1)
				{
					if(l1[i]=='.')
					{
						continue;
					}
					else if(l2[i]=='.' && l1[i]=='#')
					{
						c++;
						isl1=0;
					}
					else if(l1[i]=='#' && l2[i]=='#')
					{
						isno=1;
						printf("No\n");
						break;
					}
				}
				else if(isl1==0)
				{
					if(l2[i]=='.')
					{
						continue;
					}
					else if(l2[i]=='#' && l1[i]=='.')
					{
						isl1=1;
						c++;
					}
					else if(l1[i]=='#' && l2[i]=='#')
					{
						isno=1;
						printf("No\n");
						break;
					}
				}
			}
			//PRINTING if YES
			if(isno==0)
			{
				printf("Yes\n");
				printf("%lld\n",c);
			}
		}
		//	HERE 
		else if(l1[0]=='.' && l2[0]=='.')
		{
			//taking l1 as the starting point
			isl1=1;
			for(i=1;i<n;i++)
			{
				//test
				/*
				if(i==2)
				{
					printf("isl1=%d , l1[2]=%c , l2[2]=%c\n",isl1,l1[i],l2[i]);
				}
				*/
				//test
				if(isl1==1)
				{
					//if(i==2){printf("YOLO l1[i]=%c\n",l1[i]);}
					if(l1[i]=='.')
					{
						//printf("Staying at L1 at %lld value = %c\n",i,l1[i]);
						continue;
					}
					else if(l1[i]=='#' && l2[i]=='#')
					{
						isno=1;
						printf("No\n");
						break;
					}
					else if((l1[i]=='#') && (l2[i]=='.'))
					{
						//printf("GRAVITY at %lld\n",i);
						c1++;
						isl1=0;
					}
				}
				else if(isl1==0)
				{
					if(l2[i]=='.')
					{
						continue;
					}
					else if(l2[i]=='#' && l1[i]=='#')
					{
						isno=1;
						printf("No\n");
						break;
					}
					else if(l1[i]=='.' && l2[i]=='#')
					{
						isl1=1;
						c1++;
					}
				}
			}
			//taking l2 as the starting point
			if(isno==0)
			{
				isl1=0;
				for(i=1;i<n;i++)
				{
					if(isl1==0)
					{
						//We are currently in 2
						if(l2[i]=='.')
						{
							continue;
						}
						else if(l1[i]=='#' && l2[i]=='#')
						{
							isno=1;
							printf("No\n");
							break;
						}
						else if(l2[i]=='#' && l1[i]=='.')
						{
							isl1=1;
							c2++;
						}
					}
					else if(isl1==1)
					{
						//WE are currently in 1
						if(l1[i]=='.')
						{
							continue;
						}
						else if(l1[i]=='#' && l2[i]=='#')
						{
							isno=1;
							printf("No\n");
							break;
						}
						else if(l1[i]=='#' && l2[i]=='.')
						{
							isl1=0;
							c2++;
						}
					}
				}
			}
			//NOW COMPARE c1 and c2 and print lowest
			if(isno==0)
			{
				printf("Yes\n");
				if(c1<c2)
				{
					printf("%lld\n",c1);
				}
				else 
				{
					printf("%lld\n",c2);
				}
			}
		}
	}
	return 0;
}
