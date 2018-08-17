#include <stdio.h>
#define N 10

int num[N][N];
int i,j;
long count=0;

int  ChekReapt(int row,int col)
{
	for (i=row,j=1;j<N;j++)//查看当前坐标的行列有没有重复
	{
		if (i==row&&j==col)
		{
			continue;
		}
		if (num[i][j]==num[row][col])
		{
			return 1;
		}
	}

	for (i=col,j=1;j<N;j++)
	{
		if (j==row&&i==col)
		{
			continue;
		}
		if (num[j][i]==num[row][col])
		{
			return 1;
		}
	}

	return 0;

}

int ChekNineGride(int row,int col)
{
	if (row<=3)//查看当前坐标在哪个九宫格内
	{
		i=1;
	}
	else if(row<=6&&row>=4)
	{
		i=4;
	}
	else if(row<=9&&row>=7)
	{
		i=7;
	}
	if (col<=3)
	{
		j=1;
	}
	else if(col<=6&&col>=4)
	{
		j=4;
	}
	else if(col<=9&&col>=7)
	{
		j=7;
	}
	int l=i+2;
	int m=j+2;
	
	int szj=j;

	for (;i<=l;i++)
	{
		for (j=szj;j<=m;j++)
		{
			if (i==row&&j==col)
			{
				continue;
			}
			if (num[i][j]==num[row][col])
			{
				return 1;
			}
		}
	}

	return 0;



}

void Save(int sznum[][N])//保存数组
{
	for (i=1;i<N;i++)
	{
		for (j=1;j<N;j++)
		{
			sznum[i][j]=num[i][j];
		}
	}
}

void Recovery(int sznum[][N])//还原数组
{
	for (i=1;i<N;i++)
	{
		for (j=1;j<N;j++)
		{
			num[i][j]=sznum[i][j];
		}
	}
}

void Backtrac(int row,int col)
{
	
	if (row==N)//换到第十行，说明填完了，输出数组
	{
		count++;
		for (i=1;i<N;i++)
		{
			for (j=1;j<N;j++)
			{
				printf("%d ",num[i][j]);
				if (j==N-1)
				{
					printf("\n");
				}
			}
			
		}
		printf("%\n\n");
		getchar();
		
	}
	else if ((num[row][col]!=0)&&col+1==N)//第九列为有数的话换行
		{
			Backtrac(row+1,1);
		}
	else if(num[row][col]!=0)//当前列有数，换列
		{
			Backtrac(row,col+1);
		}
	else
	{
		int k;//数字扫描量
		int sznum[N][N];//保存数组
		Save(sznum);
		for (k=1;k<N;k++)
		{
			num[row][col]=k;
			if (ChekReapt(row,col))//先查看当前所在坐标的行列有没有重复
			{
				continue;
			}
			else if (ChekNineGride(row,col))//再查看当前坐标的九宫格有没有重复
			{
				continue;
			}
			
			if (col+1==N)//填完了第九列就换行
			{
				Backtrac(row+1,1);
				Recovery(sznum);//上次递归结束说明填数失败，进行还原
			}
			else
			{
				Backtrac(row,col+1);
				Recovery(sznum);
			}
		}
	}

}


void main()
{

	for (i=1;i<N;i++)
	{
		
		for(j=1;j<N;j++)
		{
			scanf("%d",&num[i][j]);
		}
		getchar();
	
	}
	
	printf("\n\n");
	Backtrac(1,1);

	printf("%ld\n",count);
}