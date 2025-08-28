#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> v;
long long gr[16][16][3];

long long solve(int r, int c, int orientation) {
    if (r == N - 1 && c == N - 1) {
        return 1;
    }

    if (gr[r][c][orientation] != -1) {
        return gr[r][c][orientation];
    }

    long long count = 0;
    if (orientation == 0 || orientation == 2) {
        if (c + 1 < N && v[r][c + 1] == 0) {
            count += solve(r, c + 1, 0);
        }
    }

    if (orientation == 1 || orientation == 2) {
        if (r + 1 < N && v[r + 1][c] == 0) {
            count += solve(r + 1, c, 1);
        }
    }

    if (r + 1 < N && c + 1 < N && v[r][c + 1] == 0 && v[r + 1][c] == 0 && v[r + 1][c + 1] == 0) {
        count += solve(r + 1, c + 1, 2);
    }

    return gr[r][c][orientation] = count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 3; ++k) {
                gr[i][j][k] = -1;
            }
        }
    }
    
    if (v[N - 1][N - 1] == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long result = solve(0, 1, 0);

    cout << result << "\n";

    return 0;
}
