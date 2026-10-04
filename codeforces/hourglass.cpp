#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll s,k,m; cin >> s >> k >> m;
    ll ans = 0;
    if(s <= k){
        ans = max(0LL,s-m+(m/k)*k);
    }
    else{
        ll p = m/k;
        if(p % 2 == 1){
            ans = max(0LL,k-m+p*k);
        }
        else{
            ans = max(0LL,s-m+p*k);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}