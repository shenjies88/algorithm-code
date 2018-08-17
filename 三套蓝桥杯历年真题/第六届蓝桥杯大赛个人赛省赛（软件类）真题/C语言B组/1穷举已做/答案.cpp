#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
	int w,q,b,s,g;
	int count=0;
	for (w=1;w<10;w++)
	{
		for (q=0;q<10;q++)
		{
			for (b=0;b<10;b++)
			{
				for (s=0;s<10;s++)
				{
					for (g=0;g<10;g++)
					{
						if (w==4||q==4||b==4||s==4||g==4)
						{
							continue;
						}
						else
						{
							count++;
						}
					}
				}
			}
		}
	}
	printf("%d",count);
}





