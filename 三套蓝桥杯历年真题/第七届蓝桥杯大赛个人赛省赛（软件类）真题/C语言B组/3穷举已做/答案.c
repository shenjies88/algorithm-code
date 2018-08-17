#include <stdio.h>

int add(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	if (a*c*(g*100+h*10+i)+b*(g*100+h*10+i)+(d*100+e*10+f)*c==10*c*(g*100+h*10+i))
	{
		return 1;
	}
	else
		return 0;
}

int check(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	int num[10],k,j;
	
	num[1]=a;
	num[2]=b;
	num[3]=c;
	num[4]=d;
	num[5]=e;
	num[6]=f;
	num[7]=g;
	num[8]=h;
	num[9]=i;
	
	for (k=1;k<10;k++)
	{
		for (j=1;j<10;j++)
		{
			if (k==j)
			{
				continue;
			}
			else
			{
				if (num[k]==num[j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void main()
{
	int count=0;
	int a,b,c,d,e,f,g,h,i;
	for (a=1;a<10;a++)
	{
		for (b=1;b<10;b++)
		{
			for (c=1;c<10;c++)
			{
				for (d=1;d<10;d++)
				{
					for (e=1;e<10;e++)
					{
						for (f=1;f<10;f++)
						{
							for (g=1;g<10;g++)
							{
								for (h=1;h<10;h++)
								{
									for (i=1;i<10;i++)
									{
										if(add(a,b,c,d,e,f,g,h,i)&&check(a,b,c,d,e,f,g,h,i))
										{
											count++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d",count);
}