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
const int mxA=1e6;
vector<bool> is_prime(mxA+1, true);
vector<int> primes;
int spf[mxA + 1];
// vector<vector<int>> primefact(mxA+1);

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

void solve(){
    int n ; cin >> n;
    vint a(n);
    for(int i  = 0 ; i < n ; i++){
        cin >> a[i];
    }
    ll MOD = 998244353;
    vector<vector<ll>> f(2e5+1,vector<ll>(20,0));
    // f[i][j] = total frequensi dari bentuk i ^j dimana i prima
    // cout << "HA";
    for(auto x : a){
        int cur = x;
        while(cur > 1){
            int cur_prime = spf[cur];
            int cnt = 0;
            while(cur % cur_prime == 0){
                cur = cur/cur_prime;
                cnt++;
            }
            f[cur_prime][cnt]++;
        }
    }
    vector<vector<ll>> suff(2e5+1,vector<ll>(20,0));
    // suff[i][j] = total dari f[i][j+1] + f[i][j+2] + .. + f[i][19]
    for(int i = 1 ; i < 2e5+1 ; i++){
        suff[i][19] = f[i][19];
        for(int j = 18; j >= 0 ; j--){
            suff[i][j] = suff[i][j+1] + f[i][j];
        }
    }
    ll ans = 1;
    for(int i = 1 ; i < 2e5 + 1 ; i++){
        if(spf[i] != i) continue;
        // int curr = i;
        for(int j = 1 ; j < 20 ; j++){
            // pasangan yang menghasilkan gcd = curr ^j -> (f[curr][j],2) + f[curr][j] + suff[cur][j+1]
            ll s_next = (j + 1 < 20) ? suff[i][j + 1] : 0;
            ll cnt_pairs = (f[i][j] * (f[i][j] - 1)) / 2 + f[i][j] * s_next;
            ans = ans * modpow(i,j * cnt_pairs,MOD);
            ans %= MOD;
        }
    }
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
