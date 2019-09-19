#include<iostream>
using namespace std;

int GetDaysOfMonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		days[2] += 1;
	}
	return days[month];
}

bool IsValidDay(int year, int month, int day)
{
	if (year > 0 && (month > 0 && month<13) && (day>0 && day < GetDaysOfMonth(year, month)))
	{
		return true;
	}
	return false;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int count = 0;
		if (IsValidDay(year, month, day))
		{
			for (int i = 1; i < month; i++)
			{
				count += GetDaysOfMonth(year, i);
			}
			count += day;
			cout << count << endl;
		}
		else
		{
			return -1;
			cout << "000" << endl;
		}
	}
	return 0;
}