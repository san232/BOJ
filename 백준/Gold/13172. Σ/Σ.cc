#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const long long MOD = 1000000007LL;

    auto mod_pow = [&](long long base, long long exp) -> long long {
        base %= MOD;
        long long result = 1LL;
        while (exp > 0) {
            if (exp & 1LL) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1LL;
        }
        return result;
    };

    auto mod_inv = [&](long long x) -> long long {
        // Fermat: x^(MOD-2) mod MOD
        return mod_pow(x, MOD - 2);
    };

    int M;
    if (!(std::cin >> M)) return 0;

    long long answer = 0LL;
    for (int i = 0; i < M; ++i) {
        long long N, S;
        std::cin >> N >> S;
        long long term = ( (S % MOD) * mod_inv(N) ) % MOD;
        answer += term;
        if (answer >= MOD) answer -= MOD;
    }

    std::cout << answer << '\n';
    return 0;
}
