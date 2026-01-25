#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> h(n+1), s(n+1);
    
    for(ll i = 1; i <= n; i++) cin >> h[i];
    for(ll i = 1; i <= n; i++) cin >> s[i];
    
    vector<ll> dp(x+1, 0);
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    
    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}