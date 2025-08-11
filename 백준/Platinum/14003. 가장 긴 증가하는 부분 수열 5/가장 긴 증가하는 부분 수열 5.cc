#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void solve_lis() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> c; 
    std::vector<int> p(n); 

    for (int i = 0; i < n; ++i) {
        if (c.empty() || a[i] > c.back()) {
            c.push_back(a[i]);
            p[i] = c.size() - 1;
        } else {
            auto it = std::lower_bound(c.begin(), c.end(), a[i]);
            *it = a[i];
            p[i] = std::distance(c.begin(), it);
        }
    }

    int lis_length = c.size();
    std::cout << lis_length << "\n";

    std::vector<int> lis_result;
    lis_result.reserve(lis_length);
    int current_len = lis_length - 1;

    for (int i = n - 1; i >= 0; --i) {
        if (p[i] == current_len) {
            lis_result.push_back(a[i]);
            current_len--;
        }
        if (current_len < 0) {
            break;
        }
    }

    std::reverse(lis_result.begin(), lis_result.end());

    for (int i = 0; i < lis_result.size(); ++i) {
        std::cout << lis_result[i] << (i == lis_result.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    solve_lis();

    return 0;
}
