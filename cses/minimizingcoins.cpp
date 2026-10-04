#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, x; cin >> n >> x;
    vector<ll> c(n);
    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }
    
    const ll INF = 1e9;
    vector<ll> dp(x+1, INF);
    dp[0] = 0;
    
    for(ll j = 1; j <= x; j++){
        for(ll i = 0; i < n; i++){
            if(j >= c[i]){
                dp[j] = min(dp[j],dp[j-c[i]] + 1);
            }
        }
    }
    #include <bits/stdc++.h>
    using namespace std;
    
    void solve() {
        
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
    if(dp[x] == INF){
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
    
    return 0;
}