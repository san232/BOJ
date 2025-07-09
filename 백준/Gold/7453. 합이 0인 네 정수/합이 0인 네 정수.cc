#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB, CD;
    AB.reserve(n * n);
    CD.reserve(n * n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long result = 0;
    int left = 0, right = CD.size() - 1;

    while (left < AB.size() && right >= 0) {
        int sum = AB[left] + CD[right];
        if (sum == 0) {
            long long ab_cnt = 1, cd_cnt = 1;
            while (left + 1 < AB.size() && AB[left] == AB[left + 1]) {
                ++ab_cnt; ++left;
            }
            while (right - 1 >= 0 && CD[right] == CD[right - 1]) {
                ++cd_cnt; --right;
            }
            result += ab_cnt * cd_cnt;
            ++left; --right;
        } else if (sum < 0) {
            ++left;
        } else {
            --right;
        }
    }

    cout << result << '\n';
}
