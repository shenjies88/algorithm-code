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
	else if (num[conut]==0)//��鵱ǰλ�Ƿ�����
	{

		int i;
		//for��ɨ����������Ҫ����Ϊ�ֲ����������𵽻��ݵ�Ч��
		baocun(sznum);//���浱ǰ���
		for (i=1;i<8;i++)//�Ե�ǰλ�ý���1��7��ɨ��
		{
			if (saomiao(i))//����Ƿ����ظ�����
			{
				continue;
			}
			
			num[conut]=i;

			if (check(conut))//����Ƿ����1���1 ���Ҽ�����λ����������
			{	
				zuhe(conut+1);
				huanyuan(sznum);//�ϴεݹ����˵�����������ϣ����л�ԭ
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
	printf("��%d��\n\n",s);
}