#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }
    long long result = 0;
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long s = a + b;
        result += s;
        pq.push(s);
    }
    cout << result << "\n";
    return 0;
}
