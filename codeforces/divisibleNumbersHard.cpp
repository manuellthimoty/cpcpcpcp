#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a == 1 || b ==1) return 1;
    if(b == 0) return a;
    return gcd(b,a % b);
}

void solve() {
    ll a,b,c,d ; cin >> a >> b >> c >> d;
    vector<ll> gcdArr;
    bool ans = false;
    ll k = a * b;
    
    // WLOG kita ambil dari a, maka banyaknya nilai yg mungkin dari gcd(a*b,a) hanyalah  
    for(ll i = a + 1 ; i <= c;i++){
        ll gcdVal = gcd(i,a*b);
        ll fact = a*b /gcdVal;
        // cek apakah ada kelipatan fact di interval b,d
        ll n = (d/fact) - (b/fact);
        // cout << fact << " " << n << endl;
        if(n <= 0) continue;
        else{
            ll sisa = b % fact;
            ll jalankeKanan = fact - sisa;
            ll j = b + jalankeKanan;
            if(j <= b) continue;
            cout << i << " " << j <<endl;
            return ;
        }
    }
    cout << -1 << " " << -1 << endl;
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