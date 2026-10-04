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

    
};

int main() {
    ll n,m ; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0 ;i < n ; i++) cin >> a[i];

    FenwickTree fen = FenwickTree(a);
    while(m--){
        int type,first,second; cin >> type >> first >> second;
        if(type == 1){
            first--;
            ll newVal = a[first] ^ second;
            ll diff = newVal - a[first];
            fen.add(first,diff);
            a[first] = newVal;
        }
        else{
            first--;
            second--;
            cout << fen.sum(first,second) << '\n';
        }
    }

    

    return 0;
}
