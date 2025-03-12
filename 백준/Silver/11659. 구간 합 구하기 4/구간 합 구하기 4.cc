#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N);
    vector<int> prefixSum(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        prefixSum[i + 1] = prefixSum[i] + numbers[i];
    }

    for (int k = 0; k < M; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << '\n';
    }

    return 0;
}
