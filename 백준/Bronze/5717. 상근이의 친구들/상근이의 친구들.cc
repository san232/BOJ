#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>v;

	while (true)
	{
		int a, b, c = 0;



		cin >> a >> b;

		c = a + b;

		if (c == 0)
			break;

		v.push_back(c);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}