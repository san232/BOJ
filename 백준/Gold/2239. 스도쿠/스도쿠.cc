#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;
int board[SIZE][SIZE];

bool row[SIZE][10];
bool col[SIZE][10];
bool square[SIZE][10];

inline int get_square_index(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

bool fill(int idx) {
    if (idx == SIZE * SIZE) {
        return true;
    }

    int i = idx / SIZE;
    int j = idx % SIZE;

    if (board[i][j] != 0) {
        return fill(idx + 1);
    }

    for (int num = 1; num <= 9; ++num) {
        int sq = get_square_index(i, j);
        if (!row[i][num] && !col[j][num] && !square[sq][num]) {
            board[i][j] = num;
            row[i][num] = true;
            col[j][num] = true;
            square[sq][num] = true;

            if (fill(idx + 1)) {
                return true;
            }

            board[i][j] = 0;
            row[i][num] = false;
            col[j][num] = false;
            square[sq][num] = false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < SIZE; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < SIZE; ++j) {
            int val = line[j] - '0';
            board[i][j] = val;
            if (val != 0) {
                row[i][val] = true;
                col[j][val] = true;
                square[get_square_index(i, j)][val] = true;
            }
        }
    }

    fill(0);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}
