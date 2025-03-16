#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        map<string, int> clothes;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        int result = 1;
        for (auto& [type, count] : clothes) {
            result *= (count + 1);
        }
        result -= 1;

        cout << result << '\n';
    }

    return 0;
}