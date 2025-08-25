#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
vector<string> board;
bool visited_alpha[26];
int max_count = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void solve(int x, int y, int count) {
    if (count > max_count) {
        max_count = count;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if (!visited_alpha[board[nx][ny] - 'A']) {
                visited_alpha[board[nx][ny] - 'A'] = true;
                solve(nx, ny, count + 1);
                visited_alpha[board[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    board.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    visited_alpha[board[0][0] - 'A'] = true;
    solve(0, 0, 1);

    cout << max_count << endl;

    return 0;
}