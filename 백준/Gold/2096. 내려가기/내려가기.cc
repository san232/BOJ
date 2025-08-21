#include <iostream>
#include <vector>
#include <algorithm>

const int NUM_COLS = 3;

void solve() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "0 0\n";
        return;
    }

    std::vector<int> max_dp(NUM_COLS);
    std::vector<int> min_dp(NUM_COLS);

    for (int i = 0; i < NUM_COLS; ++i) {
        std::cin >> max_dp[i];
        min_dp[i] = max_dp[i];
    }

    for (int i = 1; i < n; ++i) {
        std::vector<int> current_values(NUM_COLS);
        for (int j = 0; j < NUM_COLS; ++j) {
            std::cin >> current_values[j];
        }

        std::vector<int> prev_max_dp = max_dp;
        std::vector<int> prev_min_dp = min_dp;

        max_dp[0] = std::max(prev_max_dp[0], prev_max_dp[1]) + current_values[0];
        max_dp[1] = std::max({prev_max_dp[0], prev_max_dp[1], prev_max_dp[2]}) + current_values[1];
        max_dp[2] = std::max(prev_max_dp[1], prev_max_dp[2]) + current_values[2];

        min_dp[0] = std::min(prev_min_dp[0], prev_min_dp[1]) + current_values[0];
        min_dp[1] = std::min({prev_min_dp[0], prev_min_dp[1], prev_min_dp[2]}) + current_values[1];
        min_dp[2] = std::min(prev_min_dp[1], prev_min_dp[2]) + current_values[2];
    }

    int max_score = *std::max_element(max_dp.begin(), max_dp.end());
    int min_score = *std::min_element(min_dp.begin(), min_dp.end());

    std::cout << max_score << " " << min_score << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
