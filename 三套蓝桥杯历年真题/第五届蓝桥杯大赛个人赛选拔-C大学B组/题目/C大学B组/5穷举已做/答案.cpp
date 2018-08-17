#include <stdio.h>
#include <math.h>



void main()
{
	int x;
	scanf("%d",&x);
	int sum=0,i,j,jishu=0;
	for(i=1;(i*i)<(x*x);i++)
	{
		for (j=1;(j*j)<(x*x);j++)
		{
			if (x*x==j*j+i*i)
			{
				jishu++;
			}
		}
	}
	printf("%d",jishu/2);


}
