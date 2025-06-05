#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    cin >> N >> S;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int result = INT_MAX;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < N; ++right) {
        sum += a[right];
        while (sum >= S) {
            result = min(result, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    if (result == INT_MAX) {
        cout << 0 << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
