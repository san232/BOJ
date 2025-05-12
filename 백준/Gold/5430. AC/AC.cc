#include<string>
#include<iostream>
#include<deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string p;
        cin >> p;
        int n;
        cin >> n;

        string arrs;
        cin >> arrs;

        deque<int> dq;
        if (n > 0) {
            int num = 0;
            for (int i = 1; i + 1 < (int)arrs.size(); i++) {
                char c = arrs[i];
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                }
                else if (c == ',') {
                    dq.push_back(num);
                    num = 0;
                }
            }
            dq.push_back(num);
        }

        bool rev = false;
        bool error = false;
        for (char op : p) {
            if (op == 'R') {
                rev = !rev;
            }
            else { // 'D'
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (!rev) dq.pop_front();
                else     dq.pop_back();
            }
        }

        if (error)
        {
            cout << "error\n";
        }
        else
        {
            cout << '[';
            if (!dq.empty())
            {
                if (!rev)
                {
                    auto it = dq.begin();
                    cout << *it++;
                    for (; it != dq.end(); ++it)
                        cout << ',' << *it;
                }
                else
                {
                    auto it = dq.rbegin();
                    cout << *it++;
                    for (; it != dq.rend(); ++it)
                        cout << ',' << *it;
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
