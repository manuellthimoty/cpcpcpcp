#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)
ll mod = 1e9+7;

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> suff(n);
    suff[n-1] = a[n-1] % mod;
    for(int i = n-2 ; i>=0 ;i--){
        suff[i] = (suff[i+1] + a[i] % mod) % mod;
    }
    ll pembil = 0;
    for(int i = 0 ; i < n-1 ; i++){
        pembil = (pembil + (a[i] % mod * suff[i+1]) % mod) % mod;
    }
    ll invn = modpow(n,mod-2,mod);
    ll invn1 = modpow(n-1,mod-2,mod);
    ll ans = ((2 * pembil) % mod * ((invn * invn1) % mod)) % mod;
    if(ans <0) ans += mod;
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
