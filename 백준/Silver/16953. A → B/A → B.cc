#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    long long steps = 0;
    long long cur = B;

    while (cur > A) {
        if (cur % 10 == 1) {
            cur /= 10;
            steps++;
        } else if (cur % 2 == 0) {
            cur /= 2;
            steps++;
        } else {
            break;
        }
    }

    if (cur == A) {
        cout << (steps + 1) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
