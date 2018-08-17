#include <stdio.h>
int map[]={1,2,3,4,6,7,8,9,11,12,13,14};
int aa[5],vis[5];
int D[4]={-1,1,5,-5};
int sum=0,i,j,flage;





void dfs(int n)
{
	int t,i,j;
	for (i=0;i<5;i++)
	{
		t=aa[n]+D[i];
		if (t<1||t>14||t==5||t==10)continue;
		for (j=0;j<5;j++)
		{
			if (!vis[j]&&aa[j]==t)
			{
				vis[j]=1;
				dfs(j);
				
			}
		}
	}

}






void main()
{
	int a,b,c,d,e;
	for (a=0;a<12;a++)
	{
		for (b=a+1;b<12;b++)
		{
			for (c=b+1;c<12;c++)
			{
				for (d=c+1;d<12;d++)
				{
					for (e=d+1;e<12;e++)
					{
						aa[0]=map[a];
						aa[1]=map[b];
						aa[2]=map[c];
						aa[3]=map[d];
						aa[4]=map[e];
						for (i=0;i<5;i++)
						{
							vis[i]=0;
						}
						vis[0]=1;
						flage=1;
						dfs(0);
						for(i=0;i<5;i++)
						{
							if (!vis[i])
							{
								flage=0;
								break;
							}
						}
						if (flage==1)
						{
							sum++;
						}
						
					}
				}
			}
		}
	}
	printf("%d",sum);
}
