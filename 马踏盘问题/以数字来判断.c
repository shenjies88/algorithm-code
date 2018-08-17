#include <stdio.h>
int map[]={0,1,2,3,4,6,7,8,9,11,12,13,14};
int s[13]={0};
int repot[13]={0};
int b[4]={-5,-1,5,1};
int sum=0;



void  dfs(int n,int count)
{
	if (count==12)
	{
		int d;
		for (d=1;d<=12;d++)
		{
			if(d<12)printf("%d->",repot[d]);
			else printf("%d",repot[d]);
		}
		printf("\n");
		sum++;
	}
	else
	{
		int i,j,t;
		for (i=0;i<4;i++)
		{
			t=map[n]+b[i];
			if (t<1||t>14||t==5||t==10)continue;
			for (j=1;j<=12;j++)
			{
				if (!s[j]&&map[j]==t)
				{
					s[j]=1;
					repot[count+1]=map[j];
					dfs(j,count+1);
					s[j]=0;
					repot[count+1]=0;
				}
			}
			
		}
	}
}



void main()
{
	s[1]=1;
	repot[1]=1;
	dfs(1,1);
	printf("%d\n",sum);
}