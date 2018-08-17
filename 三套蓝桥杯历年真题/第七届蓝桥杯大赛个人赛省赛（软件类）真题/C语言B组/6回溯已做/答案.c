#include <stdio.h>
#define MAX 32767
int num[5][6];
int count=0;
int i,j;

int Check(int k,int row,int col)
{
	for (i=row-1;i<=row+1;i++)
	{
		for (j=col-1;j<=col+1;j++)
		{
			if (i==row&&j==col)
			{
				continue;
			}
			else
			{
				if (num[i][j]==k-1||num[i][j]==k+1)
				{
					return 1;
				}
			}
		}
	}
	return 0;

}

void Save(int sznum[][6],int num[][6])
{
	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			sznum[i][j]=num[i][j];
		}
	}
	
}

void Recovery(int sznum[][6],int num[][6])
{
	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			num[i][j]=sznum[i][j];
		}
	}
	
}

int chongfu(int k)
{
	for (i=1;i<=3;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (k==num[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}

void BackTrack(int row,int col)
{
	if (row==4)
	{
		count++;
		for (i=1;i<=3;i++)
		{
			for (j=1;j<=4;j++)
			{
				if (num[i][j]==MAX)
				{
					printf(" \t");
				}
				else
				{
					printf("%d\t",num[i][j]);
				}
			}
			printf("\n");
		}
		getchar();
	}
	else
	{	
		int k;
		int sznum[5][6];
		Save(sznum,num);
		for (k=0;k<10;k++)
		{
			if (Check(k,row,col)||chongfu(k))//上下左右对角线
			{
				continue;
			
			}
			else
			{
				num[row][col]=k;

				if (row==1&&col==4)
				{
					BackTrack(2,1);
					Recovery(sznum,num);
					continue;
				}
				else if(row==2&&col==4)
				{
					BackTrack(3,1);
					Recovery(sznum,num);
					continue;
				}
				else if (row==3&&col==3)
				{
					BackTrack(4,1);
					Recovery(sznum,num);
					continue;
				}
				else
				{
					BackTrack(row,col+1);
					Recovery(sznum,num);
					continue;
				}
			}
		}
		
	}
	
}


void  main()
{	
	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			num[i][j]=MAX;
		}
	}
	BackTrack(1,2);
	
}