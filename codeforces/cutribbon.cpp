#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,a,b,c; cin >> n >> a >> b >> c;
    ll maks = 0;
    for(ll i = 0 ; i <= n ; i ++){
        for (ll j = 0 ; j <= n ; j++){
            ll indeks3 = 0;
            ll cur = a*i + b *j;
            ll remainder = n - cur;
            if(remainder % c == 0 && remainder >=0){
                indeks3 = remainder/c;
                maks = max(maks, i+j+indeks3);
            }
        }
    }
    cout << maks << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}