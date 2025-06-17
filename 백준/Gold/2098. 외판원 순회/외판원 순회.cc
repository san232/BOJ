#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> W(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> W[i][j];

    const int FULL = 1 << N;
    const int INF = 1e9;
    vector<vector<int>> dp(FULL, vector<int>(N, INF));

    dp[1][0] = 0;

    for (int mask = 1; mask < FULL; ++mask) {
        if (!(mask & 1)) continue;
        for (int u = 0; u < N; ++u) {
            if (!(mask & (1 << u))) continue;
            int cost_u = dp[mask][u];
            if (cost_u == INF) continue;
            for (int v = 0; v < N; ++v) {
                if (mask & (1 << v)) continue;
                if (W[u][v] == 0) continue;
                int nextMask = mask | (1 << v);
                dp[nextMask][v] = min(dp[nextMask][v], cost_u + W[u][v]);
            }
        }
    }

    int answer = INF;
    int endMask = FULL - 1;
    for (int u = 1; u < N; ++u) {
        if (W[u][0] == 0) continue;
        answer = min(answer, dp[endMask][u] + W[u][0]);
    }

    cout << answer << "\n";
    return 0;
}
