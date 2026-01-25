
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<ll> h(n+1,0), k(n+1,0), d(n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        cin >> h[i] >> k[i] >> d[i];
    }
    vector<ll> dp(m+1, 0);
    
    for(ll i = 1 ; i <= n ; i++){
        if(d[i] == 1) {
            for(ll j = m; j >= h[i]; j--){
                dp[j] = max(dp[j], dp[j-h[i]] + k[i]);
            }
        } else {
            for(ll j = h[i]; j <= m; j++){
                dp[j] = max(dp[j], dp[j-h[i]] + k[i]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}