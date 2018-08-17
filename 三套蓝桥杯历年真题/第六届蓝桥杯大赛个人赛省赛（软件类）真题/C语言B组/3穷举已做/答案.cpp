#include <iostream>
using namespace std;

int check(int num1,int num2,int num3,int num4,int num5,int num6,int num7,int num8)
{
	int num[9];
	num[1]=num1;
	num[2]=num2;
	num[3]=num3;
	num[4]=num4;
	num[5]=num5;
	num[6]=num6;
	num[7]=num7;
	num[8]=num8;
	for (int i=1;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (i==j)continue;
			if (num[i]==num[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;

	for (a=8;a<10;a++)
	{
		for (e=1;e<2;e++)
		{
			for (b=0;b<10;b++)
			{
				for (c=0;c<10;c++)
				{
					for (d=0;d<10;d++)
					{
						for (f=0;f<10;f++)
						{
							for (g=0;g<10;g++)
							{
								for (h=0;h<10;h++)
								{
									if (e*10000+f*1000+c*100+b*10+h==a*1000+b*100+c*10+d+e*1000+f*100+g*10+b&&check(a,b,c,d,e,f,g,h))
									{
										printf("%d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,b);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}