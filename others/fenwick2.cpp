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
    ll n ; cin >> n;
    vector<ll> a(n);
    input(a,0,n);
    vector<ll> d(n,0);
    d[0] = a[0];
    for(int i = 1; i < n ; i++){
        d[i] = a[i] - a[i-1];
    }
    // d[i] = a[i] - a[i-1]
    // d[1] = a[1] - a[0]
    // d[2] = a[2] - a[1]
    // d[3] = a[3] - a[2]
    // d[0] = a[0]
    FenwickTree fen = FenwickTree(d);
    ll q;cin >> q;
    while(q--){
        ll type ; cin >> type;
        if(type == 1){
            ll l,r,v ; cin >> l >> r >> v;
            fen.add(l-1,v);
            fen.add(r,-v);

        }
        else{
            ll x; cin >> x;
            cout << fen.sum(x-1) << endl;
        }
    }
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
