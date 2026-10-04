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
    ll n ; cin >> n;
    vector<ll> a(n+1);
    input(a,1,n+1);
    vector<ll> pref(n+1);
    pref[0] = 0;
    pref[1] = a[1];
    for(ll i = 2; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
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
