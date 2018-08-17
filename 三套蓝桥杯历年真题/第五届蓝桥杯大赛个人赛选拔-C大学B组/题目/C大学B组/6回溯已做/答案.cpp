#include <stdio.h>
#define N 10

int num[N][N];
int i,j;
long count=0;

int  ChekReapt(int row,int col)
{
	for (i=row,j=1;j<N;j++)//�鿴��ǰ�����������û���ظ�
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
	if (row<=3)//�鿴��ǰ�������ĸ��Ź�����
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

void Save(int sznum[][N])//��������
{
	for (i=1;i<N;i++)
	{
		for (j=1;j<N;j++)
		{
			sznum[i][j]=num[i][j];
		}
	}
}

void Recovery(int sznum[][N])//��ԭ����
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
	
	if (row==N)//������ʮ�У�˵�������ˣ��������
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
	else if ((num[row][col]!=0)&&col+1==N)//�ھ���Ϊ�����Ļ�����
		{
			Backtrac(row+1,1);
		}
	else if(num[row][col]!=0)//��ǰ������������
		{
			Backtrac(row,col+1);
		}
	else
	{
		int k;//����ɨ����
		int sznum[N][N];//��������
		Save(sznum);
		for (k=1;k<N;k++)
		{
			num[row][col]=k;
			if (ChekReapt(row,col))//�Ȳ鿴��ǰ���������������û���ظ�
			{
				continue;
			}
			else if (ChekNineGride(row,col))//�ٲ鿴��ǰ����ľŹ�����û���ظ�
			{
				continue;
			}
			
			if (col+1==N)//�����˵ھ��оͻ���
			{
				Backtrac(row+1,1);
				Recovery(sznum);//�ϴεݹ����˵������ʧ�ܣ����л�ԭ
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