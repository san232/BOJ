#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), sortedX;
    map<int, int> compressed;

    for (int i = 0; i < N; i++) {
        cin >> X[i];
        sortedX.push_back(X[i]);
    }

    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());

    for (int i = 0; i < sortedX.size(); i++) {
        compressed[sortedX[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << compressed[X[i]] << " ";
    }

    return 0;
}
