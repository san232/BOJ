#include <iostream>
using namespace std;

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int num = mod_pow(a, b, 10);
        if (num == 0)
            cout << 10 << endl;
        else
            cout << num << endl;
    }
    return 0;
}
