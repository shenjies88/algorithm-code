#include <stdio.h>
#include <math.h>



void main()
{
	double x=2.0;
	while (x<3.0)
	{
		x+=0.00000001;
		if (fabs(pow(x,x)-10)<0.00001)
		{
			printf("%.8lf",x);
			break;
		}
	}

	
}