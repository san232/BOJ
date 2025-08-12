#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> dims(N + 1);
    vector<pair<int, int>> rc(N);
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        rc[i] = {r, c};
    }

    dims[0] = rc[0].first;
    for (int i = 0; i < N; i++) dims[i + 1] = rc[i].second;

    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            long long best = LLONG_MAX;
            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < best) best = cost;
            }
            dp[i][j] = best;
        }
    }

    cout << dp[0][N - 1] << '\n';
    return 0;
}
