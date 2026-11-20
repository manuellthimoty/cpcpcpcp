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
    ll n ; cin >> n;
    map<ll,ll> freq;
    ll mx = -1;
    vector<int> a(n);

    for(int i =0 ; i < n ; i++){
        ll x; cin >> x;
        a[i] = x;
        mx = max(mx,x);
        freq[x]++;
    }
    if(freq[mx] > 1){
        cout << 1 << endl;
        return;
    }
    sort(a.rbegin(),a.rend());
    vector<ll> all;

    for(int i =0; i < n ; i++){
        if(freq[a[i]] > 1) break;
        all.push_back(a[i]);
    }
    
    sort(all.rbegin(),all.rend());
    ll ans =1;
    ll MOD = 1e9+7;
    for(int i = 0 ; i < all.size() ; i++){
        ans += modpow(all[i]-1,i+1,MOD);
        ans %= MOD;
    }
    cout << ans << '\n';

}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
