#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> solutions(N);
    for (int i = 0; i < N; ++i) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    long long min_abs_sum = LLONG_MAX;
    vector<long long> result_solutions(3);

    for (int i = 0; i < N - 2; ++i) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            long long current_sum = solutions[i] + solutions[left] + solutions[right];

            if (abs(current_sum) < min_abs_sum) {
                min_abs_sum = abs(current_sum);
                result_solutions[0] = solutions[i];
                result_solutions[1] = solutions[left];
                result_solutions[2] = solutions[right];
            }

            if (current_sum < 0) {
                left++;
            } else if (current_sum > 0) {
                right--;
            } else {
                break;
            }
        }
    }

    sort(result_solutions.begin(), result_solutions.end());
    cout << result_solutions[0] << " " << result_solutions[1] << " " << result_solutions[2] << "\n";

    return 0;
}