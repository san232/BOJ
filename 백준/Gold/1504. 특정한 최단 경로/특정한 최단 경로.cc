#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

struct Edge {
    int to;
    int weight;
};

const long long INF = 4000000000000000000LL;

int N, E;
vector<Edge> adj[801];
int v1, v2;

vector<long long> dijkstra(int start) {
    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push(pair<long long, int>(0, start));

    while (!pq.empty()) {
        long long cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) {
            continue;
        }

        for (size_t i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].to;
            int weight = adj[here][i].weight;
            long long nextDist = cost + static_cast<long long>(weight);
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(pair<long long, int>(nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Edge{ b, c });
        adj[b].push_back(Edge{ a, c });
    }

    cin >> v1 >> v2;

    vector<long long> dist_from_1 = dijkstra(1);
    vector<long long> dist_from_v1 = dijkstra(v1);
    vector<long long> dist_from_v2 = dijkstra(v2);

    long long path1 = -1;
    long long path2 = -1;

    if (dist_from_1[v1] != INF && dist_from_v1[v2] != INF && dist_from_v2[N] != INF) {
        path1 = dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N];
    }
    if (dist_from_1[v2] != INF && dist_from_v2[v1] != INF && dist_from_v1[N] != INF) {
        path2 = dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N];
    }

    if (path1 == -1 && path2 == -1) {
        cout << -1 << '\n';
    }
    else if (path1 == -1) {
        cout << path2 << '\n';
    }
    else if (path2 == -1) {
        cout << path1 << '\n';
    }
    else {
        cout << (path1 < path2 ? path1 : path2) << '\n';
    }

    return 0;
}
