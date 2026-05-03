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

void precompute(){
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1 ; i <= 1e6 ; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[1e6] = modpow(fact[1e6],mod-2,mod);
    for(int i = 1e6-1; i>= 0; i--){
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }
}

ll comb(ll n, ll k){
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invfact[k]) % mod) * invfact[n-k]) % mod;
}

void solve(){
    ll n, k; 
    cin >> n >> k;
    
    ll ones = 0;
    for(int i = 0 ; i < n ; i++){
        int x; 
        cin >> x;
        if(x == 1) ones++;
    }
    
    ll ans = 0;
    for(ll i = (k+1)/2 ; i <= min(ones, k) ; i++){
        ll first = comb(ones, i);
        ll second = comb(n - ones, k - i);
        
        ans = (ans + (first * second) % mod) % mod;
    }
    
    cout << ans << endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
