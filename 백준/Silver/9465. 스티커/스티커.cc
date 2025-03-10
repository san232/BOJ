#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int bottomUp(int n, vector<vector<int>>& buf)
{
    vector<vector<int>> dp(2, vector<int>(n, 0));
    
    dp[0][0] = buf[0][0];
    dp[1][0] = buf[1][0];
    if (n > 1)
    {
        dp[0][1] = buf[0][1] + dp[1][0];
        dp[1][1] = buf[1][1] + dp[0][0];
    }
    
    for (int i = 2; i < n; i++)
    {
        dp[0][i] = buf[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = buf[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }
    
    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> buf(2, vector<int>(n));
        
        for (int i = 0; i < n; i++) cin >> buf[0][i];
        for (int i = 0; i < n; i++) cin >> buf[1][i];
        
        cout << bottomUp(n, buf) << endl;
    }
    return 0;
}
