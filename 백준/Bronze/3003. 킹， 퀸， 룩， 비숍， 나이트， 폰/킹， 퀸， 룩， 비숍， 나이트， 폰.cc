#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main()
{
	int input[6], cnt[6] = {0};

	int answer[6] = { 1, 1, 2, 2, 2, 8 };



	for (int i = 0; i < 6; i++)
	{
		cin >> input[i];

		while (input[i] < answer[i])
		{
			input[i]++;
			cnt[i]++;
		}
		while (input[i] > answer[i])
		{
			input[i]--;
			cnt[i]--;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		cout << cnt[i] << " ";
	}


}
