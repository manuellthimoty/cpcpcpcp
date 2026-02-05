#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n,q ; cin >> n >> q;
    vector<ll> a(n+1,0),b(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    for(ll i = 1 ; i<= n ; i++) cin >> b[i];
    a[n] = max(a[n],b[n]);

    for(ll i = n-1 ; i >= 1 ;i--){
        ll greater = max(a[i+1],b[i]);
        a[i] = max(a[i],greater);
    }

    vector<ll> prefSum(n+1,0);
    prefSum[1] = a[1];
    for(ll i = 2 ; i <= n ; i++){
        prefSum[i] = prefSum[i-1] + a[i];
    }

    while(q--){
        ll l,r; cin >> l >> r;
        cout << prefSum[r] - prefSum[l-1] << " ";
    }
    cout << endl;
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