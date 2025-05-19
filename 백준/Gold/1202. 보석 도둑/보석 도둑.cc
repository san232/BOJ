#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> jewels(N);
    for(int i = 0; i < N; ++i){
        cin >> jewels[i].first >> jewels[i].second;
    }

    vector<int> C(K);
    for(int i = 0; i < K; ++i){
        cin >> C[i];
    }

    sort(jewels.begin(), jewels.end(), [](auto &a, auto &b){
        return a.first < b.first;
    });
    sort(C.begin(), C.end());

    priority_queue<int> pq;
    ll ans = 0;
    int idx = 0;

    for(int i = 0; i < K; ++i){
        int cap = C[i];
        while(idx < N && jewels[idx].first <= cap){
            pq.push(jewels[idx].second);
            ++idx;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}
