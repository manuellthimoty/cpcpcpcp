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

void solve(){
    ll k; cin >> k;
    ll w1,v1,s1 ; cin >> w1 >> v1 >> s1;
    ll w2,v2,s2 ; cin >> w2 >> v2 >> s2;
    ll ans = 0;
    if(s1 + w1 <= k){
        ll sisa1 = k - s1;
        ll banyakPaket = sisa1/w1;
        ll ans1 = banyakPaket * v1;
        ans = max(ans1,ans);
    }
    if(s2 + w2 <= k){
        ll sisa2 = k- s2;
        ll banyakPaket = sisa2/w2;
        ll ans2 = banyakPaket * v2;
        ans = max(ans2,ans);
    }
    if(s1 + w1 + s2 + w2 <= k){
        ll W_rem = k - s1 - s2 - w1 - w2;
        ll best = 0;
        for (ll y = 0; y < w1 && y * w2 <= W_rem; y++) {
            ll x = (W_rem - y * w2) / w1;
            ll cur = x * v1 + y * v2;
            best = max(cur,best);
        }
    
        for (ll x = 0; x < w2 && x * w1 <= W_rem; x++) {
            ll y = (W_rem - x * w1) / w2;
            ll cur = x * v1 + y * v2;
            best = max(cur,best);
        }
        ans = max(ans,best + v1 + v2);
    }
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
