#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dow(int year, int month, int day)
{
	int d = day;
	int Y;
	double m = (double)((month-3)%12+1);
	
	if(m>10)  Y = year-1;
	else  Y = year;
	
	int y =Y%100;
	int c = (Y-y)/100;
	int w = ((d+(int)floor(2.6*m-0.2)+y+y/4+c/4-2*c))%7;

	return w;
}

long months_range(int day, int startyear, int endyear)
{
	unsigned long total = 0;
	int year, month;
	for(year = startyear;year<endyear;year++)
		for(month = 1; month <= 12; month++)
			if(dow(year, month, 1) == day) total++;
	return total;
}

int main()
{
	int iter = 0;
	long total;
	while(iter <100000)
	{
		total = months_range(0,1901,2000);
		iter++;
	}
	printf("Solution %ld\n", total);
	return 0;
}
