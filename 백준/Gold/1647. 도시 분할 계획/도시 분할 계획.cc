#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

vector<int> parent;

int findSet(int x) {
    return parent[x] == x ? x : parent[x] = findSet(parent[x]);
}

bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    edges.reserve(M);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }

    sort(edges.begin(), edges.end());

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    long long answer = 0;
    int used = 0;
    int need = N - 2;

    for (auto& e : edges) {
        if (used == need) break;
        if (unionSet(e.u, e.v)) {
            answer += e.cost;
            ++used;
        }
    }

    cout << answer;
    return 0;
}
