#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll get_k(ll x){
    ll k = 0;
    while(x>=3){
        x/=3;
        k++;
    }
    return k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // precompute
    ll maxN = 2e5;
    vector<int> logList(maxN+1);
    logList[0] = 0;
    for(ll i = 1 ; i <= maxN ; i++){
        logList[i] = get_k(i);
    }
    while (t--) {
        ll l,r; cin >> l >> r;
        ll ans = 0;
        for(ll i = l ; i <= r ; i++){
            ans += logList[i];
        }
        ans += r - l + 2 + logList[l];
        cout << ans << endl;
    }

    return 0;
}