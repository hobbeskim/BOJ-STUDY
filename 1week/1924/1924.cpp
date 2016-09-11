#include<stdio.h>

int main()
{
	int month;
	int day;
	int pastDays = 0;
	int monthData[12][2] = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };//recording Data of each month's day
	char * week[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	scanf("%d %d", &month, &day);

	for (int i = 0; i < month-1; i++)
	{
		pastDays = pastDays + monthData[i][1];//adding sigma(month-1) as pastDays
	}

	pastDays = pastDays + day; //adding day
	printf("%s", week[pastDays % 7]);//if pastDay % 7 == 0, Sunday 

	return 0;
}