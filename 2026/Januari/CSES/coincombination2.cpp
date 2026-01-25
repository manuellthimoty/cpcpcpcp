#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll MOD = 1e9 + 7;
    ll n,x ; cin >> n >> x ;
    vector<ll> c(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> c[i];

    vector<ll> dp(1e6+1,0);
    dp[0] = 1;
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 0 ; j <= x ; j++){
            if(j - c[i] >=0){
                dp[j] = (dp[j] + dp[j-c[i]]) % MOD;
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