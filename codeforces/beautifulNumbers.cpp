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

vector<ll> fact(1e6+1);
vector<ll> invfact(1e6+1);
ll mod = 1e9+7;

bool isBeautiful(ll n, ll a, ll b){
    while(n > 0){
        if(n % 10 != a && n % 10 != b) return false;
        n = n/10;
    }
    return true;
}

ll modpow(ll a, ll b){
    ll res = 1;

    while(b){
        if(b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}


void precompute(){
    fact[0] = 1;
    for(ll i = 1; i <= 1e6 ; i++){
        fact[i] = ((fact[i-1] % mod) * i) % mod;
    }
    invfact[1e6] = modpow(fact[1e6],mod-2);
    for(ll i = 1e6-1 ; i>=0 ;i--){
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}



void solve(){
    ll ans = 0;
    ll a,b,n ; cin >> a >> b >> n;
    for(ll p = 0 ; p <= n ; p++){
        ll q = n - p; // p + q = n
        if(!isBeautiful(a*p + b* q,a,b)) continue;
        ll cnt = (((fact[n] * invfact[p]) % mod) * invfact[q] % mod) % mod;
        ans = (ans + cnt) % mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    precompute();

    while (t--) {
        solve();
    }

    return 0;
}
