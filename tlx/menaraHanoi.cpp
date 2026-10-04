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

struct FenwickTree {
    vector<ll> bit;
    ll n;
    const ll MIN_INF = -(ll)1e9;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i,a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll getMax(int r){
        ll mx = 0;
        for(; r < n ; r = r | (r+1)){
            mx = max(mx, bit[r]);
        }
        return mx;
    }

    void update(int idx, int val){
        for(; idx >= 0 ; idx = (idx & (idx+1))-1){
            bit[idx] = max(bit[idx],(ll)val);
        }
    }

    
};

int main() {
    GK();
    int n ; cin >> n;
    vector<ll> d(n);
    for(int i = 0 ; i < n ; i++) cin >> d[i];
    ll mx = *max_element(d.begin(),d.end());
    FenwickTree fen(mx+2);

    vector<ll> dp(n,0);
    // dp[0] = 1;
    // fen.update(d[0],1);

    for(int i = 0; i < n ; i++){
        ll cur = d[i];
        ll mxDp = fen.getMax(cur+1);
        dp[i] = mxDp + 1;
        fen.update(d[i],dp[i]);
    }
    ll ans = 1;
    for(int i = 0 ; i < n ; i++) ans = max(ans,dp[i]);
    cout << ans << endl;

    return 0;
}
