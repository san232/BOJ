#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

bool unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    parent.resize(V + 1);
    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
    }

    long long mstWeight = 0;
    for (const auto& edge : edges) {
        if (unionSets(edge.u, edge.v)) {
            mstWeight += edge.cost;
        }
    }

    cout << mstWeight << '\n';
    return 0;
}
