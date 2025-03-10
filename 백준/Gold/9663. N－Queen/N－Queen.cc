#include <iostream>
#include <vector>
using namespace std;

int N, result = 0;
vector<int> queenPos;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queenPos[i] == col || abs(queenPos[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        result++;
        return;
    }
    
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            queenPos[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    cin >> N;
    queenPos.resize(N);
    solve(0);
    cout << result << endl;
    return 0;
}
