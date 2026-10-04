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

ll MOD = 1e9+7;
ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

ll mod_inverse(ll k, ll mod){
    ll ans = modpow(k,mod-2,mod);
    return ans%mod;
}


void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    int cntmin1 = 0;
    for(int i = 0; i < n ; i++) {cin >> a[i]; if(a[i] == -1) cntmin1 ++;}
    vector<pair<int,int>> berurutan;
    for(int i = 0 ; i < n-1 ; i++){
        if(a[i+1] - a[i] == 1){
            berurutan.push_back({a[i],a[i+1]});
        }
    }
    map<ll,ll> f;
    for(auto x : a) f[x]++;
    // jika k genap maka ai1 = a12 di setiap subset
    ll ans = 1;
    for(auto val : f){
        int cur = val.first;
        int cur_freq = val.second;
        ans *= modpow(2,cur_freq-1, MOD);
        ans %= MOD;
    }
    ll S = ans;
    if(cntmin1 == 0){
        cout << ans << endl;
        return;
    }

    for(auto x : berurutan){
        ans += S;
        ans %= MOD;
    }
    cout << ans << endl;
    // jika k ganjil, maka ai1
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
