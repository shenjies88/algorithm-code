#include <stdio.h>
#define N 15
int num[N]={0};


int j,s;

int check(int weishu)
{
	
	if (num[weishu+num[weishu]+1]==0&&weishu+num[weishu]+1<N)
	{
		num[weishu+num[weishu]+1]=num[weishu];
		return 1;
	}
	else
		return 0;
}

int saomiao(int shu)
{
	for (j=1;j<N;j++)
	{
		if (shu==num[j])
		{
			return 1;
		}
	}
	return 0;
}

void baocun(int sznum[])
{

	for(j=1;j<N;j++)
				{
		sznum[j]=num[j];
				}
}

void huanyuan(int sznum[])
{
	for(j=1;j<N;j++)
	{
		num[j]=sznum[j];
			}
}



void zuhe(int conut)
{
	int sznum[N]={0};
	if (conut==N)
	{
		s++;
		for (j=1;j<N;j++)
		{
			printf("%d ",num[j]);
		}
		printf("\n\n");
		getchar();
	
	}
	else if (num[conut]==0)//检查当前位是否有数
	{

		int i;
		//for的扫描量和数组要定义为局部变量才能起到回溯的效果
		baocun(sznum);//保存当前情况
		for (i=1;i<8;i++)//对当前位置进行1到7的扫描
		{
			if (saomiao(i))//检查是否有重复的数
			{
				continue;
			}
			
			num[conut]=i;

			if (check(conut))//检查是否符合1间隔1 并且间隔后的位置在数组内
			{	
				zuhe(conut+1);
				huanyuan(sznum);//上次递归结束说明条件不符合，进行还原
			}
		}
		

	}
	else
	{
		zuhe(conut+1);
		huanyuan(sznum);
		
		
	}
}

void main()
{
	
	
	zuhe(1);
	printf("有%d种\n\n",s);
}