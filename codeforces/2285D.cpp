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

vector<ll> fact(2e5+5,1);
const ll MOD = 1e9+7;
void init(){
    for(int i =2 ; i <= 2e5+1; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


ll comb(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    ll denominator = fact[r] * fact[n-r] % MOD;
    return fact[n] * modpow(denominator, MOD-2) % MOD;
}

ll binsearch(const vector<ll>& v, ll val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

ll binsearch2(const vector<ll>& v, ll val1, ll val2) {
    if (val1 > val2) return 0;

    return upper_bound(v.begin(), v.end(), val2)
         - lower_bound(v.begin(), v.end(), val1);
}

void solve(){
    ll n,m; cin >> n >> m;
    ll q; cin >> q;

    vector<ll> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<ll> pref(n+1,0);
    for(ll i = 1 ; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    map<ll,vector<ll>> mp;
    ll cnt = 0;
    for(ll i = 1; i <= n ; i++){
        ll sum = pref[i] + pref[n-i];
        mp[sum].push_back(i);
        if(sum == pref[n]) cnt++;        
    }
    for(auto& el : mp){
        sort(el.second.begin(),el.second.end());
    }
    vector<ll>& patokan = mp[pref[n]];
    ll curans = comb(cnt-1,m-1);
    while(q--){
        ll idx,v; cin >> idx >> v;
        if(v == 0){
            cout << curans << '\n';
            continue;
        }
        if (idx <= n / 2) {
            ll currleft = binsearch(patokan, idx);
            ll currr = 2 * currleft + 1;

            ll newsum = pref[n] - v;
            auto it = mp.find(newsum);

            if (it != mp.end()) {
                ll currright = binsearch2(it->second, idx, n / 2);
                currr += 2 * currright;
            }
            if (n % 2 == 0 && pref[n / 2] * 2 == newsum) {
                currr--;
            }
            cout << comb(currr - 1, m - 1) << '\n';
        } else {
            ll curright = binsearch2(patokan, idx, n - 1);
            ll currr = 2 * curright + 1;

            ll newsum = pref[n] + v;
            auto it = mp.find(newsum);

            if (it != mp.end()) {
                ll currright = binsearch2( it->second, n - idx + 1, n / 2);
                currr += 2 * currright;
            }

            if (n % 2 == 0 && pref[n / 2] * 2 == newsum) {
                currr--;
            }

            cout << comb(currr - 1, m - 1) << '\n';
        }


    }



}
int main() {
    GK();
    init();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
