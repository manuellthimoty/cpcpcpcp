#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M = 1e9 + 7;
    vector<vector<ll>> dp(2001, vector<ll>(2001, 0));
    
    vector<vector<ll>> factors(2001);
    for(ll i = 1; i <= 2000; i++){
        for(ll j = 1; j * j <= i; j++){
            if(i % j == 0){
                factors[i].push_back(j);
                if(i/j != j){
                    factors[i].push_back(i/j);
                }
            }
        }
    }
    
    for(ll i = 1; i <= 2000; i++){
        dp[1][i] = 1;
    }

    ll n, k;
    cin >> n >> k;
    
    for(ll i = 2; i <= k; i++){
        for(ll j = 1; j <= n; j++){
            for(auto x : factors[j]){
                dp[i][j] = (dp[i][j] + dp[i-1][x]) % M;
            }
        }
    }
    
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans = (ans + dp[k][i]) % M;
    }
    cout << ans << endl;

    return 0;
}