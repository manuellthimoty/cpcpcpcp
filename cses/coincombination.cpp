#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll MOD = 1e9 + 7;
    ll n,x ; cin >> n >> x ;
    vector<ll> c(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> c[i];

    vector<ll> dp(x+1,0);
    dp[0] = 1;
    ll ans = 0;
    for(ll i = 1 ; i <= x ; i++){
        for(ll j = 1 ; j <= n ; j++){
            if(i - c[j] >=0){
                dp[i] = (dp[i] + dp[i-c[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}