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
// let a b c freq of 1 2 3,
// then in the first part , a >= b+c
// second part, a + b >= c
// third part bebas
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
void solve(){
    ll n ; cin >> n;
    vector<ll> arr(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> arr[i];
    vector<ll> a(n+1),b(n+1),c(n+1);
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    for(ll i = 1 ; i <= n ; i++){
        a[i] = a[i-1] + (arr[i] == 1 ? 1 : 0);
        b[i] = b[i-1] + (arr[i] == 2 ? 1 : 0);
        c[i] = c[i-1] + (arr[i] == 3 ? 1 : 0);
    }
    vector<ll> p(n+1);
    p[0] = 0;
    for(ll i = 1; i <= n ; i++){
        p[i] = a[i] + b[i] - c[i];
    }ll offset = n;
    FenwickTree tree(2 * n + 5);
    // i < j < n
    for(ll j = 2; j <= n - 1; j++){
        tree.add(p[j] + offset, 1);
    }
    bool possible = false;
    for(ll i = 1; i <= n - 2; i++){
        if (a[i] >= b[i] + c[i]) {
            ll target = p[i] + offset;
            if (tree.sum(target, 2 * n + 3) > 0) {
                possible = true;
                break;
            }
        }
        tree.add(p[i+1] + offset, -1);
    }
    
    if(possible) YES
    else NO
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
