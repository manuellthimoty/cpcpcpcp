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


ll power(ll a, ll b, ll mod){
    a = a % mod;
    if(b == 0) return 1;
    ll mid = power(a,b/2,mod);
    if(b % 2 == 0) return (mid * mid) % mod;
    else return a * ((mid * mid)% mod) % mod;
}
int M = 1e9 + 7;
void solve(){
    int n,m ; cin >> n >> m;
    vector<ll> fact(n+1);
    vector<ll> pow2(n+1);
    pow2[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        pow2[i] = ((pow2[i-1] % M) * 2) % M;
    }
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= n ; i++){
        fact[i] = ((fact[i-1] % M) * i)%M;
    }
    vector<ll> invfact(n+1);
    // a^-1 mod M = a ^ (m-2) mod M; (fermat)
    // (k!) ^ -1 mod M = (k!) ^ (m-2) mod M//
    for(int i = 0 ; i <= n ; i++){
        invfact[i] = power(fact[i],M-2,M);
    }
    vector<ll> combN(n+1);
    for(int i = 0 ; i <= n ; i++){
        combN[i] = (((fact[n] * invfact[i]) % M) * invfact[n-i]) % M;
    }
    ll sum = 0;
    for(int k = 1; k <= n ; k++){
        ll first = power(pow2[n-k]-1,m,M) %M;
        ll second = combN[k] % M;
        ll cur = (first * second) % M;
        if(k % 2 == 1){
            sum = (sum + cur) % M;
        }
        else sum = ((sum - cur) % M + M) % M;
        
    }
    ll final = power(pow2[n]-1,m,M);
    final -= sum;
    final = ((final % M) + M) %M;
    cout << final << endl;

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
