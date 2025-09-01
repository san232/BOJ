#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> lab;
vector<pair<int, int>> empty_spaces;
vector<pair<int, int>> virus_locations;
int max_safe_area = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void calculate_safe_area() {
    vector<vector<int>> temp_lab = lab;

    queue<pair<int, int>> q;
    for (const auto& loc : virus_locations) {
        q.push(loc);
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && temp_lab[nr][nc] == 0) {
                temp_lab[nr][nc] = 2;
                q.push({nr, nc});
            }
        }
    }

    int current_safe_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (temp_lab[i][j] == 0) {
                current_safe_area++;
            }
        }
    }

    max_safe_area = max(max_safe_area, current_safe_area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    lab.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) {
                empty_spaces.push_back({i, j});
            } else if (lab[i][j] == 2) {
                virus_locations.push_back({i, j});
            }
        }
    }

    for (size_t i = 0; i < empty_spaces.size(); ++i) {
        for (size_t j = i + 1; j < empty_spaces.size(); ++j) {
            for (size_t k = j + 1; k < empty_spaces.size(); ++k) {
                lab[empty_spaces[i].first][empty_spaces[i].second] = 1;
                lab[empty_spaces[j].first][empty_spaces[j].second] = 1;
                lab[empty_spaces[k].first][empty_spaces[k].second] = 1;

                calculate_safe_area();

                lab[empty_spaces[i].first][empty_spaces[i].second] = 0;
                lab[empty_spaces[j].first][empty_spaces[j].second] = 0;
                lab[empty_spaces[k].first][empty_spaces[k].second] = 0;
            }
        }
    }

    cout << max_safe_area << endl;

    return 0;
}