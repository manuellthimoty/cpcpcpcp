#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;
ll n;

vector<ll> fact(102);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2 ; i < 102 ; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(257,vector<ll>(n+1,0)));
    dp[0][0][0]=1;
    dp[0][a[0]][1] = 1;
    // cout << dp[0][0][0];
    for(ll i = 0 ; i < n-1 ; i++){
        for(ll x = 0 ; x < 256 ; x++){
            for(ll t = 0 ; t < n ; t++){
                dp[i+1][x][t]  += dp[i][x][t] % mod;
                dp[i+1][x][t] %= mod;
                dp[i+1][x ^ a[i+1]][t+1] += dp[i][x][t] % mod;
                dp[i+1][x ^ a[i+1]][t+1]  %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 0 ; i <= n ; i++){
        ans += (dp[n-1][k][i] * fact[i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
