#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n ; cin >> n ; 
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    vector<ll> dp_left(n), dp_right(n);
    dp_left[0] = 1;
    ll ans = 1;
    for(ll i = 1 ; i < n ; i++){
        if(a[i] > a[i-1]){
            dp_left[i] = 1 + dp_left[i-1];
        }
        else{
            dp_left[i] = 1;
        }
        ans = max(ans,dp_left[i]);
    }
    dp_right[n-1] = 1;
    for(ll i = n-2 ; i >= 0 ; i--){
        if(a[i] < a[i+1]){
            dp_right[i] = 1 + dp_right[i+1];
        }
        else{
            dp_right[i] = 1;
        }
        ans = max(ans,dp_right[i]);
    }
    for(ll i = 1 ; i < n - 1; i++){
        if(a[i-1] < a[i+1]){
            ans = max(ans, dp_left[i-1] + dp_right[i+1]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}