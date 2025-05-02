#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, X, N;
    cin >> T >> X;
    cin >> N;

    bool allAvailable = true;

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        bool canAttend = false;
        for (int j = 0; j < K; j++) {
            int t;
            cin >> t;
            if (t == X) canAttend = true;
        }
        if (!canAttend) allAvailable = false;
    }

    cout << (allAvailable ? "YES" : "NO") << '\n';
    return 0;
}
