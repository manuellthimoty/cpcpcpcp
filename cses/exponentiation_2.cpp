#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll powerMod(ll a, ll b, ll m){
    if(b == 0) return 1;
    if(b == 1) return a % m ;
    ll half = powerMod(a,b/2,m);
    if(b % 2 == 0){
        return ((half % m) * (half % m)) % m;
    }
    else{
        return (((a % m) * (half % m) % m) * (half %m)) % m;
    }
}

void solve() {
    ll a,b,c ; cin >> a >> b >> c;
    ll MOD = 1e9 + 7;
    ll atas = powerMod(b,c,MOD-1);
    ll ans = powerMod(a,atas,MOD);
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