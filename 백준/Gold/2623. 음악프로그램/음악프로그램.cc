#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> indeg(N + 1, 0);

    unordered_set<long long> seen;
    seen.reserve(200000);
    seen.max_load_factor(0.7f);

    for (int i = 0; i < M; ++i) {
        int k; 
        cin >> k;
        if (k == 0) continue;

        int prev; 
        cin >> prev;
        for (int j = 1; j < k; ++j) {
            int cur; 
            cin >> cur;
            long long key = 1LL * prev * (N + 1) + cur;
            if (seen.insert(key).second) {
                adj[prev].push_back(cur);
                indeg[cur]++;
            }
            prev = cur;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) if (indeg[i] == 0) q.push(i);

    vector<int> order; order.reserve(N);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != N) {
        cout << 0 << '\n';
    } else {
        for (int x : order) cout << x << '\n';
    }
    return 0;
}
