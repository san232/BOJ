#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<int>>;

long long N;
long long B;

matrix multiply(const matrix& a, const matrix& b) {
    matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

matrix power(matrix a, long long b) {
    matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        result[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        b /= 2;
    }
    return result;
}

void print_matrix(const matrix& m) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    matrix a(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    matrix result = power(a, B);
    print_matrix(result);

    return 0;
}
