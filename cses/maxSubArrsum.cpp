#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n ;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i ++) cin >> a[i];
    ll ans = a[0];
    vector<ll> dp(n);
    dp[0] = a[0];
    for(ll i = 1 ; i < n ; i++){
        dp[i] = max(a[i],a[i] + dp[i-1]);
        ans = max(dp[i],ans);
    }
    cout << ans << endl;

    return 0;
}