#include <stdio.h>
#define MAX 32767
int num[5][6];
int i,j,count=0;
int repot[13]={0};
int pre;

void Save(int *repot,int *szrepot)
{
	for (i=0;i<13;i++)
	{
		szrepot[i]=repot[i];
	}
}

void Recover(int *repot,int *szrepot)
{
	for (i=0;i<13;i++)
	{
		repot[i]=szrepot[i];
	}
}


int check(int row,int col)
{
	for (i=0;i<13;i++)
	{
		if (num[row][col]==repot[i])
		{
			return 0;
		}
	}
	return 1;
}


void BackTrac(int row,int col,int k)
{
	if (k==1)
	{
		pre=MAX;
	}
	if (k==12)
	{
		count++;
		repot[k]=num[row][col];
		for (i=1;i<=12;i++)
		{
			printf("%d ",repot[i]);
		}
		printf("\n");
	}
	else
	{
		int o;
		int szrepot[13];
		Save(repot,szrepot);
		for (o=0;o<4;o++)
		{
			switch (o)
			{
			case 0:
				if (num[row-1][col]!=MAX&&num[row-1][col]!=pre&&check(row-1,col))
				{
					repot[k]=num[row][col];
					if(k!=4)pre=num[row][col];			
					BackTrac(row-1,col,k+1);
					if (k!=4)pre=repot[k-1];
					Recover(repot,szrepot);
				
				}
				break;
			case 1:
				if (num[row][col-1]!=MAX&&num[row][col-1]!=pre&&check(row,col-1))
				{
					repot[k]=num[row][col];		
					if(k!=4)pre=num[row][col];		
					BackTrac(row,col-1,k+1);
					if(k!=4)pre=repot[k-1];
					Recover(repot,szrepot);
				}
				break;
			case 2:
				if (num[row+1][col]!=MAX&&num[row+1][col]!=pre&&check(row+1,col))
				{
					repot[k]=num[row][col];
					if(k!=4)pre=num[row][col];		
					BackTrac(row+1,col,k+1);
					if(k!=4)pre=repot[k-1];
					Recover(repot,szrepot);
				}
				break;
			case 3:
				if (num[row][col+1]!=MAX&&num[row][col+1]!=pre&&check(row,col+1))
				{
					repot[k]=num[row][col];
					if(k!=4)pre=num[row][col];		
					BackTrac(row,col+1,k+1);
					if(k!=4)pre=repot[k-1];
					Recover(repot,szrepot);
				}
				break;
			}
		}
	
	}

}




void main()
{
	int k=1;
	
	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			if (i==0||i==4||j==0||j==5)
			{
				num[i][j]=MAX;
			}
		}
	}

	for (i=1;i<=3;i++)
	{
		for(j=1;j<=4;j++) 
		{
			num[i][j]=k++;
		}
	}
	repot[0]=MAX;
	BackTrac(1,1,1);
	
	printf("%d",count);
	getchar();
}