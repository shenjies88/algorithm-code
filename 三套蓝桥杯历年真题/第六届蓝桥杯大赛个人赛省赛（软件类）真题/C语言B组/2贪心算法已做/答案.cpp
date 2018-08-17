#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 13

int month[N]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day[5]={0};
int year[5]={0,2014,2015,2016,2017};
int i,j,flag=0;
int V=1000;
void main()
{
	for(i=1;i<5;i++)
	{
		if ((year[i]%4==0&&year[i]%100!=0)||year[i]%400==0)
		{
			day[i]=366;
			
		}
		else
		{
			day[i]=365;
		}
	}

	for (i=1;i<11;i++)
	{
		j+=month[i];
	}
	j=j+9;

	if (day[1]==366)
	{
		j=j+1;
	}

	day[1]=day[1]-j;
	i=1;
	do 
	{
		V=V-day[i];
		i++;
	} while (V>day[i]);
	
	if ((year[i]%4==0&&year[i]%100!=0)||year[i]%400==0)
	{
		
		month[2]=29;
	}
		

	for (i=1;V>month[i];i++)
	{
		V=V-month[i];
	}

	printf("%d  %d\n",i,V);

	printf("2017-08-05\n");
}




