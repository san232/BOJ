#include <iostream>
using namespace std;

int main()
{
    int X, N, total = 0;
    cin >> X >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        total += a * b;
    }

    if (total == X)
    {
        cout << "Yes" << endl;
    } else
    {
        cout << "No" << endl;
    }
}
