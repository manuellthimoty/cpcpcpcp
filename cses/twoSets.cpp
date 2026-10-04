#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    ll total = n * (n + 1) / 2;
    
    if(total % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    
    ll target = total / 2;
    vector<vector<ll>> dp(n+1, vector<ll>(target+1, 0));
    dp[0][0] = 1;
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    
    ll inv2 = power(2, MOD - 2, MOD);
    ll ans = (dp[n][target] * inv2) % MOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}