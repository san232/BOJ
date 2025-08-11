#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> choices(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> choices[i];
    }

    std::vector<int> visited(n + 1, 0);
    int team_members = 0;

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            std::vector<int> path;
            int current = i;

            while (visited[current] == 0) {
                visited[current] = 1;
                path.push_back(current);
                current = choices[current];
            }

            if (visited[current] == 1) {
                auto cycle_start_it = std::find(path.begin(), path.end(), current);
                team_members += std::distance(cycle_start_it, path.end());
            }

            for (int node : path) {
                visited[node] = 2;
            }
        }
    }

    std::cout << n - team_members << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}