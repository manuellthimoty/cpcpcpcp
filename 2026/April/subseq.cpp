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
struct FenwickTree {
    vector<ll> bit;
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }


    ll getatidx(ll i){
        return sum(i,i);
    }
    
};

void solve(){
    ll n,k; cin >> n >> k;
    vector<FenwickTree> BIT(k+2, FenwickTree(n+2));
    vector<int> a(n);
    input(a,0,n);
    for(ll p = 0 ; p < n ; p++){
        ll val = a[p];
        for(ll len = k+1 ; len >=2 ; len--){
            ll count = BIT[len-1].sum(val-1);
            BIT[len].add(val,count);
        }
        BIT[1].add(val,1);
    }
    ll ans = BIT[k+1].sum(n);
    cout << ans << endl;
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
