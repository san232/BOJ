#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int year = 2024;
	int month = 1;

	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		month += 7;

		if (month > 12)
		{
			month -= 12;
			year += 1;
		}
	}


	cout << year << " " << month;
}