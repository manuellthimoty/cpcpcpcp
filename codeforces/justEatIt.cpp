#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n ; cin >> n ; 
    vector<ll> a(n);
    for (ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    // hitung maks sub sequence
    ll maks1 = a[0];
    ll maxending = a[0];
    for(ll i = 1 ; i < n-1 ; i++){
        maxending = max(a[i],a[i]+maxending);
        maks1 = max(maks1,maxending);
    }

    ll maks2 = a[1];
    maxending = a[1];
    for(ll i = 2 ; i < n ; i++){
        maxending = max(a[i],a[i]+maxending);
        maks2 = max(maks2,maxending);
    }

    ll maks3 = a[1];
    maxending = a[1];
    for(ll i = 2 ; i < n-1 ; i++){
        maxending = max(a[i],a[i]+maxending);
        maks3 = max(maks3,maxending);
    }
    ll maks = max(maks1,max(maks2,maks3));

    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) sum += a[i];
    if(sum > maks) cout << "YES" << endl;
    else cout << "NO" << endl;

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