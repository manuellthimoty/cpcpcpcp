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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)
vector<ll> fact(2e5+1);
vector<ll> invFact(2e5+1);
ll MOD = 998244353; 

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}


void init(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= 2e5 ; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
    int n = 2e5;
    invFact[n] = power(fact[n], MOD - 2);    
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll comb(ll n, ll k){
    ll ans = (fact[n] * (invFact[k] % MOD)) % MOD * (invFact[n-k] % MOD);
    ans %= MOD;
    return ans;
}


int main() {
    GK();
    init();
    // int t;
    // cin >> t;
    int n,k ;cin >> n >> k;
    vector<ll> a(n+1);
    for(int i = 1; i <= n ; i++) {
        cin >> a[i];
        a[i] %= MOD;
    }
    vector<ll> suff(n+1);
    suff[n] = a[n];
    for(int i = n-1 ; i >=1 ; i--){
        suff[i] = suff[i+1] + a[i];
        suff[i] %= MOD;
    }

    ll first = 0;
    for(int i = 1; i <= n ; i++){
        first += a[i] * a[i];
        first %= MOD;
    }
    if(k == 1){
        cout << first << '\n';
        return 0;
    }
    first *= comb(n-1,k-1);
    ll sumaiaj = 0;
    for(int i = 1; i <= n-1 ; i++){
        sumaiaj += (ll) a[i] * suff[i+1];
        sumaiaj %= MOD;
    }    
    ll second = 2 * sumaiaj;
    second %= MOD;
    second *= comb(n-2,k-2);
    second %= MOD;
    
    ll ans = first + second;
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}
