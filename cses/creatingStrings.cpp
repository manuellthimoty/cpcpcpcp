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

void solve(){
    string s; cin >> s;
    map<char,ll> freq;
    for(auto t : s){
        freq[t] ++;
    }
    int n = s.size();
    ll atas = fact[n];
    for(auto t : freq){
        atas = (atas * invfact[t.second]) % mod;
    }
    cout << atas << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    precompute();
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
