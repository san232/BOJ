#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int studentCount, compareCount;
    cin >> studentCount >> compareCount;

    vector<vector<int>> adjacency(studentCount + 1);
    vector<int> indegree(studentCount + 1, 0);

    for (int i = 0; i < compareCount; ++i) {
        int from, to;
        cin >> from >> to;
        adjacency[from].push_back(to);
        ++indegree[to];
    }

    queue<int> ready;
    for (int i = 1; i <= studentCount; ++i) {
        if (indegree[i] == 0) {
            ready.push(i);
        }
    }

    vector<int> order;
    while (!ready.empty()) {
        int current = ready.front();
        ready.pop();
        order.push_back(current);

        for (int next : adjacency[current]) {
            --indegree[next];
            if (indegree[next] == 0) {
                ready.push(next);
            }
        }
    }

    for (int i = 0; i < order.size(); ++i) {
        cout << order[i];
        if (i < order.size() - 1) cout << " ";
    }
    cout << '\n';

    return 0;
}
