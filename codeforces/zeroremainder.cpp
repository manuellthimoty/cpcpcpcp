#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    map<ll,ll> m;
    bool alldiv = true;
    for(ll i = 0 ; i < n ; i++){
        ll nums ; cin >> nums;
        ll rem = nums % k;
        if ( rem == 0) continue;
        alldiv = false;
        m[k-rem] ++;
    }
    if(alldiv){
        cout << 0 << endl;
        return;
    }
    ll mx = 0;
    ll mxar = 0;
    for(auto &p : m){
        if(p.second > mx){
            mx = p.second;
            mxar = p.first;
        }
        else if(p.second == mx){
            mxar = max(mxar,p.first);
        }
    }


    // 1 2 2
    ll ans = mxar + (mx-1) * k + 1;
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
