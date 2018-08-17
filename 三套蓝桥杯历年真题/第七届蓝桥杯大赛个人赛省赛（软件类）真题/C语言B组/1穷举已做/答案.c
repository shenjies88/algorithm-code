#include <stdio.h>


void main()
{
	int i,add=0,j=1;
	long int sum=0;
	for (i=1;i<=100;i++)
	{
		sum+=i+add;
		add+=j;
		j++;
	}
	printf("%ld",sum);
}