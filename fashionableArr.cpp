#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n ; cin >> n ;
    vector<ll> a(n);
    for(ll i =0 ; i<n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll i = 0 ;
    ll j = n-1;
    ll ans = 1e3;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = i; j < n ; j++){
            if((a[i] + a[j]) % 2 ==0){
                ans = min(i + n- j - 1,ans);
            }
        }
    }
    cout << ans << endl;
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