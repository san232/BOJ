#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr double kE = 2.718281828459045;
    int sum, product;
    cin >> sum >> product;

    if (sum == product) {
        cout << 1 << '\n';
        return 0;
    }

    if (pow(kE, sum / kE) < product) {
        cout << -1 << '\n';
        return 0;
    }

    long double previousProduct = -1.0L;
    for (int count = 2; ; ++count) {
        long double value = static_cast<long double>(sum) / count;
        long double currentProduct = pow(value, count);

        if (previousProduct > currentProduct) {
            cout << -1 << '\n';
            return 0;
        }
        if (currentProduct >= product) {
            cout << count << '\n';
            return 0;
        }
        previousProduct = currentProduct;
    }
}
