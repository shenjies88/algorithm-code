#include <stdio.h>
int j;
int check(int i,int lowkey)
{
	int minmul;
	int maxmul;
	int befor;
	int sum=0;
	
	
	for (j=1;j<50;j++)
	{
		if (j==befor)
		{
			continue;
		}
		if (j==lowkey||j==i)
		{
		
			if (j==lowkey)
			{
				minmul=lowkey*(lowkey+1);
				befor=lowkey+1;
			}
			if (j==i)
			{
				maxmul=i*(i+1);
				befor=i+1;
			}
		}
		else
		{
			sum+=j;
		}
	}
		sum=sum+minmul+maxmul;
	
	if (sum==2015)
	{
		return 1;
	}
	else
		return 0;
}

void BackTrack(int lowkey)
{
	if (lowkey==47)
	{
		return;
	}
	else
	{
		int i;
		for (i=lowkey+2;i<50;i++)
		{
			if (check(i,lowkey))
			{
				printf("%d %d\n",lowkey,i);
			}
		}
		BackTrack(lowkey+1);
	}
}

int main()
{
	
	BackTrack(1);
	return 0;
}




