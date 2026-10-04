#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n ; cin >> n ;
    vector<ll> a(n),b(n),c(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(ll i = 0 ; i < n ; i++){
        cin >> b[i];
    }for(ll i = 0 ; i < n ; i++){
        cin >> c[i];
    }
    ll jumlah_ab = 0;
    ll jumlah_bc = 0;
    // hitung hubungan a b dengan asumsi b = 0;
    for(ll i = 0 ; i < n ; i++){
        if(a[i] >= b[0]) continue;
        bool ketemu = true;
        for(ll j = 0 ; j < n ; j++){
            if(a[(i+j) % n] >= b[j]){
                ketemu = false;
                break;
            }
        }
        if(ketemu){
            jumlah_ab++;
        }
    }
    // hitung hubungan b c dengan asumsi b = 0
    for(ll i = 0 ; i < n ; i++){
        if(b[0] >= c[i]) continue;
        bool ketemu2 = true;
        for(ll j = 0 ; j < n ; j++){
            if(c[(i+j) % n] <= b[j]){
                ketemu2 = false;
                break;
            }
        }
        if(ketemu2){
            jumlah_bc++;
        }
    }
    ll ans = jumlah_ab * jumlah_bc * n;
    // cout << jumlah_ab << " " <<jumlah_bc << endl;
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