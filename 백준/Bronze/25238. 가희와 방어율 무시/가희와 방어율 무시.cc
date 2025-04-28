#include<iostream>
#include<vector>

using namespace std;

int defignore(float def, float defIgnorePer);

int main()
{
	float def, defIgnorePer = 0;

	cin >> def >> defIgnorePer;

	

	cout << defignore(def, defIgnorePer);


}

int defignore(float def, float defIgnorePer)
{
	
	float ignore = (def * 0.01f) * defIgnorePer;

	if (def - ignore >= 100)
		return 0;

	return 1;
}
