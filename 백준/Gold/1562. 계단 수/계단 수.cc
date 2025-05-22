#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int FULL_MASK = (1 << 10) - 1;
    vector<array<int, 1<<10>> dp(10), next_dp(10);

    for (int d = 1; d <= 9; ++d) {
        dp[d][1 << d] = 1;
    }

    for (int step = 1; step < N; ++step) {
        for (int d = 0; d < 10; ++d)
            fill(next_dp[d].begin(), next_dp[d].end(), 0);

        for (int d = 0; d < 10; ++d) {
            for (int mask = 0; mask <= FULL_MASK; ++mask) {
                int cnt = dp[d][mask];
                if (!cnt) continue;

                if (d > 0) {
                    int nd = d - 1;
                    int nmask = mask | (1 << nd);
                    next_dp[nd][nmask] = (next_dp[nd][nmask] + cnt) % MOD;
                }
                if (d < 9) {
                    int nd = d + 1;
                    int nmask = mask | (1 << nd);
                    next_dp[nd][nmask] = (next_dp[nd][nmask] + cnt) % MOD;
                }
            }
        }

        dp.swap(next_dp);
    }

    long long answer = 0;
    for (int d = 0; d < 10; ++d) {
        answer = (answer + dp[d][FULL_MASK]) % MOD;
    }

    cout << answer << "\n";
    return 0;
}
