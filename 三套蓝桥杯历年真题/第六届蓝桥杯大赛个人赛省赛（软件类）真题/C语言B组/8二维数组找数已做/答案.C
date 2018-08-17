#include <stdio.h>
#include <stdlib.h>



void SortGraph(int **num,int m,int n,int w)
{
	int i,j,k,l,s,flag=1;
	for (i=0;i<w&&flag;i++)
	{
		for (j=0;j<w;j++)
		{
			if (m==num[i][j])
			{
				flag=0;
				break;
			}
		}
		if (flag==0)
		{
			break;
		}
	}
	flag=1;
	for (k=0;k<w&&flag;k++)
	{
		for (l=0;l<w;l++)
		{
			if (n==num[k][l])
			{
				flag=0;
				break;
			}
		}
		if (flag==0)
		{
			break;
		}
	}
	s=abs(i-k)+abs(j-l);
	printf("%d",s);
}

void main()
{
	int **num;
	int w,m,n,i,j,sum=1;
	scanf("%d%d%d",&w,&m,&n);
	if (!(num=(int**)malloc(w*sizeof(int*))))
	{
		exit(0);
	}
	for (i=0;i<w;i++)
	{
		if (!(num[i]=(int*)malloc((w*sizeof(int)))))
		{
			exit(0);
		}
	}
	for (i=0;i<w;i++)
	{
		if (i%2!=0)
		{
			for (j=w-1;j>=0;j--)
			{
				num[i][j]=sum;
				sum++;
			}
		}
		else
		{
			for(j=0;j<w;j++)
			{
				num[i][j]=sum;
				sum++;
			}
		}
		
	}

	for (i=0;i<w;i++)
	{
		for (j=0;j<w;j++)
		{
			printf("%d\t",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	SortGraph(num,m,n,w);

}