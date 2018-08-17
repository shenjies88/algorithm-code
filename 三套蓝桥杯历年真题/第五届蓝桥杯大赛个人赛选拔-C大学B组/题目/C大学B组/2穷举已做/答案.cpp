#include <stdio.h>
#include <math.h>



void main()
{
	double sum=0.0;
	double div1=1.0;
	int jishu=0;
	for (;sum<15.0;div1++)
	{
		sum+=1/div1;
		jishu++;
		if (sum>15.00000001)
		{
			printf("%d",jishu);
			break;
		}
	}

	
}