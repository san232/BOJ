#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> A(N), dp(N, 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int maxLength = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    
    cout << maxLength << endl;
    return 0;
}
