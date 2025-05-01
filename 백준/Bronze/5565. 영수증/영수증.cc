#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main()
{
	int input = 0;

	cin >> input;

	for (int i = 0; i < 9; i++)
	{
		int n = 0;
		cin >> n;

		input -= n;
	}

	cout << input;

}
