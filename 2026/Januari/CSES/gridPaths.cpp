#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<string> s;
    s.resize(n);
    ll MOD = 1e9 + 7;
    for(ll i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    for(ll i = 0 ; i < n ; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(ll i = 0 ; i < n ; i++){
        if(s[0][i] != '*'){
            dp[0][i] = 1;
        }
        else{
            break;
        }
    }
    for(ll i = 0 ; i < n ; i++){
        if(s[i][0] != '*'){
            dp[i][0] = 1;
        }
        else{
            break;
        }
    }
    
    for(ll i = 1; i < n ; i++){
        for(ll j = 1; j < n ; j++){
            if(s[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = ((dp[i-1][j] % MOD) + (dp[i][j-1] % MOD)) % MOD;
        }
    }
    cout << dp[n-1][n-1] << endl;

    return 0;
}